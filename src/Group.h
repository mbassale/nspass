//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef OWNPASS_GROUP_H
#define OWNPASS_GROUP_H

#include <string>
#include <list>
#include <boost/uuid/uuid.hpp>
#include "Password.h"
#include "IdGenerator.h"

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
		Group(const Group& other)
				:id{ other.id }, type{ other.type }, name{ other.name }, passwords{ other.passwords }, url{ other.url },
				 description{ other.description } { }
		Group(Group&& other) noexcept { *this = std::move(other); }
		Group(GroupType type, boost::uuids::uuid& id, const std::string& name, const std::list<Password>& passwords, const std::string& url, const std::string& description)
				:type{ type }, id{ id }, name{ name }, passwords{ passwords }, url{ url }, description{ description } { }
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

		[[nodiscard]] const boost::uuids::uuid get_id() const { return id; }

		[[nodiscard]] const std::string& get_name() const { return name; }
		Group& set_name(const std::string& new_name)
		{
			name = new_name;
			return *this;
		}

		[[nodiscard]] const std::list<Password>& get_passwords() const { return passwords; }
		[[nodiscard]] std::list<Password>& get_passwords() { return passwords; }
		Group& add_password(const Password& password);

		const std::string& get_url() const { return url; }
		Group& set_url(const std::string& new_url)
		{
			url = new_url;
			return *this;
		}

		const std::string& get_description() const { return description; };
		Group& set_description(const std::string& new_description)
		{
			description = new_description;
			return *this;
		}

		static Group& get_default();
	protected:
		boost::uuids::uuid id;
		GroupType type;
		std::string name;
		std::list<Password> passwords;
		std::string url;
		std::string description;
	};

	class GroupFactory {
	public:

		static Group make_group(const std::string& name = std::string(),
				const std::string& url = std::string(),
				const std::string& description = std::string())
		{
			boost::uuids::uuid id = IdGenerator::make();
			const auto passwords = std::list<Password>();
			Group group{ GroupType::Group, id, name, passwords, url, description };
			return group;
		}

		static Group make_group(boost::uuids::uuid& id,
				const std::string& name,
				const std::list<Password>& passwords,
				const std::string& url = std::string(),
				const std::string& description = std::string())
		{
			Group group{ GroupType::Group, id, name, passwords, url, description };
			return group;
		}

		static Group make_site(const std::string& name = std::string(),
				const std::string& url = std::string(),
				const std::string& description = std::string())
		{
			boost::uuids::uuid id = IdGenerator::make();
			const auto passwords = std::list<Password>();
			Group group{ GroupType::Site, id, name, passwords , url, description };
			return group;
		}

		static Group make_application(const std::string& name = std::string(),
				const std::string& url = std::string(),
				const std::string& description = std::string())
		{
			boost::uuids::uuid id = IdGenerator::make();
			const auto passwords = std::list<Password>();
			Group group{ GroupType::Application, id, name, passwords , url, description };
			return group;
		}
	};
}

#endif //OWNPASS_GROUP_H
