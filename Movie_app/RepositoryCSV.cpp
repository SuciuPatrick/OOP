//
// Created by Suciu Patrick on 2019-05-13.
//

#include "RepositoryCSV.h"
#include <fstream>
#include <zconf.h>

void RepositoryCSV::writeWatchlist() {
    std::vector<Movie> list = this->getDa();

    std::ofstream out("watchlist.csv");

    for (int i = 0; i < list.size(); i++)
    {
        out << list[i].getTitle() << ',' << list[i].getGenre() << ',' << list[i].getYear() << ',' << list[i].getNumberOfLikes() << ',' << list[i].getTrailer() << '\n';
    }
}

void RepositoryCSV::showWatchlist() {
    //to do the fork
    execlp("open", "open", "watchlist.csv", NULL);
}

RepositoryCSV::RepositoryCSV() {}

RepositoryCSV::~RepositoryCSV() {

}
