//
// Created by Marco Bassaletti on 17-03-21.
//
#include "../NSPass.h"
#include "../query/CategoryQuery.h"
#include "../query/GroupQuery.h"
#include "CreatePasswordCommand.h"

namespace NSPass::Commands {
	using namespace std;
	using NSPass::Query::CategoryQuery;
	using NSPass::Query::GroupQuery;

	void CreatePasswordCommand::execute()
	{
		auto category_obj = find_or_create_category();
		auto group_obj = find_or_create_group(category_obj);
		// TODO: we should have a second master pass or pin to encrypt this password.
		auto password_ptr = PasswordFactory::make(create_data.username,
				SecureString::FromPlainText(create_data.username, create_data.password), create_data.url,
				create_data.description);
		group_obj->add_password(password_ptr);
		category_obj->save_group(group_obj);
		get_storage().save_category(category_obj);
		get_storage().flush();
		category_id = category_obj->get_id();
		password_id = password_ptr->get_id();
		group_id = group_obj->get_id();
		(get_signal_context().get_password_created())(password_ptr);
	}

	void CreatePasswordCommand::undo()
	{
		if (category_id.is_nil() || group_id.is_nil() || password_id.is_nil()) return;
		auto category_obj = get_storage().find_category(category_id);
		if (category_obj) {
			auto group_obj = category_obj->find_group(group_id);
			if (group_obj) {
				auto password_ptr = group_obj->find_password(password_id);
				if (password_ptr) {
					group_obj->remove_password(password_ptr);
				}
			}
		}
	}

	CategoryPtr CreatePasswordCommand::find_or_create_category()
	{
		if (!create_data.category_id.is_nil()) {
			CategoryQuery category_query{ get_storage() };
			return category_query.find(create_data.category_id);
		}
		CategoryQuery category_query{ get_storage(), create_data.category };
		auto categories = category_query.find();
		if (!categories.empty()) {
			return categories.front();
		}
		return CategoryFactory::make(create_data.category);
	}

	GroupPtr CreatePasswordCommand::find_or_create_group(CategoryPtr& category_obj)
	{
		if (!create_data.group_id.is_nil()) {
			GroupQuery group_query{ get_storage() };
			return group_query.find(create_data.group_id).group;
		}
		GroupQuery::QueryArguments args;
		args.category_search = create_data.category;
		args.search = create_data.site.empty() ? create_data.application : create_data.site;
		GroupQuery group_query{ get_storage(), args };
		auto groups = group_query.find();
		if (!groups.empty()) {
			return groups.front().group;
		}
		if (create_data.site.length() > 0) {
			return GroupFactory::make_site(create_data.site);
		}
		else if (create_data.application.length() > 0) {
			return GroupFactory::make_application(create_data.application);
		}
		throw ApplicationException{ "Attempt to store password without associated site or application." };
	}
}
