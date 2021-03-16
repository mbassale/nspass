//
// Created by Marco Bassaletti on 15-03-21.
//

#ifndef OWNPASS_APPLICATION_H
#define OWNPASS_APPLICATION_H

#include <list>
#include <functional>

namespace OwnPass {

	typedef std::function<void()> InitCallback;
	typedef std::function<void()> CleanupCallback;

	class Application {
	public:
		static Application& instance();

		void register_init(const InitCallback& callback) {
			init_callbacks.push_back(callback);
		}

		void register_cleanup(const CleanupCallback& callback) {
			cleanup_callbacks.push_back(callback);
		}

		void init() {
			for (const auto& callback : init_callbacks) {
				callback();
			}
		}

		void cleanup() {
			for (const auto& callback : cleanup_callbacks) {
				callback();
			}
		}

	private:
		std::list<InitCallback> init_callbacks;
		std::list<CleanupCallback> cleanup_callbacks;
	};
}

#endif //OWNPASS_APPLICATION_H
