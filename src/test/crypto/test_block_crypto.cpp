//
// Created by Marco Bassaletti on 11-03-21.
//

#include <string>
#include <vector>
#include "../catch.hpp"
#include "../../crypto/BlockCrypto.h"
#include "../../crypto/InitializationVector.h"

using namespace std;
using namespace OwnPass::Crypto;

class BlockCryptoFixture {
public:
	BlockCryptoFixture()
	{

	}

protected:
	vector<uint8_t> create_block_from_string(BlockCrypto& block_crypto, const std::string& str)
	{
		auto block_length = block_crypto.pad_length(str.size());
		vector<uint8_t> block;
		block.resize(block_length, 0);
		memcpy(block.data(), str.data(), str.size());
		return block;
	}

	void assert_encrypt(BlockCrypto& block_crypto, const std::string& expected, const std::string& plain_text)
	{
		auto plain_block = create_block_from_string(block_crypto, expected);
		auto cipher_block = block_crypto.encrypt(plain_block);
		auto result_block = block_crypto.decrypt(cipher_block);
		REQUIRE(plain_block == result_block);
	}
};

TEST_CASE_METHOD(BlockCryptoFixture, "constructor")
{
	vector<uint8_t> init_vector = InitializationVectorFactory::make(BlockCrypto::get_block_length());
	REQUIRE_THROWS_AS((BlockCrypto{ "", init_vector }), KeyLengthError);
	REQUIRE_THROWS_AS((BlockCrypto{ "test1234", init_vector }), KeyLengthError);
	REQUIRE_NOTHROW((BlockCrypto{ "one test AES key", init_vector }));
	REQUIRE_NOTHROW((BlockCrypto{ "one test AES keyone test AES key", init_vector }));
}

TEST_CASE_METHOD(BlockCryptoFixture, "encrypt and decrypt")
{
	vector<uint8_t> init_vector = InitializationVectorFactory::make(BlockCrypto::get_block_length());
	BlockCrypto string_crypto{ "two test AES key", init_vector };
	assert_encrypt(string_crypto, "", "");
	assert_encrypt(string_crypto, " ", " ");
	assert_encrypt(string_crypto, "a", "a");
	assert_encrypt(string_crypto, "123456789 abcdefghijklmnopqrstuvwzyz ABCDEFGHIJKLMNOPQRSTUVWZYZ",
			"123456789 abcdefghijklmnopqrstuvwzyz ABCDEFGHIJKLMNOPQRSTUVWZYZ");
}
