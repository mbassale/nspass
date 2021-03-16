//
// Created by Marco Bassaletti on 15-03-21.
//

#include <gcrypt.h>
#include "InitCrypto.h"
#include <iostream>

namespace OwnPass::Crypto {

	InitCrypto init_crypto;

	InitCrypto::InitCrypto()
	{
		auto& app = Application::instance();
		std::cout << "Registering crypto initialization." << std::endl;
		app.register_init([] {
			/* http://lists.gnupg.org/pipermail/gcrypt-devel/2003-August/000458.html
			 * Because you can't know in a library whether another library has
			 * already initialized the library
			 */
			if (!gcry_control(GCRYCTL_ANY_INITIALIZATION_P)) {
				gcry_check_version(NULL); /* before calling any other functions */
			}
		});
	}
}
