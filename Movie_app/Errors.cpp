//
// Created by Suciu Patrick on 2019-05-13.
//

#include "Errors.h"

const std::string &ValidationException::getMessage() const {
    return message;
}

ValidationException::ValidationException(std::string message) {
    this->message = message;
}

const std::string &RepositoryException::getMessage() const {
    return message;
}

RepositoryException::RepositoryException(std::string message) {
    this->message = message;
}

const std::string &UIException::getMessage() const {
    return message;
}

UIException::UIException(std::string message) {
    this->message = message;
}
