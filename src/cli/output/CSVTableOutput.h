//
// Created by Marco Bassaletti on 29-03-21.
//

#ifndef OWNPASS_CSVTABLEOUTPUT_H
#define OWNPASS_CSVTABLEOUTPUT_H

#include "TableOutput.h"

#include <utility>

namespace OwnPass::CLI::Output {
	struct CSVTableOutputOptions {
	public:
		static constexpr auto DefaultColumnSeparator = ",";
		size_t max_rows = 0;
		std::string column_separator = ",";
		std::ostream& out;

		explicit CSVTableOutputOptions(std::ostream& out, size_t max_rows = 0,
				std::string column_separator = DefaultColumnSeparator)
				:out{ out }, max_rows{ max_rows }, column_separator{ std::move(column_separator) } { }
	};

	class CSVTableOutput : public TableOutput {
	public:
		explicit CSVTableOutput(const CSVTableOutputOptions& options, std::vector<std::string> headers);
		~CSVTableOutput() override = default;

		void print_headers() override;
		void print_row(const std::vector<std::string>& row) override;

	protected:
		CSVTableOutputOptions options;
		std::vector<std::string> headers;
	};
}

#endif //OWNPASS_CSVTABLEOUTPUT_H
