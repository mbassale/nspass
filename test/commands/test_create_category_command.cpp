//
// Created by Marco Bassaletti on 20-04-21.
//

#include "../catch.hpp"
#include "../../src/NSPass.h"
#include "../../src/Application.h"
#include "../SampleStorageFixture.h"
#include "../../src/commands/CreateCategoryCommand.h"

using NSPass::IdGenerator;
using NSPass::Application;
using NSPass::CategoryPtr;
using NSPass::Commands::CreateCategoryCommand;

class CreateCategoryCommandFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[create category command]";
	CreateCategoryCommandFixture() = default;
};

TEST_CASE_METHOD(CreateCategoryCommandFixture, "CreateCategoryCommand - construct", CreateCategoryCommandFixture::Tag)
{
	REQUIRE_NOTHROW(CreateCategoryCommand{ Application::instance(), "" });
}

TEST_CASE_METHOD(CreateCategoryCommandFixture, "CreateCategoryCommand - execute", CreateCategoryCommandFixture::Tag)
{
	reset_sample_storage();
	auto& app = Application::instance();
	auto category = get_random_category();
	auto name = "New Category";
	size_t invoke_count = 0;
	CreateCategoryCommand create_category_command{ Application::instance(), name };
	app.get_signal_context().get_category_created().connect([&](const CategoryPtr& created_category) {
		auto created_category_ptr = create_category_command.get_created_category();
		auto created_category2 = created_category_ptr.lock();
		REQUIRE(created_category2);
		REQUIRE(created_category->get_id() == created_category2->get_id());
		invoke_count++;
	});
	REQUIRE_NOTHROW(create_category_command.execute());
	REQUIRE(invoke_count == 1);
	auto created_category_ptr = create_category_command.get_created_category();
	auto created_category = created_category_ptr.lock();
	REQUIRE(created_category);
	REQUIRE(created_category->get_name() == name);
}
