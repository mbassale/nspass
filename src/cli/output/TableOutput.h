//
// Created by Marco Bassaletti on 28-03-21.
//

#ifndef OWNPASS_TABLEOUTPUT_H
#define OWNPASS_TABLEOUTPUT_H

#include "../../OwnPass.h"

namespace OwnPass::CLI::Output {

	class TableOutput {
	public:
		TableOutput() = default;
		virtual ~TableOutput() = default;

		virtual void print_headers() = 0;
		virtual void print_row(const std::vector<std::string>& row) = 0;
	};
}

#endif //OWNPASS_TABLEOUTPUT_H
