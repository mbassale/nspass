//
// Created by Marco Bassaletti on 15-03-21.
//
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include "../catch.hpp"
#include "../../src/crypto/StringCrypto.h"
#include "../../src/crypto/EncryptedFile.h"

using namespace std;
using namespace NSPass::Crypto;

class EncryptedFileFixture {
public:
	EncryptedFileFixture() = default;
};

const auto LoremIpsumText = R"(Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
)";

TEST_CASE_METHOD(EncryptedFileFixture, "encrypted file constructor")
{
	REQUIRE_NOTHROW((EncryptedFile{ "test_encrypted_file.dat", "test1234" }));
}

TEST_CASE_METHOD(EncryptedFileFixture, "encrypted file correctness")
{
	auto filename = "test_encrypted_file.dat";
	auto shared_key = "test1234";
	EncryptedFile encrypted_file{ filename, shared_key };
	encrypted_file.encrypt(LoremIpsumText);

	ifstream infile(filename, ios::binary | ios::in);
	REQUIRE(infile.is_open());
	std::stringstream in_str_stream;
	in_str_stream << infile.rdbuf();
	auto encrypted_contents = in_str_stream.str();
	REQUIRE_FALSE(encrypted_contents == LoremIpsumText);
	StringCrypto string_crypto{ shared_key };
	auto contents = string_crypto.decrypt(encrypted_contents);
	REQUIRE(contents == LoremIpsumText);
	if (std::filesystem::exists(filename))
		std::filesystem::remove(filename);
}

TEST_CASE_METHOD(EncryptedFileFixture, "encrypt/decrypt file")
{
	auto filename = "encrypted_file.dat";
	auto shared_key = "test1234";
	EncryptedFile encrypted_file{ filename, shared_key };
	encrypted_file.encrypt(LoremIpsumText);
	REQUIRE(LoremIpsumText == encrypted_file.decrypt());
	if (std::filesystem::exists(filename))
		std::filesystem::remove(filename);
}
