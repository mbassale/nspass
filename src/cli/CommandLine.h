//
// Created by Marco Bassaletti on 16-03-21.
//

#ifndef OWNPASS_COMMANDLINE_H
#define OWNPASS_COMMANDLINE_H

#include <string>
#include <vector>
#include <boost/program_options.hpp>

namespace OwnPass::CLI {
	class CommandLine {
	public:
		CommandLine(int argc, char** argv);
		int run();
	private:
		int argc;
		char** argv;
	};
}

#endif //OWNPASS_COMMANDLINE_H
