//
// Created by Marco Bassaletti on 30-03-21.
//
#include "../NSPass.h"
#include "../cli/output/StreamTableOutput.h"
#include "../cli/output/CSVTableOutput.h"
#include "ListCommand.h"

namespace NSPass::Commands {
	using NSPass::CLI::Output::TableOutput;
	using NSPass::CLI::Output::TableOutputPtr;
	using NSPass::CLI::Output::StreamTableOutputOptions;
	using NSPass::CLI::Output::StreamTableOutput;
	using NSPass::CLI::Output::CSVTableOutputOptions;
	using NSPass::CLI::Output::CSVTableOutput;

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
