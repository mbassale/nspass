//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef OWNPASS_PASSWORD_H
#define OWNPASS_PASSWORD_H

#include <utility>

#include "OwnPass.h"
#include "./crypto/SecureString.h"

namespace OwnPass {
	using OwnPass::Crypto::SecureString;

	class Password {
	public:
		Password(const Password& other) = default;
		Password(Password&& other) noexcept { *this = std::move(other); }

		Password(ObjectId id, std::string_view username, SecureString password,
				std::string_view url, std::string_view description)
				:id{ id }, username{ username }, password{ std::move(password) }, url{ url },
				 description{ description } { }

		~Password() = default;

		Password& operator=(const Password& other)
		{
			if (this == &other) return *this;
			id = other.id;
			username = other.username;
			password = other.password;
			url = other.url;
			description = other.description;
			return *this;
		}

		Password& operator=(Password&& other) noexcept
		{
			id = other.id;
			username = std::move(other.username);
			password = std::move(other.password);
			url = std::move(other.url);
			description = std::move(other.description);
			return *this;
		}

		[[nodiscard]] ObjectId get_id() const { return id; }

		[[nodiscard]] std::string_view get_username() const { return username; }

		Password& set_username(std::string_view new_username)
		{
			username = new_username;
			return *this;
		}

		[[nodiscard]] const SecureString& get_password() const { return password; }

		Password& set_password(const SecureString& new_password)
		{
			password = new_password;
			return *this;
		}

		[[nodiscard]] std::string_view get_url() const { return url; }

		Password& set_url(std::string_view new_url)
		{
			url = new_url;
			return *this;
		}

		[[nodiscard]] std::string_view get_description() const { return description; }

		Password& set_description(std::string_view new_description)
		{
			description = new_description;
			return *this;
		}

		bool operator==(const Password& other) const { return id == other.id; }

	private:
		ObjectId id{};
		std::string username;
		SecureString password;
		std::string url;
		std::string description;
	};

	typedef std::reference_wrapper<Password> PasswordRef;

	typedef std::shared_ptr<Password> PasswordPtr;

	class PasswordFactory {
	public:
		PasswordFactory() = delete;
		~PasswordFactory() = delete;

		static PasswordPtr make(std::string_view username, const SecureString& pass,
				std::string_view url = std::string(), std::string_view description = std::string());

		static PasswordPtr make(ObjectId id, std::string_view username,
				const SecureString& pass, std::string_view url = std::string(),
				std::string_view description = std::string());
	};
}

#endif //OWNPASS_PASSWORD_H
