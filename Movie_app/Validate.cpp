//
// Created by Suciu Patrick on 2019-05-13.
//

#include "Validate.h"

Validate::Validate() {}

Validate::~Validate() {

}

void Validate::validateMovie(Movie m) {
    if (m.getYear() > 2019 || m.getYear() < 1600)
        throw ValidationException("Invalid year.");
    if (m.getNumberOfLikes() < 0)
        throw  ValidationException("Invalid number of likes.");
}
