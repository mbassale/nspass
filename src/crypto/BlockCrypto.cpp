//
// Created by Marco Bassaletti on 11-03-21.
//

#include <gcrypt.h>
#include <cmath>
#include <memory>
#include <cstring>
#include <sstream>
#include "InitializationVector.h"
#include "BlockCrypto.h"

namespace NSPass::Crypto {

	BlockCrypto::BlockCrypto(std::string_view shared_key, const std::vector<uint8_t>& init_vector)
			:shared_key{ shared_key }, init_vector{ init_vector }
	{
		int gcry_mode = GCRY_CIPHER_MODE_CBC;
		gcry_error_t gcry_ret;

		gcry_ret = gcry_cipher_open(
				&cipher_hd,    // gcry_cipher_hd_t *hd
				GCRY_CIPHER,   // int algo
				gcry_mode,     // int mode
				0);            // unsigned int flags
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_open failed: " << gcry_strsource(gcry_ret) << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}

		block_length = get_block_length();
		if (shared_key.size() < block_length || shared_key.size() % block_length != 0) {
			throw KeyLengthError{ shared_key.size(), block_length };
		}

		gcry_ret = gcry_cipher_setkey(cipher_hd, shared_key.data(), shared_key.size());
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_setkey failed: " << gcry_strsource(gcry_ret) << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}
	}

	BlockCrypto::~BlockCrypto()
	{
		gcry_cipher_close(cipher_hd);
	}

	std::vector<uint8_t> BlockCrypto::encrypt(const std::vector<uint8_t>& plain_text)
	{
		gcry_error_t gcry_ret = gcry_cipher_setiv(cipher_hd, init_vector.data(), init_vector.size());
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_setiv failed: " << gcry_strsource(gcry_ret) << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}

		size_t buffer_size = pad_length(plain_text.size());
		std::vector<uint8_t> output_buffer;
		output_buffer.resize(buffer_size, 0);
		std::vector<uint8_t> input_buffer;
		input_buffer.resize(buffer_size, 0);
		memcpy(input_buffer.data(), plain_text.data(), plain_text.size());

		gcry_ret = gcry_cipher_encrypt(
				cipher_hd, // gcry_cipher_hd_t h
				output_buffer.data(), // unsigned char *out
				buffer_size, // size_t outsize
				input_buffer.data(), // const unsigned char *in
				buffer_size); // size_t inlen
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_encrypt failed: " << gcry_strsource(gcry_ret) << " "
						  << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}

		return output_buffer;
	}

	std::vector<uint8_t> BlockCrypto::decrypt(const std::vector<uint8_t>& cipher_text)
	{
		gcry_error_t gcry_ret = gcry_cipher_setiv(cipher_hd, init_vector.data(), init_vector.size());
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_setiv failed: " << gcry_strsource(gcry_ret) << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}

		std::vector<uint8_t> output_buffer;
		output_buffer.resize(cipher_text.size(), 0);

		gcry_ret = gcry_cipher_decrypt(
				cipher_hd, // gcry_cipher_hd_t h
				output_buffer.data(), // unsigned char *out
				cipher_text.size(), // size_t outsize
				cipher_text.data(), // const unsigned char *in
				cipher_text.size()); // size_t inlen
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_encrypt failed: " << gcry_strsource(gcry_ret) << " "
						  << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}

		return output_buffer;
	}

	size_t BlockCrypto::pad_length(size_t length) const
	{
		size_t number_of_blocks = std::ceil(static_cast<float>(length) / static_cast<float>(block_length));
		return number_of_blocks * block_length;
	}
}
