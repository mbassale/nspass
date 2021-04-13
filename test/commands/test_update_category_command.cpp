//
// Created by Marco Bassaletti on 13-04-21.
//
#include "../catch.hpp"
#include "../../src/NSPass.h"
#include "../../src/Application.h"
#include "../SampleStorageFixture.h"
#include "../../src/commands/UpdateCategoryCommand.h"

using NSPass::IdGenerator;
using NSPass::Application;
using NSPass::CategoryPtr;
using NSPass::Commands::UpdateCategoryCommand;

class UpdateCategoryCommandFixture : public SampleStorageFixture {
public:
	static constexpr auto Tag = "[update category command]";
	UpdateCategoryCommandFixture() = default;
};

TEST_CASE_METHOD(UpdateCategoryCommandFixture, "UpdateCategoryCommand - construct", UpdateCategoryCommandFixture::Tag)
{
	UpdateCategoryCommand::UpdateData update_data;
	auto category_id = IdGenerator::make();
	REQUIRE_NOTHROW(UpdateCategoryCommand{ Application::instance(), category_id, update_data });
}

TEST_CASE_METHOD(UpdateCategoryCommandFixture, "UpdateCategoryCommand - execute", UpdateCategoryCommandFixture::Tag)
{
	reset_sample_storage();
	auto& app = Application::instance();
	UpdateCategoryCommand::UpdateData update_data;
	update_data.name = "Updated Name";
	size_t invoke_count = 0;
	auto category = get_random_category();
	app.get_signal_context().get_category_updated().connect([&](const CategoryPtr& updated_category) {
		REQUIRE(updated_category);
		REQUIRE(updated_category->get_id() == category->get_id());
		REQUIRE(updated_category->get_name() == update_data.name);
		invoke_count++;
	});
	UpdateCategoryCommand update_category_command{ Application::instance(), category->get_id(), update_data };
	REQUIRE_NOTHROW(update_category_command.execute());
	REQUIRE(invoke_count == 1);
	auto& updated_category_ptr = update_category_command.get_updated_category();
	auto updated_category = updated_category_ptr.lock();
	REQUIRE(updated_category);
	REQUIRE(updated_category->get_id() == category->get_id());
	REQUIRE(updated_category->get_name() == update_data.name);
}
