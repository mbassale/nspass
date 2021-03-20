//
// Created by Marco Bassaletti on 18-03-21.
//

#ifndef OWNPASS_HELPCOMMAND_H
#define OWNPASS_HELPCOMMAND_H

#include "Command.h"
#include <boost/program_options.hpp>

namespace OwnPass::Commands {
	class HelpCommand : public Command {
	public:
		static constexpr auto Name = "help";
		explicit HelpCommand(OwnPass::Application& app, const boost::program_options::options_description& opt_desc)
				:Command(app), opt_desc{ opt_desc } { };
		~HelpCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return false; }
		void execute() override;
		void undo() override;
	private:
		const boost::program_options::options_description& opt_desc;
	};
}

#endif //OWNPASS_HELPCOMMAND_H
