//
// Created by Marco Bassaletti on 28-03-21.
//

#ifndef OWNPASS_TABLEOUTPUT_H
#define OWNPASS_TABLEOUTPUT_H

#include "../../OwnPass.h"

namespace OwnPass::CLI::Output {

	struct TableOutputOptions {
	public:
		size_t max_column_width = 0;
		size_t max_rows = 0;
		std::ostream& out;

		TableOutputOptions(std::ostream& out, size_t max_column_width, size_t max_rows)
				:out{ out }, max_column_width{ max_column_width }, max_rows{ max_rows } { }
	};

	class TableOutput {
	public:
		explicit TableOutput(const TableOutputOptions& options, std::vector<std::string>  headers);
		void print_headers();
		void print_row(const std::vector<std::string>& row);
	protected:
		TableOutputOptions options;
		std::vector<std::string> headers;
		size_t get_max_column_width();
	};
}

#endif //OWNPASS_TABLEOUTPUT_H
