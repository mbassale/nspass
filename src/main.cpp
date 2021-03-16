#include <boost/program_options.hpp>
#include "Application.h"

using OwnPass::Application;

int main()
{
	auto& app = Application::instance();
	app.config(Application::LogMode::NORMAL);

	// global initialization
	app.init();

	// global clean-up
	app.cleanup();

	return 0;
}
