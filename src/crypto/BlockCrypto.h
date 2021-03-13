//
// Created by Marco Bassaletti on 11-03-21.
//

#ifndef OWNPASS_BLOCKCRYPTO_H
#define OWNPASS_BLOCKCRYPTO_H

#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <gcrypt.h>

#define GCRY_CIPHER GCRY_CIPHER_AES256

namespace OwnPass::Crypto {

	class KeyLengthError : public std::runtime_error {
	public:
		KeyLengthError(size_t key_length, size_t block_length) : std::runtime_error("") {
			std::ostringstream oss;
			oss << "Shared key size=" << key_length << " is not multiple of block length " << block_length;
			error_message = oss.str();
		}

		[[nodiscard]] const char * what() const noexcept override { return error_message.c_str(); }
	private:
		std::string error_message;
	};

	class BlockCrypto {
	public:
		BlockCrypto(const std::string& shared_key, const std::vector<uint8_t>& init_vector);
		~BlockCrypto();

		static size_t get_block_length() { return gcry_cipher_get_algo_blklen(GCRY_CIPHER); }
		static size_t get_key_length() { return gcry_cipher_get_algo_keylen(GCRY_CIPHER); }
		[[nodiscard]] size_t pad_length(size_t length) const;

		std::vector<uint8_t> encrypt(const std::vector<uint8_t>& plain_text);
		std::vector<uint8_t> decrypt(const std::vector<uint8_t>& cipher_text);

	private:
		const std::string& shared_key;
		const std::vector<uint8_t>& init_vector;
		gcry_cipher_hd_t cipher_hd{};
		size_t block_length;
	};
}

#endif //OWNPASS_BLOCKCRYPTO_H
