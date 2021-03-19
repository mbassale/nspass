//
// Created by Marco Bassaletti on 15-03-21.
//

#ifndef OWNPASS_APPLICATION_H
#define OWNPASS_APPLICATION_H

#include <list>
#include <functional>
#include "Vault.h"
#include "ApplicationException.h"

namespace OwnPass {

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

		[[nodiscard]] Vault& get_vault() const;
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
		LogMode log_mode = LogMode::NORMAL;
		std::list<InitCallback> init_callbacks;
		std::list<CleanupCallback> cleanup_callbacks;
		std::unique_ptr<Vault> vault;

		void init_logging();
		void init_vault();
	};
}

#endif //OWNPASS_APPLICATION_H
