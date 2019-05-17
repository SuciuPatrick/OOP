//
// Created by Suciu Patrick on 2019-04-16.
//

#ifndef MOVIE_FINAL_CONTROLLER_H
#define MOVIE_FINAL_CONTROLLER_H

#include "Repository.h"
#include "UndoAction.h"
#include <memory>

class Controller {
private:
    Repository* repo;
    Repository* watchlist;
    std::vector<std::unique_ptr<UndoAction>> undoList;
public:
    //Constructor
    Controller(Repository *repo, Repository *watchlist);

    //getter
    Repository *getRepo();
    Repository *getWatchlist();

    //Op
    bool add(Movie m);
    bool remove(std::string);
    bool update(Movie m);
    void executeUndo();
    void writeTofile();
};

#endif //MOVIE_FINAL_CONTROLLER_H
