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
		auto password_obj = PasswordFactory::make(group_obj, username,
				SecureString::FromPlainText(username, password), url, description);
		group_obj.add_password(password_obj);
		category_obj.save_group(group_obj);
		app.get_vault().get_storage().save_category(category_obj);
	}

	void CreateCommand::undo()
	{
		
	}

	Category CreateCommand::find_or_create_category()
	{
		auto& storage = app.get_vault().get_storage();
		auto category_opt = storage.find_category(category);
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
