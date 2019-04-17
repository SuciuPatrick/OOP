//
// Created by Suciu Patrick on 2019-04-16.
//

#include "Movie.h"

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