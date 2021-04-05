//
// Created by Marco Bassaletti on 15-03-21.
//

#ifndef OWNPASS_APPLICATION_H
#define OWNPASS_APPLICATION_H

#include "NSPass.h"
#include "storage/JsonStorageFactory.h"
#include "config/Settings.h"
#include "Vault.h"
#include "storage/Storage.h"

namespace NSPass {

	typedef std::function<void()> InitCallback;

	typedef std::function<void()> CleanupCallback;

	class Application {
	public:
		enum class LogMode {
			VERBOSE,
			NORMAL
		};

		Application();
		~Application();

		static Application& instance();

		[[nodiscard]] NSPass::Config::Settings& get_settings();
		[[nodiscard]] Vault& get_vault() const;
		[[nodiscard]] NSPass::Storage::Storage& get_storage() const;
		void init();
		void cleanup();

		void config(LogMode new_log_mode)
		{
			if (new_log_mode != log_mode) {
				log_mode = new_log_mode;
				init_logging();
			}
		}

		void register_init(const InitCallback& callback)
		{
			init_callbacks.push_back(callback);
		}

		void register_cleanup(const CleanupCallback& callback)
		{
			cleanup_callbacks.push_back(callback);
		}

	private:
		NSPass::Storage::JsonStorageFactory storage_factory{};
		LogMode log_mode = LogMode::NORMAL;
		std::list<InitCallback> init_callbacks;
		std::list<CleanupCallback> cleanup_callbacks;
		std::unique_ptr<Vault> vault;
		NSPass::Config::Settings settings;

		void init_logging();
		void init_vault();
	};
}

#endif //OWNPASS_APPLICATION_H
