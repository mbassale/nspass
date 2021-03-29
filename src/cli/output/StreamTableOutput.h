//
// Created by Marco Bassaletti on 29-03-21.
//

#ifndef OWNPASS_STREAMTABLEOUTPUT_H
#define OWNPASS_STREAMTABLEOUTPUT_H

#include "../../OwnPass.h"
#include "TableOutput.h"

namespace OwnPass::CLI::Output {
	struct StreamTableOutputOptions {
	public:
		size_t max_column_width = 0;
		size_t max_rows = 0;
		std::ostream& out;

		StreamTableOutputOptions(std::ostream& out, size_t max_column_width, size_t max_rows)
				:out{ out }, max_column_width{ max_column_width }, max_rows{ max_rows } { }
	};

	class StreamTableOutput : public TableOutput {
	public:
		explicit StreamTableOutput(const StreamTableOutputOptions& options, std::vector<std::string> headers);
		~StreamTableOutput() override = default;

		void print_headers() override;
		void print_row(const std::vector<std::string>& row) override;

	protected:
		StreamTableOutputOptions options;
		std::vector<std::string> headers;
		size_t get_max_column_width();
	};
}

#endif //OWNPASS_STREAMTABLEOUTPUT_H
