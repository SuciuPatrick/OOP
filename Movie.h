//
// Created by Suciu Patrick on 2019-04-16.
//

#ifndef MOVIE_FINAL_MOVIE_H
#define MOVIE_FINAL_MOVIE_H
#include <iostream>

class Movie {
private:
    // a title, a genre, a year of release, a number of likes and a trailer.
    std::string title;
    std::string genre;
    int year;
    int numberOfLikes;
    std::string trailer;
public:
    //getters
    const std::string &getTitle() const;
    const std::string &getGenre() const;
    int getYear() const;
    int getNumberOfLikes() const;
    const std::string &getTrailer() const;

    //setters
    void setTitle(const std::string &title);
    void setGenre(const std::string &genre);
    void setYear(int year);
    void setNumberOfLikes(int numberOfLikes);
    void setTrailer(const std::string &trailer);

    //Print
    std::string toString();

    //contructor
    Movie(const std::string &title, const std::string &genre, int year, int numberOfLikes, const std::string &trailer);
};

#endif //MOVIE_FINAL_MOVIE_H
