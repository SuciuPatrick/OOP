//
// Created by Suciu Patrick on 2019-04-16.
//

#include "Movie.h"
#include <vector>
#include <sstream>

const std::string &Movie::getTitle() const {
    return title;
}

const std::string &Movie::getGenre() const {
    return genre;
}

int Movie::getYear() const {
    return year;
}

int Movie::getNumberOfLikes() const {
    return numberOfLikes;
}

const std::string &Movie::getTrailer() const {
    return trailer;
}

void Movie::setTitle(const std::string &title) {
    Movie::title = title;
}

void Movie::setGenre(const std::string &genre) {
    Movie::genre = genre;
}

void Movie::setYear(int year) {
    Movie::year = year;
}

void Movie::setNumberOfLikes(int numberOfLikes) {
    Movie::numberOfLikes = numberOfLikes;
}

void Movie::setTrailer(const std::string &trailer) {
    Movie::trailer = trailer;
}

Movie::Movie(const std::string &title, const std::string &genre, int year, int numberOfLikes,
             const std::string &trailer) : title(title), genre(genre), year(year), numberOfLikes(numberOfLikes),
                                           trailer(trailer) {}

std::string Movie::toString() {
    std::string final;

    final = this->title + " " + this->genre + " " + std::to_string(this->year) + " " + std::to_string(this->numberOfLikes) + " " + this->trailer;

    return final;
}

Movie::Movie() {}

std::vector<std::string> Split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    bool ok = false;
    while (std::getline(tokenStream, token, delimiter))
    {
        ok = true;
        tokens.push_back(token);
    }
    if (ok == false)
        tokens[0] = s;
    return tokens;
}

std::ostream &operator<<(std::ostream &os, const Movie &movie) {
    os << movie.title << "," << movie.genre << "," << movie.year << ","
       << movie.numberOfLikes << "," << movie.trailer;
    return os;
}

std::istream &operator>>(std::istream &in, Movie &d) {
    std::vector<std::string> tokens;
    std::string line;

    getline(in, line);
    if (!line.empty()) {
        tokens = Split(line, ',');
        d.title = tokens[0];
        d.genre = tokens[1];
        d.year = stoi(tokens[2]);
        d.numberOfLikes = stoi(tokens[3]);
        d.trailer = tokens[4];
    }
    return in;
}
