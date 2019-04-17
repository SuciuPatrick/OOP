//
// Created by Suciu Patrick on 2019-04-10.
//

#ifndef BACTERIA_TEST_CONTROLLER_H
#define BACTERIA_TEST_CONTROLLER_H

#include "Repository.h"

class Controller {
private:
    Repository repo;
public:
    bool add(Bacteria bacteria);
    Repository &getRepo();

    Controller(const Repository &repo);
};

#endif //BACTERIA_TEST_CONTROLLER_H
