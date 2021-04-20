//
// Created by Marco Bassaletti on 20-04-21.
//

#ifndef NSPASS_CREATECATEGORYCOMMAND_H
#define NSPASS_CREATECATEGORYCOMMAND_H

#include "../NSPass.h"
#include "Command.h"

namespace NSPass::Commands {
	class CreateCategoryCommand : public Command {
	public:
		static constexpr auto Name = "create-category";

		CreateCategoryCommand(Application& app, std::string_view name)
				:Command(app), name{ name } { }
		~CreateCategoryCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }

		[[nodiscard]] CategoryWeakPtr get_created_category() { return created_category; }

		void execute() override;
		void undo() override;

	protected:
		std::string name;
		CategoryWeakPtr created_category{};
	};
}

#endif //NSPASS_CREATECATEGORYCOMMAND_H
