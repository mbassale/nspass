//
// Created by Marco Bassaletti on 12-04-21.
//

#include "../catch.hpp"
#include "../../src/NSPass.h"
#include "../../src/Application.h"
#include "../SampleStorageFixture.h"
#include "../../src/commands/UpdateGroupCommand.h"

using NSPass::IdGenerator;
using NSPass::Application;
using NSPass::Commands::UpdateGroupCommand;

class UpdateGroupCommandFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[update group command]";
	UpdateGroupCommandFixture() = default;
};

TEST_CASE_METHOD(UpdateGroupCommandFixture, "UpdateGroupCommand - construct", UpdateGroupCommandFixture::Tag)
{
	UpdateGroupCommand::UpdateData update_data;
	auto group_id = IdGenerator::make();
	REQUIRE_NOTHROW(UpdateGroupCommand{ Application::instance(), group_id, update_data });
}

TEST_CASE_METHOD(UpdateGroupCommandFixture, "UpdateGroupCommand - execute", UpdateGroupCommandFixture::Tag)
{
	reset_sample_storage();
	UpdateGroupCommand::UpdateData update_data;
	update_data.name = "Updated Name";
	update_data.url = "https://updated-url.test.com";
	update_data.description = "Updated Description";
	auto category = get_random_category();
	auto group = get_random_group(category);
	UpdateGroupCommand update_group_command{ Application::instance(), group->get_id(), update_data };
	REQUIRE_NOTHROW(update_group_command.execute());
	auto& updated_group_ptr = update_group_command.get_updated_group();
	auto updated_group = updated_group_ptr.lock();
	REQUIRE(updated_group);
	REQUIRE(updated_group->get_id() == group->get_id());
	REQUIRE(updated_group->get_name() == update_data.name);
	REQUIRE(updated_group->get_url() == update_data.url);
	REQUIRE(updated_group->get_description() == update_data.description);
}
