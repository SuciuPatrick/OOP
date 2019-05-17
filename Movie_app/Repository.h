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
    Movie getMovieByTitle(std::string title);
    bool searchByTitle(std::string title);
    Repository();
    Repository(Repository &r);
    void readFromFile(std::string text);
    std::vector<std::string> Split(const std::string &s, char delimiter);



    virtual void writeWatchlist() = 0;
    virtual void showWatchlist() = 0;
};

#endif //MOVIE_FINAL_REPOSITORY_H
