//
// Created by Marco Bassaletti on 18-03-21.
//

#include <iostream>
#include "HelpCommand.h"

namespace OwnPass::Commands {
	using namespace std;

	void HelpCommand::execute()
	{
		cout << opt_desc << endl;
	}

	void HelpCommand::undo()
	{

	}

}
