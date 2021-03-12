//
// Created by Marco Bassaletti on 11-03-21.
//

#ifndef OWNPASS_STRINGCRYPTO_H
#define OWNPASS_STRINGCRYPTO_H

#include <vector>
#include <string>
#include <utility>
#include <gcrypt.h>

namespace OwnPass::Crypto {
	class StringCrypto {
	public:
		// TODO: support keys of less than 16 bytes
		explicit StringCrypto(const std::string& shared_key);
		~StringCrypto();

		std::vector<uint8_t> encrypt(const std::string& plain_text);
		std::string decrypt(const std::vector<uint8_t>& cipher_text);

	private:
		// TODO: generate random initialization vector
		std::vector<uint8_t> init_vector;
		const std::string& shared_key;
		gcry_cipher_hd_t cipher_hd;
		size_t key_length;
		size_t blk_length;
	};
}

#endif //OWNPASS_STRINGCRYPTO_H
