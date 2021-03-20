#include <stdexcept>
#include <boost/log/trivial.hpp>
#include "./cli/CommandLine.h"
#include "./cli/input/PromptSecretInput.h"

using OwnPass::CLI::CommandLine;
using OwnPass::CLI::Input::PromptSecretInput;

int main(int argc, char* argv[])
{
	try {
		PromptSecretInput prompt_secret_input{};
		CommandLine command_line{ argc, argv, prompt_secret_input };
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
