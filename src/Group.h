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

	/**
	  * Pure virtual class for Sites and Applications
	  */
	class Group {
	public:
		constexpr static const auto DefaultGroupName{ "Default" };

		Group()
				:id{ IdGenerator::make() }, name(DefaultGroupName) { }
		Group(const Group& other)
				:id{ other.id }, name{ other.name }, passwords{ other.passwords } { }
		Group(Group&& other) noexcept { *this = std::move(other); }
		Group(const char* name)
				:id{ IdGenerator::make() }, name{ name } { }
		Group(std::string& name)
				:id{ IdGenerator::make() }, name{ name } { }
		Group(std::string&& name)
				:id{ IdGenerator::make() }, name{} { this->name = std::move(name); }
		Group(std::string& name, std::list<Password>& passwords)
				:id{ IdGenerator::make() }, name{ name }, passwords{ passwords } { }
		Group(boost::uuids::uuid& id, std::string& name)
				:id{ id }, name{ name } { }
		Group(boost::uuids::uuid& id, std::string& name, std::list<Password>& passwords)
				:id{ id }, name{ name }, passwords{ passwords } { }
		Group(boost::uuids::uuid& id, std::string&& name)
				:id{ id }, name() { this->name = std::move(name); }
		Group(boost::uuids::uuid& id, std::string&& name, std::list<Password>&& passwords)
				:id{ id }, name{}, passwords{}
		{
			this->name = std::move(name);
			this->passwords = std::move(passwords);
		}
		~Group() = default;

		Group& operator=(const Group& other)
		{
			if (this == &other) return *this;
			id = other.id;
			name = other.name;
			passwords = other.passwords;
			return *this;
		}
		Group& operator=(Group&& other) noexcept
		{
			id = other.id;
			name = std::move(other.name);
			passwords.clear();
			passwords = std::move(other.passwords);
			return *this;
		}

		[[nodiscard]] const boost::uuids::uuid get_id() const { return id; }
		[[nodiscard]] const std::string& get_name() const { return name; }
		Group& set_name(const char* new_name)
		{
			name = new_name;
			return *this;
		}
		Group& set_name(std::string& new_name)
		{
			name = new_name;
			return *this;
		}
		[[nodiscard]] const std::list<Password>& get_passwords() const { return passwords; }
		[[nodiscard]] std::list<Password>& get_passwords() { return passwords; }
		Group& add_password(const Password& password);

		static Group& get_default();
	protected:
		boost::uuids::uuid id;
		std::string name;
		std::list<Password> passwords;
	};
}

#endif //OWNPASS_GROUP_H
