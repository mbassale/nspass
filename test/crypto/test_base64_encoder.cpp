//
// Created by Marco Bassaletti on 12-03-21.
//

#include "../catch.hpp"
#include "../../src/crypto/Base64Encoder.h"

using namespace std;
using namespace OwnPass::Crypto;

constexpr auto LoremIpsumText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt"
							 " ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation "
							 "ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
							 "reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur "
							 "sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id "
							 "est laborum.";

class Base64EncoderFixture {
public:
	Base64EncoderFixture()
	{

	}
protected:
	vector<uint8_t> string2buffer(const std::string& str)
	{
		vector<uint8_t> buffer;
		buffer.reserve(str.length());
		for (char i : str)
			buffer.push_back(i);
		return buffer;
	}

	void assert_decode(const std::string& str)
	{
		auto encoded_string = Base64Encoder::encode(string2buffer(str));
		auto decoded_buffer = Base64Encoder::decode(encoded_string);
		REQUIRE(decoded_buffer == string2buffer(str));
	}
};

TEST_CASE_METHOD(Base64EncoderFixture, "base64 encode/decode")
{
	assert_decode("");
	assert_decode(" ");
	assert_decode("    ");
	assert_decode("1234567890");
	assert_decode(LoremIpsumText);
}
