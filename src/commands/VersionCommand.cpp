//
// Created by Marco Bassaletti on 17-03-21.
//

#include <iostream>
#include "VersionCommand.h"

namespace OwnPass::Commands {
	using namespace std;

	void VersionCommand::execute() {
		cout << "OwnPass v0.1" << endl;
	}

	void VersionCommand::undo() {}
}
