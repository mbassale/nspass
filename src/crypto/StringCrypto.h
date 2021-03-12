//
// Created by Marco Bassaletti on 11-03-21.
//

#ifndef OWNPASS_STRINGCRYPTO_H
#define OWNPASS_STRINGCRYPTO_H

#include <string>
#include <utility>
#include <gcrypt.h>

namespace OwnPass::Crypto {

	struct EncryptedBuffer {
		std::shared_ptr<uint8_t> data;
		const size_t size;
		EncryptedBuffer(std::shared_ptr<uint8_t>& data, const size_t size) : data{ data }, size{ size } {}
	};

	class StringCrypto {
	public:
		// TODO: support keys of less than 16 bytes
		explicit StringCrypto(const std::string& shared_key);
		~StringCrypto();

		EncryptedBuffer encrypt(const std::string& plain_text);
		std::string decrypt(const EncryptedBuffer& buffer);

	private:
		// TODO: generate random initialization vector
		const char* init_vector = "a test ini value";
		const std::string& shared_key;
		gcry_cipher_hd_t cipher_hd;
		size_t key_length;
		size_t blk_length;
	};
}

#endif //OWNPASS_STRINGCRYPTO_H
