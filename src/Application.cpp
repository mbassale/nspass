//
// Created by Marco Bassaletti on 15-03-21.
//

#include <memory>
#include <iomanip>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include "Application.h"

namespace logging = boost::log;

namespace OwnPass {
	Application app;

	Application::Application()
	{
		init_logging();
		init_vault();
	}

	Application::~Application()
	{
	}

	Application& Application::instance()
	{
		return app;
	}

	void Application::init()
	{
		BOOST_LOG_TRIVIAL(trace) << "Initializing... " << std::flush;
		for (const auto& callback : init_callbacks) {
			callback();
		}
		BOOST_LOG_TRIVIAL(trace) << "Done." << std::endl;
	}

	void Application::cleanup()
	{
		BOOST_LOG_TRIVIAL(trace) << "Cleanup... " << std::flush;
		for (const auto& callback : cleanup_callbacks) {
			callback();
		}
		BOOST_LOG_TRIVIAL(trace) << "Done." << std::endl;
	}

	void Application::init_logging()
	{
		switch (log_mode) {
		case LogMode::NORMAL:
			logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);
			break;
		default:
			logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::trace);
			break;
		}
	}

	void Application::init_vault()
	{
		vault = std::make_unique<Vault>();
	}

	Vault& Application::get_vault() const
	{
		if (vault) return *vault;
		throw ApplicationException{ "Vault not initialized." };
	}
}
