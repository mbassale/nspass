//
// Created by Marco Bassaletti on 07-03-21.
//
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <filesystem>
#include <iostream>
#include <list>
#include <boost/json.hpp>
#include "JsonParser.h"
#include "JsonWriter.h"
#include "serializer/StorageSerializer.h"
#include "../crypto/EncryptedFile.h"
#include "JsonStorage.h"

namespace OwnPass::Storage {
	using namespace std;
	using namespace OwnPass;
	using namespace OwnPass::Crypto;
	using namespace OwnPass::Storage::Serializer;

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

	list<Category>& JsonStorage::list_categories()
	{
		return categories;
	}

	Category& JsonStorage::save_category(Category& category)
	{
		auto it = find(categories.begin(), categories.end(), category);
		if (it == categories.end()) {
			categories.push_back(category);
		}
		else {
			*it = category;
		}
		return category;
	}

	std::optional<CategoryRef> JsonStorage::find_category(ObjectId category_id)
	{
		auto it = find_if(categories.begin(), categories.end(), [&category_id](Category& category) {
			return category_id == category.get_id();
		});
		if (it == categories.end()) return std::nullopt;
		return *it;
	}

	std::optional<CategoryRef> JsonStorage::find_category(std::string_view search)
	{
		auto it = find_if(categories.begin(), categories.end(), [&search](Category& category) {
			return boost::algorithm::icontains(category.get_name(), search);
		});
		if (it == categories.end()) return std::nullopt;
		return *it;
	}

	void JsonStorage::create_storage_file()
	{
		storage_header = StorageHeader();
		categories = std::list<Category>();
		save();
	}

	void JsonStorage::load()
	{
		EncryptedFile encrypted_file{ storage_location, master_password };
		auto contents = encrypted_file.decrypt();
		deserialize(contents);
	}

	void JsonStorage::save()
	{
		serialize();
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
		categories = std::get<std::list<Category>>(storage_tuple);
	}
}
