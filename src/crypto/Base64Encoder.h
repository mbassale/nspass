//
// Created by Marco Bassaletti on 12-03-21.
//

#ifndef OWNPASS_BASE64ENCODER_H
#define OWNPASS_BASE64ENCODER_H

#include <string>
#include <vector>

namespace OwnPass::Crypto {
	class Base64Encoder {
	public:
		static std::string encode(const std::vector<uint8_t>& plain_buffer);
		static std::vector<uint8_t> decode(const std::string& encoded_str);
	};
}

#endif //OWNPASS_BASE64ENCODER_H
