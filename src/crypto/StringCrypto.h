//
// Created by Marco Bassaletti on 12-03-21.
//

#ifndef OWNPASS_STRINGCRYPTO_H
#define OWNPASS_STRINGCRYPTO_H

#include <string>
#include <vector>

namespace OwnPass::Crypto {

	class StringCrypto {
	public:
		explicit StringCrypto(std::string_view shared_key);

		std::string encrypt(std::string_view plain_text);
		std::string decrypt(std::string_view cipher_text);

	protected:
		std::string_view shared_key;
		std::string padded_shared_key;
		void pad_shared_key(size_t key_length);
	};

}

#endif //OWNPASS_STRINGCRYPTO_H
