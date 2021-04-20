//
// Created by Marco Bassaletti on 19-04-21.
//

#include "../catch.hpp"
#include "../../src/NSPass.h"
#include "../../src/Application.h"
#include "../SampleStorageFixture.h"
#include "../../src/commands/CreateGroupCommand.h"

using NSPass::IdGenerator;
using NSPass::Application;
using NSPass::GroupPtr;
using NSPass::Commands::CreateGroupCommand;

class CreateGroupCommandFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[create group command]";
	CreateGroupCommandFixture() = default;
};

TEST_CASE_METHOD(CreateGroupCommandFixture, "CreateGroupCommand - construct", CreateGroupCommandFixture::Tag)
{
	CreateGroupCommand::CreateData create_data;
	REQUIRE_NOTHROW(CreateGroupCommand{ Application::instance(), create_data });
}

TEST_CASE_METHOD(CreateGroupCommandFixture, "CreateGroupCommand - execute", CreateGroupCommandFixture::Tag)
{
	reset_sample_storage();
	auto& app = Application::instance();
	auto category = get_random_category();
	CreateGroupCommand::CreateData create_data;
	create_data.category_id = category->get_id();
	create_data.name = "New Group";
	create_data.url = "https://group-url.test.com";
	create_data.description = "Updated Description";
	size_t invoke_count = 0;
	CreateGroupCommand create_group_command{ Application::instance(), create_data };
	app.get_signal_context().get_group_created().connect([&](const GroupPtr& created_group) {
		auto created_group_ptr = create_group_command.get_created_group();
		auto created_group2 = created_group_ptr.lock();
		REQUIRE(created_group2);
		REQUIRE(created_group->get_id() == created_group2->get_id());
		invoke_count++;
	});
	REQUIRE_NOTHROW(create_group_command.execute());
	REQUIRE(invoke_count == 1);
	auto created_group_ptr = create_group_command.get_created_group();
	auto created_group = created_group_ptr.lock();
	REQUIRE(created_group);
	REQUIRE(created_group->get_name() == create_data.name);
	REQUIRE(created_group->get_url() == create_data.url);
	REQUIRE(created_group->get_description() == create_data.description);
}
