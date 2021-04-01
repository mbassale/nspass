//
// Created by Marco Bassaletti on 13-03-21.
//

#ifndef OWNPASS_SECURESTRING_H
#define OWNPASS_SECURESTRING_H

#include <string>
#include "StringCrypto.h"

namespace OwnPass::Crypto {
	class SecureString {
	public:
		SecureString()
				:cipher_text{} { }
		SecureString(const SecureString& other)
				:cipher_text{ other.cipher_text } { }
		SecureString(SecureString&& other) noexcept
		{
			*this = std::move(other);
		}
		explicit SecureString(std::string_view cipher_text)
				:cipher_text{ cipher_text } { }

		SecureString& operator=(const SecureString& other)
		{
			if (this == &other) return *this;
			cipher_text = other.cipher_text;
			return *this;
		}

		SecureString& operator=(SecureString&& other) noexcept
		{
			cipher_text = std::move(other.cipher_text);
			return *this;
		}

		[[nodiscard]] std::string_view get_cipher_text() const { return cipher_text; }
		std::string get_plain_text(std::string_view shared_key);

		bool operator==(const SecureString& other) const
		{
			return cipher_text == other.cipher_text;
		}

		bool operator==(std::string_view other_cipher_text) const
		{
			return cipher_text == other_cipher_text;
		}

		static SecureString FromCipherText(std::string_view cipher_text)
		{
			return SecureString{ cipher_text };
		}

		static SecureString FromPlainText(std::string_view shared_key, std::string_view plain_text)
		{
			StringCrypto string_crypto{ shared_key };
			return SecureString{ string_crypto.encrypt(plain_text) };
		}

	private:
		std::string cipher_text;
	};
}

#endif //OWNPASS_SECURESTRING_H
