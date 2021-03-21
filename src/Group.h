//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef OWNPASS_GROUP_H
#define OWNPASS_GROUP_H

#include <utility>

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
		Group(GroupType type, ObjectId id, std::string_view name, std::list<Password> passwords,
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

		std::optional<PasswordRef> find_password(ObjectId password_id);
		std::optional<PasswordRef> find_password(std::string_view username);

		[[nodiscard]] const std::list<Password>& get_passwords() const { return passwords; }
		[[nodiscard]] std::list<Password>& get_passwords() { return passwords; }
		Group& add_password(const Password& password)
		{
			passwords.push_back(password);
			return *this;
		}
		Group& remove_password(Password& password)
		{
			passwords.remove(password);
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
		std::list<Password> passwords;
		std::string url;
		std::string description;
	};

	typedef std::reference_wrapper<Group> GroupRef;

	class GroupFactory {
	public:

		static Group make_group(std::string_view name = std::string(),
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			ObjectId id = IdGenerator::make();
			const auto passwords = std::list<Password>();
			Group group{ GroupType::Group, id, name, passwords, url, description };
			return group;
		}

		static Group make_group(ObjectId id,
				std::string_view name,
				const std::list<Password>& passwords,
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			Group group{ GroupType::Group, id, name, passwords, url, description };
			return group;
		}

		static Group make_site(std::string_view name = std::string(),
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			ObjectId id = IdGenerator::make();
			const auto passwords = std::list<Password>();
			Group group{ GroupType::Site, id, name, passwords, url, description };
			return group;
		}

		static Group make_site(ObjectId id,
				std::string_view name,
				const std::list<Password>& passwords,
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			Group group{ GroupType::Site, id, name, passwords, url, description };
			return group;
		}

		static Group make_application(std::string_view name = std::string(),
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			ObjectId id = IdGenerator::make();
			const auto passwords = std::list<Password>();
			Group group{ GroupType::Application, id, name, passwords, url, description };
			return group;
		}

		static Group make_application(ObjectId id,
				std::string_view name,
				const std::list<Password>& passwords,
				std::string_view url = std::string(),
				std::string_view description = std::string())
		{
			Group group{ GroupType::Application, id, name, passwords, url, description };
			return group;
		}
	};
}

#endif //OWNPASS_GROUP_H
