//
// Created by Marco Bassaletti on 13-04-21.
//

#ifndef NSPASS_UPDATECATEGORYCOMMAND_H
#define NSPASS_UPDATECATEGORYCOMMAND_H

#include "../NSPass.h"
#include "Command.h"

namespace NSPass::Commands {
	class UpdateCategoryCommand : public Command {
	public:
		struct UpdateData {
			std::optional<std::string> name;
		};

		static constexpr auto Name = "update-category";
		UpdateCategoryCommand(NSPass::Application& app, ObjectId category_id, UpdateData update_data)
				:Command(app), category_id{ category_id }, update_data{ std::move(update_data) } { };
		~UpdateCategoryCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }

		[[nodiscard]] const UpdateData& get_update_data() const { return update_data; }
		[[nodiscard]] const CategoryWeakPtr& get_updated_category() const { return updated_category; }

		void execute() override;
		void undo() override;

	protected:
		ObjectId category_id{};
		UpdateData update_data;
		CategoryWeakPtr updated_category;

		CategoryPtr find_first_category_by_id();
	};
}

#endif //NSPASS_UPDATECATEGORYCOMMAND_H
