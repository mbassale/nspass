//
// Created by Marco Bassaletti on 29-03-21.
//

#include "StreamTableOutput.h"

namespace NSPass::CLI::Output {
	StreamTableOutput::StreamTableOutput(const StreamTableOutputOptions& options, std::vector<std::string>  headers)
			:options{ options }, headers{std::move( headers )}
	{

	}

	void StreamTableOutput::print_headers()
	{
		auto max_column_width = get_max_column_width();
		for (auto& cell : headers) {
			options.out << std::left << std::setw(max_column_width) << cell << std::setfill(' ');
		}
		options.out << std::endl;
	}

	void StreamTableOutput::print_row(const std::vector<std::string>& row)
	{
		auto max_column_width = get_max_column_width();
		for(auto& cell : row) {
			options.out << std::left << std::setw(max_column_width) << cell << std::setfill(' ');
		}
		options.out << std::endl;
	}

	size_t StreamTableOutput::get_max_column_width()
	{
		size_t max_column_width = options.max_column_width;
		if (max_column_width <= 0) {
			max_column_width = 0;
			for (auto& column : headers)
				max_column_width = std::max<size_t>(column.length(), max_column_width);
		}
		return max_column_width;
	}
}
