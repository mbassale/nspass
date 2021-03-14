//
// Created by Marco Bassaletti on 13-03-21.
//

#include <string>
#include "StringCrypto.h"
#include "SecureString.h"

namespace OwnPass::Crypto {
	using namespace std;

	string_view SecureString::get_plain_text(string_view shared_key)
	{
		StringCrypto string_crypto{ shared_key };
		plain_text = string_crypto.decrypt(cipher_text);
		return plain_text;
	}

}
