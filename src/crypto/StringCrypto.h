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
		explicit StringCrypto(const std::string& shared_key);

		std::string encrypt(const std::string& plain_text);
		std::string decrypt(const std::string& cipher_text);

	protected:
		const std::string& shared_key;
		std::string padded_shared_key;
		void pad_shared_key(size_t key_length);
	};

}

#endif //OWNPASS_STRINGCRYPTO_H
