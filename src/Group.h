//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef OWNPASS_GROUP_H
#define OWNPASS_GROUP_H

#include "OwnPass.h"
#include "Password.h"

namespace OwnPass {
	class Password;

	enum class GroupType {
		Group = 0,
		Site,
		Application
	};

	/**
	  * Pure virtual class for Sites and Applications
	  */
	class Group {
	public:
		constexpr static const auto DefaultGroupName{ "Default" };

		Group()
				:id{ IdGenerator::make() }, type{ GroupType::Group }, name(DefaultGroupName) { }
		Group(const Group& other) = default;
		Group(Group&& other) noexcept { *this = std::move(other); }
		Group(GroupType type, ObjectId id, std::string_view name, std::vector<PasswordPtr> passwords,
				std::string_view url, std::string_view description)
				:type{ type }, id{ id }, name{ name }, passwords{ std::move(passwords) }, url{ url },
				 description{ description } { }
		virtual ~Group() = default;

		Group& operator=(const Group& other)
		{
			if (this == &other) return *this;
			id = other.id;
			type = other.type;
			name = other.name;
			passwords = other.passwords;
			url = other.url;
			description = other.description;
			return *this;
		}
		Group& operator=(Group&& other) noexcept
		{
			id = other.id;
			type = other.type;
			name = std::move(other.name);
			passwords.clear();
			passwords = std::move(other.passwords);
			url = std::move(other.url);
			description = std::move(other.description);
			return *this;
		}

		[[nodiscard]] ObjectId get_id() const { return id; }

		[[nodiscard]] GroupType get_type() const { return type; }

		[[nodiscard]] std::string_view get_name() const { return name; }
		Group& set_name(std::string_view new_name)
		{
			name = new_name;
			return *this;
		}

		PasswordPtr find_password(ObjectId password_id);
		PasswordPtr find_password(std::string_view username);

		[[nodiscard]] const std::vector<PasswordPtr>& get_passwords() const { return passwords; }
		[[nodiscard]] std::vector<PasswordPtr>& get_passwords() { return passwords; }
		Group& add_password(const PasswordPtr& password)
		{
			passwords.push_back(password);
			return *this;
		}
		Group& remove_password(PasswordPtr& password)
		{
			for (auto it = passwords.begin(); it != passwords.end(); it++) {
				if ((*it)->get_id() == password->get_id()) {
					passwords.erase(it);
					break;
				}
			}
			return *this;
		}

		[[nodiscard]] std::string_view get_url() const { return url; }
		Group& set_url(std::string_view new_url)
		{
			url = new_url;
			return *this;
		}

		[[nodiscard]] std::string_view get_description() const { return description; };
		Group& set_description(std::string_view new_description)
		{
			description = new_description;
			return *this;
		}

		bool operator==(const Group& other) const { return id == other.id; }

	protected:
		ObjectId id{};
		GroupType type{};
		std::string name;
		std::vector<PasswordPtr> passwords;
		std::string url;
		std::string description;
	};

	typedef std::reference_wrapper<Group> GroupRef;

	typedef std::shared_ptr<Group> GroupPtr;

	typedef std::weak_ptr<Group> GroupWeakPtr;

	class GroupFactory {
	public:

		static GroupPtr make_group(std::string_view name = std::string(),
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			ObjectId id = IdGenerator::make();
			const auto passwords = std::vector<PasswordPtr>();
			return std::make_shared<Group>(GroupType::Group, id, name, passwords, url, description);
		}

		static GroupPtr make_group(ObjectId id,
				std::string_view name,
				const std::vector<PasswordPtr>& passwords,
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			return std::make_shared<Group>(GroupType::Group, id, name, passwords, url, description);
		}

		static GroupPtr make_site(std::string_view name = std::string(),
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			ObjectId id = IdGenerator::make();
			const auto passwords = std::vector<PasswordPtr>();
			return std::make_shared<Group>(GroupType::Site, id, name, passwords, url, description);
		}

		static GroupPtr make_site(ObjectId id,
				std::string_view name,
				const std::vector<PasswordPtr>& passwords,
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			return std::make_shared<Group>(GroupType::Site, id, name, passwords, url, description);
		}

		static GroupPtr make_application(std::string_view name = std::string(),
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			ObjectId id = IdGenerator::make();
			const auto passwords = std::vector<PasswordPtr>();
			return std::make_shared<Group>(GroupType::Application, id, name, passwords, url, description);
		}

		static GroupPtr make_application(ObjectId id,
				std::string_view name,
				const std::vector<PasswordPtr>& passwords,
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			return std::make_shared<Group>(GroupType::Application, id, name, passwords, url, description);
		}
	};
}

#endif //OWNPASS_GROUP_H
