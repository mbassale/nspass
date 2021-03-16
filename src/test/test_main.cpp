//
// Created by Marco Bassaletti on 15-03-21.
//
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <gcrypt.h>

int main( int argc, char* argv[] ) {
	/* http://lists.gnupg.org/pipermail/gcrypt-devel/2003-August/000458.html
		 * Because you can't know in a library whether another library has
		 * already initialized the library
		 */
	if (!gcry_control(GCRYCTL_ANY_INITIALIZATION_P)) {
		gcry_check_version(NULL); /* before calling any other functions */
	}

	int result = Catch::Session().run( argc, argv );

	// global clean-up...

	return result;
}
