//
// Created by Suciu Patrick on 2019-05-13.
//

#ifndef MOVIE_FINAL_ERRORS_H
#define MOVIE_FINAL_ERRORS_H

#include <iostream>
#include <string>

class UIException
{
private:
    std::string message;
public:
    UIException(std::string message);
    const std::string &getMessage() const;
};

class RepositoryException {
private:
    std::string message;
public:
    RepositoryException(std::string message);
    const std::string &getMessage() const;
};

class ValidationException
{
private:
    std::string message;
public:
    ValidationException(std::string message);
    const std::string &getMessage() const;
};

#endif //MOVIE_FINAL_ERRORS_H
