//
// Created by Marco Bassaletti on 01-04-21.
//

#ifndef OWNPASS_IMPORTLASTPASSCOMMAND_H
#define OWNPASS_IMPORTLASTPASSCOMMAND_H

#include "../NSPass.h"
#include "Command.h"

namespace NSPass::Commands {
	class ImportLastPassCommand : public Command {
	public:
		struct ImportErrors {
			size_t line;
			std::string error;
			ImportErrors(size_t line, std::string_view error)
					:line{ line }, error{ error } { }
		};
		static constexpr auto Name = "copy-password";
		ImportLastPassCommand(NSPass::Application& app, std::string filename)
				:Command(app), filename{ std::move(filename) } { };
		~ImportLastPassCommand() override = default;

		std::string_view get_name() override { return Name; }
		bool requires_master_password() override { return true; }
		bool requires_confirmation() override { return true; }

		[[nodiscard]] std::string_view get_filename() const { return filename; }

		[[nodiscard]] const std::vector<CategoryWeakPtr>& get_imported_categories() const { return imported_categories; }
		[[nodiscard]] const std::vector<GroupWeakPtr>& get_imported_groups() const { return imported_groups; }
		[[nodiscard]] const std::vector<PasswordWeakPtr>& get_imported_passwords() const { return imported_passwords; }
		[[nodiscard]] const std::vector<ImportErrors>& get_errors() const { return errors; }
		[[nodiscard]] bool has_errors() const { return !errors.empty(); }

		void execute() override;
		void undo() override;
	protected:
		struct ImportItem {
			std::string url;
			std::string username;
			std::string password;
			std::string extra;
			std::string site_name;
			std::string category_name;
		};

		std::string filename;
		std::vector<CategoryWeakPtr> imported_categories;
		std::vector<GroupWeakPtr> imported_groups;
		std::vector<PasswordWeakPtr> imported_passwords;
		std::vector<ImportErrors> errors;

		void import_item(const ImportItem& item);
		CategoryPtr find_or_create_category(std::string_view category_name);
		static GroupPtr find_or_create_group(const CategoryPtr& category, GroupType group_type,
				std::string_view group_name);
		static PasswordPtr create_password(const GroupPtr& group, std::string_view username, std::string_view password, std::string_view url);
		void save_imported_category(const CategoryPtr& category);
		void save_imported_group(const GroupPtr& group);
		void save_imported_password(const PasswordPtr& password);
	};
}

#endif //OWNPASS_IMPORTLASTPASSCOMMAND_H
