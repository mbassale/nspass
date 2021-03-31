//
// Created by Marco Bassaletti on 30-03-21.
//

#ifndef OWNPASS_LISTCOMMAND_H
#define OWNPASS_LISTCOMMAND_H

#include "../OwnPass.h"
#include "Command.h"

#include <utility>
#include "../cli/output/TableOutput.h"

namespace OwnPass::Commands {
	class ListCommand : public Command {
	public:
		enum class Format {
			STDOUT = 1,
			CSV
		};
		static constexpr auto MaxColumnWidth = 32;
		explicit ListCommand(OwnPass::Application& app, Format format, std::string filter = std::string())
				:Command{ app }, format{ format }, filter{ std::move(filter) } { };

		[[nodiscard]] Format get_format() { return format; }
	protected:
		Format format;
		std::string filter;

		OwnPass::CLI::Output::TableOutputPtr create_table_output(const std::vector<std::string>& headers);
	};
}

#endif //OWNPASS_LISTCOMMAND_H
