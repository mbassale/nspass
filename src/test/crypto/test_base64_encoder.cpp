//
// Created by Marco Bassaletti on 12-03-21.
//

#include "../catch.hpp"
#include "../../crypto/Base64Encoder.h"
#include <iostream>

using namespace std;
using namespace OwnPass::Crypto;

static auto LoremIpsumText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt"
							 " ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation "
							 "ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
							 "reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur "
							 "sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id "
							 "est laborum.";

static auto LoremIpsumEncodedText =
		"TG9yZW0gaXBzdW0gZG9sb3Igc2l0IGFtZXQsIGNvbnNlY3RldHVyIGFkaXBpc2NpbmcgZWxpdCwgc2VkIGRvIGVpdXNtb2QgdGVtcG9yIGluY2"
		"lkaWR1bnQgdXQgbGFib3JlIGV0IGRvbG9yZSBtYWduYSBhbGlxdWEuIFV0IGVuaW0gYWQgbWluaW0gdmVuaWFtLCBxdWlzIG5vc3RydWQgZXhl"
		"cmNpdGF0aW9uIHVsbGFtY28gbGFib3JpcyBuaXNpIHV0IGFsaXF1aXAgZXggZWEgY29tbW9kbyBjb25zZXF1YXQuIER1aXMgYXV0ZSBpcnVyZS"
		"Bkb2xvciBpbiByZXByZWhlbmRlcml0IGluIHZvbHVwdGF0ZSB2ZWxpdCBlc3NlIGNpbGx1bSBkb2xvcmUgZXUgZnVnaWF0IG51bGxhIHBhcmlh"
		"dHVyLiBFeGNlcHRldXIgc2ludCBvY2NhZWNhdCBjdXBpZGF0YXQgbm9uIHByb2lkZW50LCBzdW50IGluIGN1bHBhIHF1aSBvZmZpY2lhIGRlc2"
		"VydW50IG1vbGxpdCBhbmltIGlkIGVzdCBsYWJvcnVtLg==";

class Base64EncoderFixture {
public:
	Base64EncoderFixture()
	{

	}
protected:
	void assert_decode(const std::string& str)
	{
		REQUIRE(Base64Encoder::decode(Base64Encoder::encode(str)) == str);
	}
};

TEST_CASE_METHOD(Base64EncoderFixture, "encode")
{
	REQUIRE(Base64Encoder::encode("").empty());
	REQUIRE(Base64Encoder::encode(" ") == "IA==");
	REQUIRE(Base64Encoder::encode("    ") == "ICAgIA==");
	REQUIRE(Base64Encoder::encode("1234567890") == "MTIzNDU2Nzg5MA==");
	REQUIRE(Base64Encoder::encode(LoremIpsumText) == LoremIpsumEncodedText);
}

TEST_CASE_METHOD(Base64EncoderFixture, "decode")
{
	assert_decode("");
	assert_decode(" ");
	assert_decode("    ");
	assert_decode("1234567890");
	assert_decode(LoremIpsumText);
}
