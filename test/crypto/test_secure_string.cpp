//
// Created by Marco Bassaletti on 14-03-21.
//

#include <string>
#include "../catch.hpp"
#include "../../src/crypto/StringCrypto.h"
#include "../../src/crypto/SecureString.h"

using namespace std;
using namespace NSPass::Crypto;

class SecureStringFixture {
public:
	SecureStringFixture()
	{
	}
protected:
	std::string encrypt_string(string_view shared_key, string_view plain_text)
	{
		StringCrypto string_crypto{ shared_key };
		return string_crypto.encrypt(plain_text);
	}

	void assert_secure_string(string_view shared_key, string_view plain_text)
	{
		auto cipher_text = encrypt_string(shared_key, plain_text);
		auto secure_string = SecureString{ cipher_text };
		REQUIRE(secure_string.get_cipher_text() == cipher_text);
		REQUIRE(secure_string.get_plain_text(shared_key) == plain_text);
	}
};

TEST_CASE_METHOD(SecureStringFixture, "construct secure string")
{
	REQUIRE_NOTHROW(SecureString{""});
	REQUIRE_NOTHROW(SecureString{"test1234"});
	REQUIRE_NOTHROW(SecureString{"lorem ipsum dolor senet"});
}

TEST_CASE_METHOD(SecureStringFixture, "recover cipher text")
{
	REQUIRE((SecureString{""}).get_cipher_text() == "");
	REQUIRE((SecureString{"test1234"}).get_cipher_text() == "test1234");
	REQUIRE((SecureString{"lorem ipsum dolor senet"}).get_cipher_text() == "lorem ipsum dolor senet");
}

TEST_CASE_METHOD(SecureStringFixture, "create with cipher text, recover plain text")
{
	assert_secure_string("test1234", "");
	assert_secure_string("test1234", "test1234");
	assert_secure_string("test1234", "lorem ipsum dolor senet");
	assert_secure_string("lorem ipsum dolor senet", "test1234");
}
