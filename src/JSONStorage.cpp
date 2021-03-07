//
// Created by Marco Bassaletti on 07-03-21.
//
#include <string>
#include <vector>
#include "Category.h"
#include "Group.h"
#include "JSONStorage.h"

namespace OwnPass::DB {
    using namespace std;
    using namespace OwnPass;

    JSONStorage::JSONStorage() {

    }

    JSONStorage::~JSONStorage() {

    }

    vector<Category> JSONStorage::list_categories() {
        throw std::runtime_error("Not implemented.");
    }

    Category &JSONStorage::save_category(Category &category) {
        return category;
    }

    Category JSONStorage::find_category(string &search) {
        throw std::runtime_error("Not implemented.");
    }


    vector<Group> JSONStorage::list_groups(Category &category) {
        throw std::runtime_error("Not implemented.");
    }

    Group &JSONStorage::save_group(Group &group) {
        throw std::runtime_error("Not implemented.");
    }

    Group JSONStorage::find_group(string &search) {
        throw std::runtime_error("Not implemented.");
    }
}
