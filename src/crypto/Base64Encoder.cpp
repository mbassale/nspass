//
// Created by Marco Bassaletti on 12-03-21.
//

#include <cstdlib>
#include <cstring>
#include "Base64Encoder.h"

extern "C" {

/**
 * Base64 Encoding/Decoding functions from the book Secure Programming Cookbook for C and C++,
 * by John Viega, Matt Messier.
 * ISBN: 9780596003944
 */
static char b64_table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static char b64_revert_table[256] = {
		-3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*0-15*/
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*16-31*/
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63, /*32-47*/
		52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -2, -1, -1, /*48-63*/
		-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, /*64-79*/
		15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, /*80-95*/
		-1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, /*96-111*/
		41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1, /*112-127*/
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*128-143*/
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*144-159*/
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*160-175*/
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*176-191*/
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*192-207*/
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*208-223*/
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, /*224-239*/
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1  /*240-255*/
};

/**
 * Accepts a binary buffer with an associated size.
 * Returns a base64 encoded, NULL-terminated string.
 */
unsigned char* base64_encode(unsigned char* input, size_t len, int wrap)
{
	unsigned char* output, * p;
	size_t i = 0, mod = len % 3, toalloc;

	toalloc = (len / 3) * 4+(3-mod) % 3+1;
	if (wrap) {
		toalloc += len / 57;
		if (len % 57) toalloc++;
	}

	p = output = (unsigned char*)malloc(((len / 3)+(mod ? 1 : 0)) * 4+1);
	if (!p) return nullptr;

	while (i < len-mod) {
		*p++ = b64_table[input[i++] >> 2];
		*p++ = b64_table[((input[i-1] << 4) | (input[i] >> 4)) & 0x3f];
		*p++ = b64_table[((input[i] << 2) | (input[i+1] >> 6)) & 0x3f];
		*p++ = b64_table[input[i+1] & 0x3f];
		i += 2;
		if (wrap && !(i % 57)) *p++ = '\n';
	}
	if (!mod) {
		if (wrap && i % 57) *p++ = '\n';
		*p = 0;
		return output;
	}
	else {
		*p++ = b64_table[input[i++] >> 2];
		*p++ = b64_table[((input[i-1] << 4) | (input[i] >> 4)) & 0x3f];
		if (mod == 1) {
			*p++ = '=';
			*p++ = '=';
			if (wrap) *p++ = '\n';
			*p = 0;
			return output;
		}
		else {
			*p++ = b64_table[(input[i] << 2) & 0x3f];
			*p++ = '=';
			if (wrap) *p++ = '\n';
			*p = 0;
			return output;
		}
	}
}

static unsigned int raw_base64_decode(unsigned char* in, unsigned char* out,
		int strict, int* err)
{
	int x;
	unsigned int result = 0;
	unsigned char buf[3], * p = in, pad = 0;

	*err = 0;
	while (!pad) {
		switch ((x = b64_revert_table[*p++])) {
		case -3: /* NULL TERMINATOR */
			if (((p-1)-in) % 4) *err = 1;
			return result;
		case -2: /* PADDING CHARACTER. INVALID HERE */
			if (((p-1)-in) % 4 < 2) {
				*err = 1;
				return result;
			}
			else if (((p-1)-in) % 4 == 2) {
				/* Make sure there's appropriate padding */
				if (*p != '=') {
					*err = 1;
					return result;
				}
				buf[2] = 0;
				pad = 2;
				result++;
				break;
			}
			else {
				pad = 1;
				result += 2;
				break;
			}
			return result;
		case -1:
			if (strict) {
				*err = 2;
				return result;
			}
			break;
		default:
			switch (((p-1)-in) % 4) {
			case 0:
				buf[0] = x << 2;
				break;
			case 1:
				buf[0] |= (x >> 4);
				buf[1] = x << 4;
				break;
			case 2:
				buf[1] |= (x >> 2);
				buf[2] = x << 6;
				break;
			case 3:
				buf[2] |= x;
				result += 3;
				for (x = 0; x < 3-pad; x++) *out++ = buf[x];
				break;
			}
			break;
		}
	}
	for (x = 0; x < 3-pad; x++) *out++ = buf[x];
	return result;
}

unsigned char* base64_decode(unsigned char* buf, size_t* len, int strict,
		int* err)
{
	unsigned char* outbuf;

	outbuf = (unsigned char*)malloc(3 * (std::strlen(reinterpret_cast<const char*>(buf)) / 4+1));
	if (!outbuf) {
		*err = -3;
		*len = 0;
		return nullptr;
	}
	*len = raw_base64_decode(buf, outbuf, strict, err);
	if (*err) {
		free(outbuf);
		*len = 0;
		outbuf = nullptr;
	}
	return outbuf;
}

}

namespace OwnPass::Crypto {

	std::string Base64Encoder::encode(const std::vector<uint8_t>& plain_buffer)
	{
		auto encoded_c_str = ::base64_encode((unsigned char*)plain_buffer.data(), plain_buffer.size(), 0);
		std::string encoded_str{ reinterpret_cast<const char*>(encoded_c_str) };
		free(encoded_c_str);
		return encoded_str;
	}

	std::vector<uint8_t> Base64Encoder::decode(const std::string& encoded_str)
	{
		int decode_error = 0;
		size_t decode_length = 0;
		auto decoded_c_str = ::base64_decode((unsigned char*)encoded_str.c_str(), &decode_length, 1, &decode_error);
		if (decode_error) {
			if (decoded_c_str) free(decoded_c_str);
			throw std::runtime_error("base64 decode error");
		}
		std::vector<uint8_t> decoded_buffer;
		decoded_buffer.reserve(decode_length);
		for (auto i = 0; i < decode_length; i++)
			decoded_buffer.push_back(decoded_c_str[i]);
		free(decoded_c_str);
		return decoded_buffer;
	}

}
