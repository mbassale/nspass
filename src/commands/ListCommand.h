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
		struct Filter {
			std::string category_filter;
			std::string group_filter;
			std::string password_filter;
		};
		static const Filter EmptyFilter;

		static constexpr auto MaxColumnWidth = 32;
		explicit ListCommand(OwnPass::Application& app, Format format, Filter filter = EmptyFilter)
				:Command{ app }, format{ format }, filter{ std::move(filter) } { };

		[[nodiscard]] Format get_format() { return format; }
	protected:
		Format format;
		Filter filter;

		OwnPass::CLI::Output::TableOutputPtr create_table_output(const std::vector<std::string>& headers);
	};
}

#endif //OWNPASS_LISTCOMMAND_H
