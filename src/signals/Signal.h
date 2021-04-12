//
// Created by Marco Bassaletti on 12-04-21.
//

#ifndef NSPASS_SIGNAL_H
#define NSPASS_SIGNAL_H

#include <vector>
#include <memory>

namespace NSPass::Signals {

	typedef size_t SignalId;

	template<typename T, typename ...Args>
	class Signal {
	public:
		Signal() = default;
		virtual ~Signal() = default;

		SignalId connect(const T& slot)
		{
			slots.push_back(slot);
			return slots.size()-1;
		};

		void disconnect(SignalId slot_id)
		{
			SignalId idx = 0;
			auto it = slots.begin();
			while (it != slots.end()) {
				if (idx == slot_id) {
					slots.erase(it);
					break;
				}
				idx++;
				it++;
			}
		};

		void invoke(Args... args)
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
