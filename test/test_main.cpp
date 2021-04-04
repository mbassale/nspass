//
// Created by Marco Bassaletti on 15-03-21.
//
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "../src/Application.h"

using NSPass::Application;

int main( int argc, char* argv[] ) {
	auto& app = Application::instance();
	app.config(Application::LogMode::VERBOSE);

	// global initialization
	app.init();

	int result = Catch::Session().run( argc, argv );

	// global clean-up
	app.cleanup();

	return result;
}
