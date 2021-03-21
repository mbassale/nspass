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
#include "CategorySerializer.h"
#include "../crypto/EncryptedFile.h"
#include "JsonStorage.h"

namespace OwnPass::Storage {
	using namespace std;
	using namespace OwnPass;
	using namespace OwnPass::Crypto;

	JsonStorage::~JsonStorage()
	{
		try {
			save_and_close();
		}
		catch (std::runtime_error& e) {
			std::cerr << "Error closing json file: " << StorageFile << " error: " << e.what() << std::endl;
		}
	}

	void JsonStorage::open(std::string_view new_master_password)
	{
		master_password = new_master_password;
		if (std::filesystem::exists(StorageFile))
			load();
		else
			create_storage_file();
	}

	void JsonStorage::close()
	{
		save_and_close();
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
		categories.clear();
		std::filesystem::remove(StorageFile);
	}

	list<CategoryPtr>& JsonStorage::list_categories()
	{
		return categories;
	}

	void JsonStorage::save_category(CategoryPtr& category)
	{
		auto it = find(categories.begin(), categories.end(), category);
		if (it == categories.end()) {
			categories.push_back(category);
		}
	}

	std::optional<CategoryPtr> JsonStorage::find_category(std::string_view search)
	{
		auto it = find_if(categories.begin(), categories.end(), [&search](CategoryPtr& category) {
			return boost::algorithm::icontains(category->get_name(), search);
		});
		if (it == categories.end()) return std::nullopt;
		return *it;
	}

	void JsonStorage::create_storage_file()
	{
		categories = std::list<CategoryPtr>();
		save();
	}

	void JsonStorage::load()
	{
		EncryptedFile encrypted_file{ StorageFile, master_password };
		auto contents = encrypted_file.decrypt();
		JsonParser json_parser{ contents };
		boost::json::value root = json_parser.get_root();
		CategorySerializer categories_serializer;
		categories = categories_serializer.deserialize(root.as_array());
	}

	void JsonStorage::save()
	{
		CategorySerializer categories_serializer;
		boost::json::array root = categories_serializer.serialize(categories);
		boost::json::value root_value = root;
		JsonWriter json_writer{ root_value };
		auto contents = json_writer.save();
		EncryptedFile encrypted_file{ StorageFile, master_password };
		encrypted_file.encrypt(contents);
	}

	void JsonStorage::save_and_close()
	{
		save();
	}
}
