//
// Created by Marco Bassaletti on 24-02-21.
//

#ifndef OWNPASS_CATEGORY_H
#define OWNPASS_CATEGORY_H

#include <utility>

#include "NSPass.h"
#include "Group.h"

namespace NSPass {
	class Category {
	public:
		static constexpr auto DefaultName = "Default";

		Category()
				:id{ boost::uuids::random_generator()() }, name{ DefaultName } { }

		Category(const Category& other) = default;

		Category(Category&& other) noexcept
				:id{} { *this = std::move(other); }

		explicit Category(std::string_view name)
				:id{ IdGenerator::make() }, name{ name } { }

		Category(ObjectId id, std::string_view name, std::vector<GroupPtr> groups)
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

		[[nodiscard]] const std::vector<GroupPtr>& get_groups() const { return groups; }

		Category& add_group(const GroupPtr& group);

		GroupPtr find_group(ObjectId group_id);
		GroupPtr find_group(std::string_view group_name);
		std::list<GroupPtr> find_groups(std::string_view search);

		Category& save_group(const GroupPtr& group);

		Category& remove_group(const GroupPtr& group);

		Category& remove_group(std::string_view group_name);

		bool operator==(const Category& other) const { return id == other.id; }

	private:
		ObjectId id;
		std::string name;
		std::vector<GroupPtr> groups;
	};

	typedef std::reference_wrapper<Category> CategoryRef;

	typedef std::shared_ptr<Category> CategoryPtr;

	typedef std::weak_ptr<Category> CategoryWeakPtr;

	class CategoryFactory {
	public:
		CategoryFactory() = delete;

		static CategoryPtr make(std::string_view name)
		{
			return std::make_shared<Category>(name);
		}

		static CategoryPtr make(std::string_view name, const std::vector<GroupPtr>& groups)
		{
			return std::make_shared<Category>(IdGenerator::make(), name, groups);
		}
	};
}

#endif //OWNPASS_CATEGORY_H
