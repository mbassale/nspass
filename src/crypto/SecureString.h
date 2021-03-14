//
// Created by Marco Bassaletti on 13-03-21.
//

#ifndef OWNPASS_SECURESTRING_H
#define OWNPASS_SECURESTRING_H

#include <string>

namespace OwnPass::Crypto {
	class SecureString {
	public:
		explicit SecureString(std::string_view cipher_text) : cipher_text { cipher_text } {}
		[[nodiscard]] std::string_view get_cipher_text() const { return cipher_text; }
		std::string_view get_plain_text(std::string_view shared_key);
		void clear_plain_text() { plain_text.clear(); }
	private:
		std::string cipher_text;
		std::string plain_text;
	};
}

#endif //OWNPASS_SECURESTRING_H
