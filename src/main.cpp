#include <stdexcept>
#include <boost/log/trivial.hpp>
#include "Application.h"
#include "./cli/CommandLine.h"
#include "./cli/input/PromptSecretInput.h"
#include "./cli/input/PromptConfirmInput.h"

using NSPass::Application;
using NSPass::CLI::CommandLine;
using NSPass::CLI::Input::PromptSecretInput;
using NSPass::CLI::Input::PromptConfirmInput;

int main(int argc, char* argv[])
{
	try {
		auto& app = Application::instance();
		app.register_init([&]{
			app.get_vault().set_storage_location(app.get_settings().get_data_directory() + "/nspass.db");
		});
		PromptSecretInput prompt_secret_input{};
		PromptConfirmInput prompt_confirm_input{};
		CommandLine command_line{ argc, argv, prompt_secret_input, prompt_confirm_input };
		return command_line.run();
	}
	catch (std::runtime_error& err) {
		BOOST_LOG_TRIVIAL(fatal) << "Runtime Error: " << err.what() << std::endl;
	}
	catch (std::exception& ex) {
		BOOST_LOG_TRIVIAL(fatal) << "Error: " << ex.what() << std::endl;
	}
	catch (...) {
		BOOST_LOG_TRIVIAL(fatal) << "Unknown failure occurred." << std::endl;
	}
	return -1;
}
