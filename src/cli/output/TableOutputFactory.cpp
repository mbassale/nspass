//
// Created by Marco Bassaletti on 29-03-21.
//

#include "TableOutputFactory.h"

namespace NSPass::CLI::Output {
	StreamTableOutput TableOutputFactory::create(const StreamTableOutputOptions& options,
			const std::vector<std::string>& headers)
	{
		StreamTableOutput out{ options, headers };
		return out;
	}

	CSVTableOutput TableOutputFactory::create(const CSVTableOutputOptions& options,
			const std::vector<std::string>& headers)
	{
		CSVTableOutput out{ options, headers };
		return out;
	}
}
