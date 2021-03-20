//
// Created by Marco Bassaletti on 12-03-21.
//

#include <string>
#include "../catch.hpp"
#include "../../src/crypto/StringCrypto.h"

using namespace std;
using namespace OwnPass::Crypto;

constexpr auto LoremIpsumText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt"
								" ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation "
								"ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
								"reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur "
								"sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id "
								"est laborum.";

class StringCryptoFixture {
public:
	StringCryptoFixture()
	{
	}

protected:
	void assert_encrypt(StringCrypto& string_crypto, const std::string& str)
	{
		auto encrypted_str = string_crypto.encrypt(str);
		auto decrypted_str = string_crypto.decrypt(encrypted_str);
		REQUIRE(decrypted_str == str);
	}

	void assert_encrypt(StringCrypto& encrypt_crypto, StringCrypto& decrypt_crypto, const std::string& str)
	{
		auto encrypted_str = encrypt_crypto.encrypt(str);
		auto decrypted_str = decrypt_crypto.decrypt(encrypted_str);
		REQUIRE(decrypted_str == str);
	}
};

TEST_CASE_METHOD(StringCryptoFixture, "string encrypt/decrypt same initialization vector")
{
	StringCrypto string_crypto{ "test" };
	assert_encrypt(string_crypto, "");
	assert_encrypt(string_crypto, " ");
	assert_encrypt(string_crypto, "    ");
	assert_encrypt(string_crypto, "test 1234 test 1234");
	assert_encrypt(string_crypto, "123456789 abcdefghijklmnopqrstuvwzyz ABCDEFGHIJKLMNOPQRSTUVWZYZ");
	assert_encrypt(string_crypto, LoremIpsumText);
}

TEST_CASE_METHOD(StringCryptoFixture, "string encrypt/decrypt different initialization vector")
{
	StringCrypto string_crypto1{ "test" };
	StringCrypto string_crypto2{ "test" };
	assert_encrypt(string_crypto1, string_crypto2, "");
	assert_encrypt(string_crypto1, string_crypto2, " ");
	assert_encrypt(string_crypto1, string_crypto2, "    ");
	assert_encrypt(string_crypto1, string_crypto2, "test 1234 test 1234");
	assert_encrypt(string_crypto1, string_crypto2, "123456789 abcdefghijklmnopqrstuvwzyz ABCDEFGHIJKLMNOPQRSTUVWZYZ");
	assert_encrypt(string_crypto1, string_crypto2, LoremIpsumText);
}
