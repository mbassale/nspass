//
// Created by Marco Bassaletti on 12-04-21.
//

#ifndef NSPASS_SIGNAL_H
#define NSPASS_SIGNAL_H

#include <vector>
#include <memory>

namespace NSPass::GUI::Signals {
	template<typename T, typename ...Args>
	class Signal {
	public:
		Signal() = default;
		virtual ~Signal() = default;
		void Connect(const T& slot) { slots.push_back(slot); };
		void Disconnect(const T& slot)
		{
			auto it = slots.begin();
			while (it != slots.end()) {
				if (it == slot) {
					slots.erase(it);
					break;
				}
				it++;
			}
		};
		void Invoke(Args... args)
		{
			for (const auto& slot : slots) {
				slot(args...);
			}
		}

		[[nodiscard]] const std::vector<T>& get_slots() const { return slots; }
	protected:
		std::vector<T> slots;
	};
}

#endif //NSPASS_SIGNAL_H
