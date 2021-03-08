//
// Created by Marco Bassaletti on 07-03-21.
//
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <filesystem>
#include <iostream>
#include <list>
#include <boost/json.hpp>
#include "JsonStorage.h"
#include "JsonParser.h"
#include "JsonWriter.h"
#include "CategorySerializer.h"

namespace OwnPass::Storage {
	using namespace std;
	using namespace OwnPass;

	JsonStorage::JsonStorage()
	{
		load();
	}

	JsonStorage::~JsonStorage()
	{
		try {
			save();
		}
		catch (std::runtime_error& e) {
			std::cerr << "Error saving json file: " << StorageFile << " error: " << e.what() << std::endl;
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
		categories.clear();
		std::filesystem::remove(StorageFile);
		save();
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

	Category& JsonStorage::find_category(const string& search)
	{
		auto it = find_if(categories.begin(), categories.end(), [&search](Category& category) {
			return boost::algorithm::icontains(category.get_name(), search);
		});
		if (it == categories.end()) throw std::runtime_error("Not found");
		return *it;
	}

	void JsonStorage::load()
	{
		JsonParser json_parser{ StorageFile };
		boost::json::value root = json_parser.get_root();
		CategorySerializer categories_serializer;
		categories = categories_serializer.deserialize(root.as_array());
	}

	void JsonStorage::save()
	{
		CategorySerializer categories_serializer;
		boost::json::array root = categories_serializer.serialize(categories);
		boost::json::value root_value = root;
		JsonWriter json_writer{ root_value, StorageFile };
		json_writer.save();
	}
}
