//
// Created by Marco Bassaletti on 12-03-21.
//

#include <algorithm>
#include "Base64Encoder.h"
#include "InitializationVector.h"
#include "BlockCrypto.h"
#include "StringCrypto.h"

#define GCRY_CIPHER GCRY_CIPHER_AES256

namespace OwnPass::Crypto {
	using namespace std;

	StringCrypto::StringCrypto(const std::string& shared_key)
			:shared_key{ shared_key }
	{
		pad_shared_key(BlockCrypto::get_key_length());
	}

	std::string StringCrypto::encrypt(const std::string& plain_text)
	{
		vector<uint8_t> init_vector = InitializationVectorFactory::make(BlockCrypto::get_block_length());
		BlockCrypto block_crypto{ padded_shared_key, init_vector };
		vector<uint8_t> plain_buffer;
		plain_buffer.reserve(plain_text.size());
		copy_n(plain_text.begin(), plain_text.size(), std::back_inserter(plain_buffer));
		vector<uint8_t> cipher_block = block_crypto.encrypt(plain_buffer);
		vector<uint8_t> cipher_block_with_iv;
		cipher_block_with_iv.reserve(init_vector.size() + cipher_block.size());
		for (auto& b : init_vector)
			cipher_block_with_iv.push_back(b);
		for (auto& b : cipher_block)
			cipher_block_with_iv.push_back(b);
		return Base64Encoder::encode(cipher_block_with_iv);
	}

	std::string StringCrypto::decrypt(const std::string& cipher_text)
	{
		vector<uint8_t> cipher_buffer_with_iv = Base64Encoder::decode(cipher_text);
		vector<uint8_t> init_vector;
		auto block_length = BlockCrypto::get_block_length();
		init_vector.reserve(block_length);
		init_vector.insert(init_vector.end(), cipher_buffer_with_iv.begin(), cipher_buffer_with_iv.begin() + block_length);
		BlockCrypto block_crypto{ padded_shared_key, init_vector };
		vector<uint8_t> cipher_buffer;
		cipher_buffer.reserve(cipher_buffer_with_iv.size() - block_length);
		auto it = cipher_buffer_with_iv.begin() + block_length;
		while (it != cipher_buffer_with_iv.end())
			cipher_buffer.push_back(*it++);
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
