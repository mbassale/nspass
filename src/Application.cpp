//
// Created by Marco Bassaletti on 15-03-21.
//

#include "NSPass.h"
#include "Application.h"

namespace NSPass {
	Application app;

	Application::Application()
	{
		init_logging();
		init_vault();
	}

	Application::~Application() = default;

	Application& Application::instance()
	{
		return app;
	}

	void Application::init()
	{
		for (const auto& callback : init_callbacks) {
			callback();
		}
	}

	void Application::cleanup()
	{
		for (const auto& callback : cleanup_callbacks) {
			callback();
		}
	}

	void Application::init_logging()
	{
	}

	void Application::init_vault()
	{
		vault = std::make_unique<Vault>(storage_factory);
	}

	NSPass::Config::Settings& Application::get_settings()
	{
		return settings;
	}

	Vault& Application::get_vault() const
	{
		if (vault) return *vault;
		throw ApplicationException{ "Vault not initialized." };
	}

	NSPass::Storage::Storage& Application::get_storage() const
	{
		return get_vault().get_storage();
	}
}
