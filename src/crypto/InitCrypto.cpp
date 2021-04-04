//
// Created by Marco Bassaletti on 15-03-21.
//

#include <gcrypt.h>
#include "InitCrypto.h"
#include <iomanip>
#include <boost/log/trivial.hpp>

namespace NSPass::Crypto {

	InitCrypto init_crypto;

	InitCrypto::InitCrypto()
	{
		auto& app = Application::instance();
		BOOST_LOG_TRIVIAL(trace) << "Registering crypto initialization... " << std::flush;
		app.register_init([] {
			/* http://lists.gnupg.org/pipermail/gcrypt-devel/2003-August/000458.html
			 * Because you can't know in a library whether another library has
			 * already initialized the library
			 */
			if (!gcry_control(GCRYCTL_ANY_INITIALIZATION_P)) {
				gcry_check_version(nullptr); /* before calling any other functions */
			}
		});
		BOOST_LOG_TRIVIAL(trace) << "Done." << std::endl;
	}
}
