//
// Created by Marco Bassaletti on 29-03-21.
//

#include "TableOutputFactory.h"

namespace OwnPass::CLI::Output {
	StreamTableOutput TableOutputFactory::create(const StreamTableOutputOptions& options, const std::vector<std::string>& headers)
	{
		StreamTableOutput out{ options, headers };
		return out;
	}
}
