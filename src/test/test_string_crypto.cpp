//
// Created by Marco Bassaletti on 11-03-21.
//
#include "catch.hpp"
#include "../crypto/StringCrypto.h"
#include <iostream>

using namespace std;
using namespace OwnPass::Crypto;

class StringCryptoFixture {
public:
	StringCryptoFixture()
	{

	}

	void assert_encrypt(StringCrypto& string_crypto, const std::string& expected, const std::string& plain_text)
	{
		EncryptedBuffer buffer = string_crypto.encrypt(plain_text);
		string result_text = string_crypto.decrypt(buffer);
		REQUIRE(expected == result_text);
	}
};

TEST_CASE_METHOD(StringCryptoFixture, "constructor")
{
	StringCrypto string_crypto{ "one test AES key" };
}

TEST_CASE_METHOD(StringCryptoFixture, "encrypt and decrypt")
{
	StringCrypto string_crypto{ "two test AES key" };
	assert_encrypt(string_crypto, "", "");
	assert_encrypt(string_crypto, " ", " ");
	assert_encrypt(string_crypto, "a", "a");
	assert_encrypt(string_crypto, "123456789 abcdefghijklmnopqrstuvwzyz ABCDEFGHIJKLMNOPQRSTUVWZYZ", "123456789 abcdefghijklmnopqrstuvwzyz ABCDEFGHIJKLMNOPQRSTUVWZYZ");
}
