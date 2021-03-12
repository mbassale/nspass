//
// Created by Marco Bassaletti on 11-03-21.
//

#include <gcrypt.h>
#include <cmath>
#include <memory>
#include <cstring>
#include <sstream>
#include <iostream>
#include <boost/scoped_ptr.hpp>
#include "StringCrypto.h"

#define GCRY_CIPHER GCRY_CIPHER_AES256

namespace OwnPass::Crypto {

	StringCrypto::StringCrypto(const std::string& shared_key)
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
		std::cout << "key_length = " << key_length << std::endl;
		std::cout << "sym_key = " << sym_key << " strlen = " << strlen(sym_key) << std::endl;
		gcry_ret = gcry_cipher_setkey(cipher_hd, sym_key, key_length);
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_setkey failed: " << gcry_strsource(gcry_ret) << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}

		blk_length = gcry_cipher_get_algo_blklen(GCRY_CIPHER);
		std::cout << "blk_length = " << blk_length << std::endl;
		std::cout << "init_vector = " << init_vector << " strlen = " << strlen(init_vector) << std::endl;
		gcry_ret = gcry_cipher_setiv(cipher_hd, init_vector, blk_length);
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_setiv failed: " << gcry_strsource(gcry_ret) << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}
	}

	StringCrypto::~StringCrypto()
	{
		gcry_cipher_close(cipher_hd);
	}

	EncryptedBuffer StringCrypto::encrypt(const std::string& plain_text)
	{
		size_t number_of_blocks = std::ceil(static_cast<float>(plain_text.size()) / static_cast<float>(blk_length));
		size_t buffer_size = number_of_blocks * blk_length;
		std::shared_ptr<uint8_t> output_buffer{ new uint8_t[buffer_size] };
		boost::scoped_ptr<uint8_t> input_buffer{ new uint8_t[buffer_size] };
		memset(output_buffer.get(), 0, buffer_size);
		memset(input_buffer.get(), 0, buffer_size);
		memcpy(input_buffer.get(), plain_text.c_str(), plain_text.size());

		std::cout << "plain_text: " << plain_text << " size: " << plain_text.size() << " number of blocks: "
				  << number_of_blocks << " encrypted text size: " << buffer_size << std::endl;

		gcry_error_t gcry_ret = gcry_cipher_encrypt(
				cipher_hd,         // gcry_cipher_hd_t h
				output_buffer.get(),      // unsigned char *out
				buffer_size,   // size_t outsize
				input_buffer.get(),          // const unsigned char *in
				buffer_size);  // size_t inlen
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_encrypt failed: " << gcry_strsource(gcry_ret) << " "
						  << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}

		return EncryptedBuffer{ output_buffer, buffer_size };
	}

	std::string StringCrypto::decrypt(const EncryptedBuffer& buffer)
	{
		boost::scoped_ptr<uint8_t> output_buffer{ new uint8_t[buffer.size + 1] };
		memset(output_buffer.get(), 0, buffer.size + 1);

		gcry_error_t gcry_ret = gcry_cipher_decrypt(
				cipher_hd,          // gcry_cipher_hd_t h
				output_buffer.get(),      // unsigned char *out
				buffer.size,    // size_t outsize
				buffer.data.get(),       // const unsigned char *in
				buffer.size);   // size_t inlen
		if (gcry_ret) {
			std::ostringstream error_message;
			error_message << "gcry_cipher_encrypt failed: " << gcry_strsource(gcry_ret) << " "
						  << gcry_strerror(gcry_ret);
			throw std::runtime_error(error_message.str());
		}

		return std::string(reinterpret_cast<char*>(output_buffer.get()));
	}

}
