//
// Created by Marco Bassaletti on 22-02-21.
//

#ifndef MBASSALE_PM_APPLICATION_H
#define MBASSALE_PM_APPLICATION_H

#include "Group.h"

class Application : public Group {
public:
    Application(std::string& name);
    ~Application();
};


#endif //MBASSALE_PM_APPLICATION_H
