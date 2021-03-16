//
// Created by Marco Bassaletti on 15-03-21.
//

#include "Application.h"

namespace OwnPass {
	Application app;

	Application& Application::instance()
	{
		return app;
	}
}
