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

#define GCRY_CIPHER GCRY_CIPHER_AES256

namespace OwnPass::Crypto {

	BlockCrypto::BlockCrypto(const std::string& shared_key)
			:shared_key{ shared_key }
	{
		int gcry_mode = GCRY_CIPHER_MODE_ECB;
		gcry_error_t gcry_ret;

		/* http://lists.gnupg.org/pipermail/gcrypt-devel/2003-August/000458.html
		 * Because you can't know in a library whether another library has
		 * already initialized the library
		 */
		if (!gcry_control(GCRYCTL_ANY_INITIALIZATION_P)) {
			gcry_check_version(NULL); /* before calling any other functions */
		}

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

		key_length = gcry_cipher_get_algo_keylen(GCRY_CIPHER);
		const char* sym_key = shared_key.c_str(); // larger than 16 bytes
		gcry_ret = gcry_cipher_setkey(cipher_hd, sym_key, key_length);
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_setkey failed: " << gcry_strsource(gcry_ret) << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}

		blk_length = gcry_cipher_get_algo_blklen(GCRY_CIPHER);
		if (shared_key.size() < blk_length || shared_key.size() % blk_length != 0) {
			std::ostringstream error_message;
			error_message << "Shared key size=" << shared_key.size() << " is not multiple of block length " << blk_length;
			throw std::runtime_error(error_message.str());
		}

		init_vector = InitializationVectorFactory::make(blk_length);

		gcry_ret = gcry_cipher_setiv(cipher_hd, init_vector.data(), init_vector.size());
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_setiv failed: " << gcry_strsource(gcry_ret) << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}
	}

	BlockCrypto::~BlockCrypto()
	{
		gcry_cipher_close(cipher_hd);
	}

	std::vector<uint8_t> BlockCrypto::encrypt(const std::vector<uint8_t>& plain_text)
	{
		size_t buffer_size = pad_length(plain_text.size());
		std::vector<uint8_t> output_buffer;
		output_buffer.resize(buffer_size, 0);
		std::vector<uint8_t> input_buffer;
		input_buffer.resize(buffer_size, 0);
		memcpy(input_buffer.data(), plain_text.data(), plain_text.size());

		gcry_error_t gcry_ret = gcry_cipher_encrypt(
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
		std::vector<uint8_t> output_buffer;
		output_buffer.resize(cipher_text.size(), 0);

		gcry_error_t gcry_ret = gcry_cipher_decrypt(
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
		size_t number_of_blocks = std::ceil(static_cast<float>(length) / static_cast<float>(blk_length));
		return number_of_blocks * blk_length;
	}
}
