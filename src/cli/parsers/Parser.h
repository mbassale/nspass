//
// Created by Marco Bassaletti on 18-03-21.
//

#ifndef OWNPASS_PARSER_H
#define OWNPASS_PARSER_H

#include <boost/program_options.hpp>
#include "../../Application.h"
#include "../../commands/Command.h"
namespace OwnPass::CLI::Parsers {
	class Parser {
	public:
		Parser(OwnPass::Application& app, boost::program_options::parsed_options& parsed,
				boost::program_options::variables_map& vm)
				:app{ app }, parsed{ parsed }, vm{ vm } { }
		virtual ~Parser() = default;

	protected:
		OwnPass::Application& app;
		boost::program_options::parsed_options& parsed;
		boost::program_options::variables_map& vm;
		std::string format_error(std::string_view error_message, const boost::program_options::options_description& opt_desc);
	};

}

#endif //OWNPASS_PARSER_H
