//
// Created by Marco Bassaletti on 29-03-21.
//

#ifndef OWNPASS_TABLEOUTPUTFACTORY_H
#define OWNPASS_TABLEOUTPUTFACTORY_H

#include "StreamTableOutput.h"
#include "CSVTableOutput.h"

namespace OwnPass::CLI::Output {

	class TableOutputFactory {
	public:
		static StreamTableOutput create(const StreamTableOutputOptions& options, const std::vector<std::string>& headers);
		static CSVTableOutput create(const CSVTableOutputOptions &options, const std::vector<std::string>& headers);

		TableOutputFactory() = delete;
		TableOutputFactory(const TableOutputFactory&) = delete;
		TableOutputFactory(const TableOutputFactory&&) = delete;
	};
}

#endif //OWNPASS_TABLEOUTPUTFACTORY_H
