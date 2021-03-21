//
// Created by Marco Bassaletti on 17-03-21.
//

#include <optional>
#include "CreateCommand.h"

namespace OwnPass::Commands {
	using namespace std;

	void CreateCommand::execute()
	{
		auto category_obj = find_or_create_category();
		auto group_obj = find_or_create_group(category_obj);
		// TODO: we should have a second master pass or pin to encrypt this password.
		auto password_obj = PasswordFactory::make(username,
				SecureString::FromPlainText(username, password), url, description);
		group_obj.add_password(password_obj);
		category_obj.save_group(group_obj);
		get_storage().save_category(category_obj);
		category_id = category_obj.get_id();
		password_id = password_obj.get_id();
		group_id = group_obj.get_id();
	}

	void CreateCommand::undo()
	{
		if (category_id.is_nil() || group_id.is_nil() || password_id.is_nil()) return;
		auto category_opt = get_storage().find_category(category_id);
		if (category_opt.has_value()) {
			auto group_opt = category_opt.value().get().find_group(group_id);
		}
	}

	Category CreateCommand::find_or_create_category()
	{
		auto category_opt = get_storage().find_category(category);
		if (category_opt.has_value())
			return category_opt->get();
		return Category{ category };
	}

	Group CreateCommand::find_or_create_group(Category& category_obj)
	{
		optional<GroupRef> group_opt;
		if (site.length() > 0) {
			group_opt = category_obj.find_group(site);
			if (group_opt.has_value())
				return group_opt->get();
			return GroupFactory::make_site(site);
		}
		else if (application.length() > 0) {
			group_opt = category_obj.find_group(application);
			if (group_opt.has_value())
				return group_opt->get();
			return GroupFactory::make_application(application);
		}
		throw ApplicationException{ "Attempt to store password without associated site or application." };
	}
}
