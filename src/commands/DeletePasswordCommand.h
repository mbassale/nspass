//
// Created by Marco Bassaletti on 04-04-21.
//

#ifndef OWNPASS_DELETEPASSWORDCOMMAND_H
#define OWNPASS_DELETEPASSWORDCOMMAND_H

#include "../NSPass.h"
#include "Command.h"

namespace NSPass::Commands {
	class DeletePasswordCommand : public Command {
	public:
		struct Filter {
			std::string category_search;
			std::string application_search;
			std::string site_search;
			std::string username_search;
		};
		static constexpr auto Name = "copy-password";
		DeletePasswordCommand(NSPass::Application& app, Filter filter)
				:Command(app), filter{ std::move(filter) } { };
		~DeletePasswordCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		bool requires_confirmation() override { return true; }
		[[nodiscard]] const Filter& get_filter() const { return filter; }

		void execute() override;
		void undo() override;
	protected:
		Filter filter;
	};
}

#endif //OWNPASS_DELETEPASSWORDCOMMAND_H
