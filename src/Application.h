//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef OWNPASS_APPLICATION_H
#define OWNPASS_APPLICATION_H

#include "Group.h"

namespace OwnPass {
	class Application : public Group {
	public:
		Application(std::string& name);
		~Application();
	};
}

#endif //OWNPASS_APPLICATION_H
