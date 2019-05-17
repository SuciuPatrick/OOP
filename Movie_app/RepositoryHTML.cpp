//
// Created by Suciu Patrick on 2019-05-14.
//

#include "RepositoryHTML.h"
#include <fstream>
#include "Movie.h"
#include "zconf.h"

RepositoryHTML::RepositoryHTML() {

}

RepositoryHTML::~RepositoryHTML() {

}

void RepositoryHTML::writeWatchlist() {
    std::ofstream out("watchlist.html");
    out << "<!DOCTYPE html>\n";
    out << "<html><head><title>Watchlist</title></head>\n";
    out << "<body><table border=\"1\">";
    out << "<tr>\n";
    out << "<td>Title</td>\n";
    out << "<td>Genre</td>\n";
    out << "<td>Year</td>\n";
    out << "<td>Likes</td>\n";
    out << "<td>Link</td>\n";
    out << "</tr>\n";
    std::vector<Movie> list = this->getDa();
    for (auto d : list)
    {
        out << "<tr>\n";
        out << "<td>" << d.getTitle() <<"</td>\n";
        out << "<td>" << d.getGenre() << "</td>\n";
        out << "<td>" << d.getYear() << "</td>\n";
        out << "<td>" << d.getNumberOfLikes() << "</td>\n";
        out << "<td><a href = \"" << d.getTrailer() << "\">Trailer</a></td>\n";
        out << "</tr>\n";
    }
    out << "</table></body></html>";
    out.close();
}

void RepositoryHTML::showWatchlist() {
    execlp("open", "open", "watchlist.html", NULL);
}
