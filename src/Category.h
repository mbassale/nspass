//
// Created by Marco Bassaletti on 24-02-21.
//

#ifndef OWNPASS_CATEGORY_H
#define OWNPASS_CATEGORY_H

#include "Group.h"
#include <list>
#include <optional>

namespace OwnPass {
    class Category {
    public:
        const char* DefaultName = "Default";
        Category() : name{ DefaultName } {}
        Category(const Category& other) : name{ other.name }, groups{ other.groups } {}
        Category(Category&& other) noexcept { *this = std::move(other); }
        explicit Category(const char* name) : name { name } {}
        explicit Category(std::string& name) : name{ name } {}
        explicit Category(std::string&& name) : name{ std::move(name) } {}
        Category(const char* name, std::list<Group>& groups) : name{ name }, groups{ groups } {}
        Category(std::string& name, std::list<Group>& groups) : name{ name }, groups{ groups } {}
        ~Category() = default;

        Category& operator=(const Category& other) {
            if (this == &other) return *this;
            name = other.name;
            groups = other.groups;
            return *this;
        }
        Category& operator=(Category&& other)  noexcept {
            name = std::move(other.name);
            groups.clear();
            groups = std::move(other.groups);
            return *this;
        }
        [[nodiscard]] const std::string& get_name() const { return name; }
        Category& set_name(const char* new_name) { name = new_name; return *this; }
        Category& set_name(std::string& new_name) { name = new_name; return *this; }
        [[nodiscard]] const std::list<Group>& get_groups() const { return groups; }
        [[nodiscard]] std::list<Group>& get_groups() { return groups; }
        Category& add_group(Group& group);
        std::optional<Group> find_group(std::string& group_name);
        std::list<std::reference_wrapper<Group>> find_groups(std::string& search);
        Category& remove_group(Group& group);
        Category& remove_group(std::string& group_name);

        bool operator==(const Category& other) const { return name == other.name; }
    private:
        std::string name;
        std::list<Group> groups;
    };
}


#endif //OWNPASS_CATEGORY_H
