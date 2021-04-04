//
// Created by Marco Bassaletti on 07-03-21.
//
#include "../NSPass.h"
#include <boost/json.hpp>
#include "JsonParser.h"
#include "JsonWriter.h"
#include "serializer/StorageSerializer.h"
#include "../crypto/EncryptedFile.h"
#include "InvalidStorageException.h"
#include "JsonStorage.h"

namespace NSPass::Storage {
	using namespace std;
	using namespace NSPass;
	using namespace NSPass::Crypto;
	using namespace NSPass::Storage::Serializer;

	JsonStorage::JsonStorage(std::string_view master_password, std::string_view storage_location)
			:Storage(master_password, storage_location)
	{
		if (std::filesystem::exists(storage_location))
			load();
		else
			create_storage_file();
	}

	JsonStorage::~JsonStorage()
	{
		try {
			save();
		}
		catch (std::runtime_error& e) {
			std::cerr << "Error closing json file: " << storage_location << " error: " << e.what() << std::endl;
		}
	}

	void JsonStorage::flush()
	{
		save();
	}

	void JsonStorage::reload()
	{
		load();
	}

	void JsonStorage::purge()
	{
		storage_header = StorageHeader();
		categories.clear();
		std::filesystem::remove(storage_location);
	}

	StorageHeader& JsonStorage::get_header()
	{
		return storage_header;
	}

	vector<CategoryPtr>& JsonStorage::get_categories()
	{
		return categories;
	}

	void JsonStorage::save_category(const CategoryPtr& category)
	{
		auto it = find(categories.begin(), categories.end(), category);
		if (it == categories.end()) {
			categories.push_back(category);
		}
		else {
			*it = category;
		}
	}

	CategoryPtr JsonStorage::find_category(ObjectId category_id)
	{
		auto it = find_if(categories.begin(), categories.end(), [&category_id](const CategoryPtr& category) {
			return category_id == category->get_id();
		});
		if (it == categories.end()) return nullptr;
		return *it;
	}

	CategoryPtr JsonStorage::find_category(std::string_view search)
	{
		auto it = find_if(categories.begin(), categories.end(), [&search](const CategoryPtr& category) {
			return boost::algorithm::iequals(category->get_name(), search);
		});
		if (it != categories.end()) return *it;
		it = find_if(categories.begin(), categories.end(), [&search](const CategoryPtr& category) {
			return boost::algorithm::icontains(category->get_name(), search);
		});
		if (it != categories.end()) return *it;
		return nullptr;
	}

	void JsonStorage::create_storage_file()
	{
		storage_header = StorageHeader();
		categories = std::vector<CategoryPtr>();
		save();
	}

	void JsonStorage::load()
	{
		EncryptedFile encrypted_file{ storage_location, master_password };
		auto contents = encrypted_file.decrypt();
		verify_file_header(contents);
		deserialize(contents);
	}

	void JsonStorage::save()
	{
		serialize();
	}

	std::string JsonStorage::dump()
	{
		EncryptedFile encrypted_file{ storage_location, master_password };
		return encrypted_file.decrypt();
	}

	void JsonStorage::serialize()
	{
		StorageSerializer storage_serializer{};
		boost::json::object root_obj = storage_serializer.serialize(StorageTuple{ storage_header, categories });
		boost::json::value root_value = root_obj;
		JsonWriter json_writer{ root_value };
		auto contents = json_writer.save();
		EncryptedFile encrypted_file{ storage_location, master_password };
		encrypted_file.encrypt(contents);
	}

	void JsonStorage::deserialize(std::string_view contents)
	{
		JsonParser json_parser{ contents };
		boost::json::value root = json_parser.get_root();
		auto root_obj = root.as_object();
		StorageSerializer storage_serializer{};
		StorageTuple storage_tuple = storage_serializer.deserialize(root_obj);
		storage_header = std::get<StorageHeader>(storage_tuple);
		categories = std::get<std::vector<CategoryPtr>>(storage_tuple);
	}

	void JsonStorage::verify_file_header(std::string_view contents)
	{
		const char* expected_header = R"({"header":{"MOPM":true,)";
		size_t header_length = strlen(expected_header);
		auto actual_header = contents.substr(0, header_length);
		if (actual_header != expected_header)
			throw InvalidStorageException("Invalid storage, possibly wrong master password.");
	}
}
