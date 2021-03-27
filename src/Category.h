//
// Created by Marco Bassaletti on 24-02-21.
//

#ifndef OWNPASS_CATEGORY_H
#define OWNPASS_CATEGORY_H

#include <utility>

#include "OwnPass.h"
#include "Group.h"

namespace OwnPass {
	class Category {
	public:
		static constexpr auto DefaultName = "Default";

		Category()
				:id{ boost::uuids::random_generator()() }, name{ DefaultName } { }

		Category(const Category& other)
				:id{ other.id }, name{ other.name }, groups{ other.groups } { }

		Category(Category&& other) noexcept
				:id{} { *this = std::move(other); }

		explicit Category(std::string_view name)
				:id{ IdGenerator::make() }, name{ name } { }

		Category(ObjectId id, std::string_view name, std::list<Group> groups)
				:id{ id }, name{ name }, groups{ std::move(groups) } { }

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

		[[nodiscard]] ObjectId get_id() const { return id; }

		[[nodiscard]] std::string_view get_name() const { return name; }

		Category& set_name(std::string_view new_name)
		{
			name = new_name;
			return *this;
		}

		[[nodiscard]] const std::list<Group>& get_groups() const { return groups; }

		[[nodiscard]] std::list<Group>& get_groups() { return groups; }

		Category& add_group(Group& group);

		std::optional<GroupRef> find_group(ObjectId group_id);
		std::optional<GroupRef> find_group(std::string_view group_name);

		std::list<GroupRef> find_groups(std::string_view search);

		Category& save_group(Group& group);

		Category& remove_group(Group& group);

		Category& remove_group(std::string_view group_name);

		bool operator==(const Category& other) const { return id == other.id; }

	private:
		ObjectId id;
		std::string name;
		std::list<Group> groups;
	};

	typedef std::reference_wrapper<Category> CategoryRef;

	class CategoryFactory {
	public:
		CategoryFactory() = delete;

		static Category make(std::string_view name)
		{
			return Category{ name };
		}

		static Category make(std::string_view name, const std::list<Group>& groups)
		{
			return Category{ IdGenerator::make(), name, groups };
		}
	};
}

#endif //OWNPASS_CATEGORY_H
