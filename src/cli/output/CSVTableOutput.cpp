//
// Created by Marco Bassaletti on 29-03-21.
//

#include <boost/algorithm/string/join.hpp>
#include "CSVTableOutput.h"

#include <utility>

namespace NSPass::CLI::Output {

	CSVTableOutput::CSVTableOutput(const CSVTableOutputOptions& options, std::vector<std::string> headers)
			:options{ options }, headers{ std::move(headers) }
	{

	}

	void CSVTableOutput::print_headers()
	{
		options.out << boost::algorithm::join(headers, options.column_separator) << std::endl;
	}

	void CSVTableOutput::print_row(const std::vector<std::string>& row)
	{
		options.out << boost::algorithm::join(row, options.column_separator) << std::endl;
	}
}
