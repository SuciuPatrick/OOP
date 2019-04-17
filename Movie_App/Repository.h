//
// Created by Suciu Patrick on 2019-04-16.
//

#ifndef MOVIE_FINAL_REPOSITORY_H
#define MOVIE_FINAL_REPOSITORY_H

#include "Movie.h"
#include <vector>
class Repository {
private:
    std::vector<Movie> da;
public:
    std::vector<Movie> &getDa();
    bool addToWatchList(Movie m);
    bool addToRepository(Movie m);
    bool removeFromRepository(std::string title);
    bool updateMovie(Movie m);
    bool increaseRateByTitle(std::string title);
    int seeByGenre(std::string genre, int index);
};

#endif //MOVIE_FINAL_REPOSITORY_H
