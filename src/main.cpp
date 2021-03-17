#include <stdexcept>
#include <boost/log/trivial.hpp>
#include "CommandLine.h"

using OwnPass::CommandLine;

int main(int argc, char* argv[])
{
	try {
		CommandLine command_line{ argc, argv };
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
