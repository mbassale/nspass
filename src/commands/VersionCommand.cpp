//
// Created by Marco Bassaletti on 17-03-21.
//

#include <iostream>
#include "VersionCommand.h"

namespace NSPass::Commands {
	using namespace std;

	void VersionCommand::execute() {
		cout << "NSPass v0.1" << endl;
	}

	void VersionCommand::undo() {}
}
