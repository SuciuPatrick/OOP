//
// Created by Suciu Patrick on 2019-04-16.
//

#include "Controller.h"
#include <fstream>
#include "Errors.h"

//Constructor
//Controller::Controller(Repository &repo, Repository &watchlist) : repo(repo), watchlist(watchlist) {}

//It calls the method add from the repository.
bool Controller::add(Movie m) {
    auto ptr = std::make_unique<UndoAdd>(m, this->repo);
    this->undoList.push_back(std::move(ptr));
    this->repo->addToRepository(m);
    this->writeTofile();
}

//It calls the method remove from the repository.
bool Controller::remove(std::string title) {
    if (this->repo->searchByTitle(title)) {
        Movie m = this->repo->getMovieByTitle(title);
        auto ptr = std::make_unique<UndoRemove>(m, this->repo);
        this->undoList.push_back(std::move(ptr));
        this->repo->removeFromRepository(title);
        this->writeTofile();
        return true;
    }
    throw RepositoryException("Not in the list.");
}

//It calls the method update from the repository.
bool Controller::update(Movie m) {
    if (this->repo->updateMovie(m)) {
        this->writeTofile();
        return true;
    }
    return false;
}

void Controller::executeUndo() {
    if (this->undoList.size() == 0)
        return;
    this->undoList[this->undoList.size() - 1]->executeUndo();
    this->undoList.pop_back();
}

void Controller::writeTofile() {
    std::ofstream out;
    out.open("data.txt");

    for (const auto & i : this->repo->getDa())
        out << i << '\n';
}

Controller::Controller(Repository *repo, Repository *watchlist) : repo(repo), watchlist(watchlist){

}

Repository *Controller::getRepo() {
    return repo;
}

Repository *Controller::getWatchlist() {
    return watchlist;
}

//Controller::Controller(Repository &repo, Repository &watchlist) : repo(repo), watchlist(watchlist){

//}