//
// Created by Marco Bassaletti on 13-03-21.
//

#include <string>
#include "StringCrypto.h"
#include "SecureString.h"

namespace NSPass::Crypto {
	using namespace std;

	string SecureString::get_plain_text(string_view shared_key)
	{
		StringCrypto string_crypto{ shared_key };
		return string_crypto.decrypt(cipher_text);
	}

}
