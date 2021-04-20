//
// Created by Marco Bassaletti on 19-04-21.
//
#include "../catch.hpp"
#include "../../src/NSPass.h"
#include "../SampleStorageFixture.h"
#include "../../src/query/GroupQuery.h"
#include "../../src/query/GroupNotFoundException.h"
#include "../../src/commands/DeleteGroupCommand.h"

using namespace std;
using NSPass::Application;
using NSPass::ApplicationException;
using NSPass::IdGenerator;
using NSPass::GroupPtr;
using NSPass::Query::GroupQuery;
using NSPass::Query::GroupNotFoundException;
using NSPass::Commands::DeleteGroupCommand;

class DeleteGroupCommandFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[delete group command]";
	DeleteGroupCommandFixture() = default;
};

TEST_CASE_METHOD(DeleteGroupCommandFixture, "DeleteGroupCommand - Construct", DeleteGroupCommandFixture::Tag)
{
	reset_sample_storage();
	auto group_id = IdGenerator::make();
	REQUIRE_NOTHROW(DeleteGroupCommand{ app, group_id });
}

TEST_CASE_METHOD(DeleteGroupCommandFixture, "DeleteGroupCommand - Delete by id",
		DeleteGroupCommandFixture::Tag)
{
	size_t passes = 5;
	while (passes-- > 0) {
		reset_sample_storage();
		auto category = get_random_category();
		auto group = get_random_group(category);
		size_t signal_invoke_count = 0;
		get_signal_context().get_group_deleted().connect([&](const GroupPtr& deleted_group) {
			REQUIRE(deleted_group->get_id() == group->get_id());
			signal_invoke_count++;
		});
		DeleteGroupCommand delete_group_command{ app, group->get_id() };
		REQUIRE_NOTHROW(delete_group_command.execute());
		REQUIRE(signal_invoke_count > 0);
		GroupQuery group_query{ get_storage() };
		REQUIRE_THROWS_AS(group_query.find(group->get_id()), GroupNotFoundException);
	}
}

TEST_CASE_METHOD(DeleteGroupCommandFixture, "DeleteGroupCommand - Password not found",
		DeleteGroupCommandFixture::Tag)
{
	reset_sample_storage();
	auto group_id = IdGenerator::make();
	DeleteGroupCommand delete_group_command{ app, group_id };
	REQUIRE_THROWS_AS(delete_group_command.execute(), GroupNotFoundException);
}
