//
// Created by Suciu Patrick on 2019-04-16.
//

#ifndef MOVIE_FINAL_CONTROLLER_H
#define MOVIE_FINAL_CONTROLLER_H

#include "Repository.h"

class Controller{
private:
    Repository repo;
    Repository watchlist;
public:
    //Constructor
    Controller(const Repository &repo);

    //getter
    Repository &getRepo();

    Repository &getWatchlist();

    //Op
    bool add(Movie m);
    bool remove(std::string);
    bool update(Movie m);
};

#endif //MOVIE_FINAL_CONTROLLER_H
