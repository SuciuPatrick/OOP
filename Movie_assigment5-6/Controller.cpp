//
// Created by Suciu Patrick on 2019-04-16.
//

#include "Controller.h"

//Constructor
Controller::Controller(const Repository &repo) : repo(repo) {}

//It calls the method add from the repository.
bool Controller::add(Movie m) {
    this->repo.addToRepository(m);
}

//It calls the method remove from the repository.
bool Controller::remove(std::string title) {
    if (this->repo.removeFromRepository(title))
        return true;
    return false;
}

//It calls the method update from the repository.
bool Controller::update(Movie m) {
    if (this->repo.updateMovie(m))
        return true;
    return false;
}

//getter WatchList
Repository &Controller::getWatchlist(){
    return watchlist;
}

//getter Repository
Repository &Controller::getRepo(){
    return repo;
}