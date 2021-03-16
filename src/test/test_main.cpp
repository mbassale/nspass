//
// Created by Marco Bassaletti on 15-03-21.
//
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "../Application.h"

using OwnPass::Application;

int main( int argc, char* argv[] ) {
	auto& app = Application::instance();

	// global initialization
	std::cout << "Initializing... " << std::flush;
	app.init();
	std::cout << "Done." << std::endl;

	int result = Catch::Session().run( argc, argv );

	// global clean-up
	std::cout << "Cleanup... " << std::flush;
	app.cleanup();
	std::cout << "Done." << std::endl;

	return result;
}
