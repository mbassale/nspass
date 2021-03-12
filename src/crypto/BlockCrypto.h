//
// Created by Marco Bassaletti on 11-03-21.
//

#ifndef OWNPASS_BLOCKCRYPTO_H
#define OWNPASS_BLOCKCRYPTO_H

#include <vector>
#include <string>
#include <utility>
#include <gcrypt.h>

namespace OwnPass::Crypto {
	class BlockCrypto {
	public:
		// TODO: support keys of less than 16 bytes
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
