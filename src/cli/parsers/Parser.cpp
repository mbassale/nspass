//
// Created by Marco Bassaletti on 18-03-21.
//

#include <sstream>
#include <string>
#include <boost/program_options.hpp>
#include "Parser.h"

namespace NSPass::CLI::Parsers {
	using namespace std;
	namespace po = boost::program_options;

	string Parser::format_error(string_view reason, const po::options_description& opt_desc)
	{
		ostringstream error_message;
		error_message << "Error: " << reason << std::endl << opt_desc << std::endl;
		return error_message.str();
	}
}
