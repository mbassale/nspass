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
		explicit BlockCrypto(const std::string& shared_key);
		~BlockCrypto();

		[[nodiscard]] size_t get_block_length() const { return blk_length; }
		[[nodiscard]] size_t pad_length(size_t length) const;

		std::vector<uint8_t> encrypt(const std::vector<uint8_t>& plain_text);
		std::vector<uint8_t> decrypt(const std::vector<uint8_t>& cipher_text);

	private:
		std::vector<uint8_t> init_vector;
		const std::string& shared_key;
		gcry_cipher_hd_t cipher_hd;
		size_t key_length;
		size_t blk_length;
	};
}

#endif //OWNPASS_BLOCKCRYPTO_H
