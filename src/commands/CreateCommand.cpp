//
// Created by Marco Bassaletti on 17-03-21.
//

#include <optional>
#include "CreateCommand.h"

namespace OwnPass::Commands {
	using namespace std;

	void CreateCommand::execute()
	{
		auto category_ptr = find_or_create_category();
		auto group_obj = find_or_create_group(category_ptr);
		auto password_obj = PasswordFactory::make(*group_obj, username,
				SecureString::FromPlainText(username, password), url, description);
		group_obj->add_password(password_obj);
		category_ptr->save_group(group_obj);
		app.get_vault().get_storage().save_category(category_ptr);
	}

	void CreateCommand::undo()
	{
		
	}

	CategoryPtr CreateCommand::find_or_create_category()
	{
		auto& storage = app.get_vault().get_storage();
		auto category_opt = storage.find_category(category);
		if (category_opt.has_value())
			return category_opt.value();
		return std::make_shared<Category>(category);
	}

	GroupPtr CreateCommand::find_or_create_group(CategoryPtr& category_obj)
	{
		GroupPtr group_ptr;
		if (site.length() > 0) {
			group_ptr = category_obj->find_group(site);
			if (group_ptr)
				return group_ptr;
			return GroupFactory::make_site(site);
		}
		else if (application.length() > 0) {
			group_ptr = category_obj->find_group(application);
			if (group_ptr)
				return group_ptr;
			return GroupFactory::make_application(application);
		}
		throw ApplicationException{ "Attempt to store password without associated site or application." };
	}
}
