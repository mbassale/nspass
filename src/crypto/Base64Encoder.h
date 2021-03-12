//
// Created by Marco Bassaletti on 12-03-21.
//

#ifndef OWNPASS_BASE64ENCODER_H
#define OWNPASS_BASE64ENCODER_H

#include <string>

namespace OwnPass::Crypto {
	class Base64Encoder {
	public:
		static std::string encode(const std::string& plain_str);
		static std::string decode(const std::string& encoded_str);
	};
}

#endif //OWNPASS_BASE64ENCODER_H
