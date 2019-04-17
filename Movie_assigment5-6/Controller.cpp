//
// Created by Suciu Patrick on 2019-04-10.
//

#include "Controller.h"
#include "Repository.h"


bool Controller::add(Bacteria bacteria) {
    this->repo.addToRepository(bacteria);
}

Repository &Controller::getRepo() {
    return repo;
}

Controller::Controller(const Repository &repo) : repo(repo) {}
