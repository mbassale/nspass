//
// Created by Marco Bassaletti on 12-03-21.
//

#include <gcrypt.h>
#include <algorithm>
#include "BlockCrypto.h"
#include "StringCrypto.h"
#include "Base64Encoder.h"

#define GCRY_CIPHER GCRY_CIPHER_AES256

namespace OwnPass::Crypto {
	using namespace std;

	StringCrypto::StringCrypto(const std::string& shared_key)
			:shared_key{ shared_key }
	{
		size_t key_length = gcry_cipher_get_algo_keylen(GCRY_CIPHER);
		pad_shared_key(key_length);
	}

	std::string StringCrypto::encrypt(const std::string& plain_text)
	{
		BlockCrypto block_crypto{ padded_shared_key };
		vector<uint8_t> plain_buffer;
		plain_buffer.reserve(plain_text.size());
		copy_n(plain_text.begin(), plain_text.size(), std::back_inserter(plain_buffer));
		vector<uint8_t> cipher_block = block_crypto.encrypt(plain_buffer);
		return Base64Encoder::encode(cipher_block);
	}

	std::string StringCrypto::decrypt(const std::string& cipher_text)
	{
		vector<uint8_t> cipher_buffer = Base64Encoder::decode(cipher_text);
		BlockCrypto block_crypto{ padded_shared_key };
		vector<uint8_t> plain_buffer = block_crypto.decrypt(cipher_buffer);
		string plain_text;
		plain_text.reserve(plain_buffer.size());
		for (unsigned char i : plain_buffer) {
			if (i == 0) break;
			plain_text.push_back(i);
		}
		return plain_text;
	}

	void StringCrypto::pad_shared_key(size_t key_length)
	{
		padded_shared_key = shared_key;
		if (shared_key.size() < key_length) {
			padded_shared_key.reserve(key_length);
			while (padded_shared_key.size() < key_length) {
				padded_shared_key.push_back('0');
			}
		}
	}

}
