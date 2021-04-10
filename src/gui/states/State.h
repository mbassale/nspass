//
// Created by Marco Bassaletti on 10-04-21.
//

#ifndef NSPASS_STATE_H
#define NSPASS_STATE_H

#include <memory>

namespace NSPass::GUI::States {
	class State {
	public:
		virtual void OpenDefault() { };
		virtual void Open() { };
		virtual void Close() { };
		virtual void Save() { };
	};

	typedef std::unique_ptr<State> StatePtr;
}

#endif //NSPASS_STATE_H
