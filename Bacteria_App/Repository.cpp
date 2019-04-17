//
// Created by Suciu Patrick on 2019-04-10.
//

#include "Repository.h"

bool Repository::addToRepository(Bacteria bacteria) {
    /*
     * Adds a new bacteria. Returns true if it was added succesfully.
     * input- bacteria
     * output- true or false
    */
    unsigned long initial_size = this->da.size();
    this->da.push_back(bacteria);
    if (initial_size + 1 == this->da.size())
        return true;
    return false;
}

std::vector<Bacteria> &Repository::getDa() {

    return da;
}

Repository::Repository(const std::vector<Bacteria> &da) : da(da) {}
