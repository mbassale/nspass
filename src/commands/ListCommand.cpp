//
// Created by Marco Bassaletti on 30-03-21.
//
#include "../OwnPass.h"
#include "../cli/output/StreamTableOutput.h"
#include "../cli/output/CSVTableOutput.h"
#include "ListCommand.h"

namespace OwnPass::Commands {
	using OwnPass::CLI::Output::TableOutput;
	using OwnPass::CLI::Output::TableOutputPtr;
	using OwnPass::CLI::Output::StreamTableOutputOptions;
	using OwnPass::CLI::Output::StreamTableOutput;
	using OwnPass::CLI::Output::CSVTableOutputOptions;
	using OwnPass::CLI::Output::CSVTableOutput;

	const ListCommand::Filter ListCommand::EmptyFilter;

	TableOutputPtr ListCommand::create_table_output(const std::vector<std::string>& headers)
	{
		switch (format) {
		case Format::STDOUT: {
			StreamTableOutputOptions options{ std::cout, MaxColumnWidth, 0 };
			return std::make_unique<StreamTableOutput>(options, headers);
		}
		case Format::CSV: {
			CSVTableOutputOptions options{ std::cout };
			return std::make_unique<CSVTableOutput>(options, headers);
		}
		}
	}
}
