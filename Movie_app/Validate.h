//
// Created by Suciu Patrick on 2019-05-13.
//

#ifndef MOVIE_FINAL_VALIDATE_H
#define MOVIE_FINAL_VALIDATE_H

#include "Movie.h"
#include "Errors.h"

class Validate {
public:
    Validate();
    ~Validate();
    void validateMovie(Movie m);
};

#endif //MOVIE_FINAL_VALIDATE_H
