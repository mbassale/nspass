//
// Created by Marco Bassaletti on 24-02-21.
//

#ifndef OWNPASS_CATEGORY_H
#define OWNPASS_CATEGORY_H

#include "Group.h"
#include <list>
#include <optional>
#include <boost/uuid/uuid.hpp>
#include "IdGenerator.h"

namespace OwnPass {
	class Category {
	public:
		const char* DefaultName = "Default";

		Category()
				:id{ boost::uuids::random_generator()() }, name{ DefaultName } { }

		Category(const Category& other)
				:id{ other.id }, name{ other.name }, groups{ other.groups } { }

		Category(Category&& other) noexcept
				:id{} { *this = std::move(other); }

		Category(const std::string& name)
				:id{ IdGenerator::make() }, name{ name } { }

		explicit Category(std::string&& name)
				:id{ IdGenerator::make() }, name{ std::move(name) } { }

		Category(boost::uuids::uuid& id, const std::string& name, std::list<Group>& groups)
				:id{ id }, name{ name }, groups{ groups } { }

		~Category() = default;

		Category& operator=(const Category& other)
		{
			if (this == &other) return *this;
			id = other.id;
			name = other.name;
			groups = other.groups;
			return *this;
		}

		Category& operator=(Category&& other) noexcept
		{
			id = other.id;
			name = std::move(other.name);
			groups.clear();
			groups = std::move(other.groups);
			return *this;
		}

		[[nodiscard]] const boost::uuids::uuid& get_id() const { return id; }

		[[nodiscard]] const std::string& get_name() const { return name; }

		Category& set_name(const std::string& new_name)
		{
			name = new_name;
			return *this;
		}

		[[nodiscard]] const std::list<Group>& get_groups() const { return groups; }

		[[nodiscard]] std::list<Group>& get_groups() { return groups; }

		Category& add_group(Group& group);

		std::optional<Group> find_group(const std::string& group_name);

		std::list<std::reference_wrapper<Group>> find_groups(const std::string& search);

		Category& remove_group(Group& group);

		Category& remove_group(const std::string& group_name);

		bool operator==(const Category& other) const { return id == other.id; }

	private:
		boost::uuids::uuid id;
		std::string name;
		std::list<Group> groups;
	};
}

#endif //OWNPASS_CATEGORY_H
