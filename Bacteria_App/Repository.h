//
// Created by Suciu Patrick on 2019-04-10.
//

#ifndef BACTERIA_TEST_REPOSITORY_H
#define BACTERIA_TEST_REPOSITORY_H

#include "Bacteria.h"
#include <vector>

class Repository{
private:
    std::vector<Bacteria> da;
public:
    bool addToRepository(Bacteria bacteria);
    std::vector<Bacteria> &getDa();

    Repository(const std::vector<Bacteria> &da);
};

#endif //BACTERIA_TEST_REPOSITORY_H
