//
// Created by Suciu Patrick on 2019-04-16.
//

#ifndef MOVIE_FINAL_UI_H
#define MOVIE_FINAL_UI_H

#include "Controller.h"

class UI{
private:
    Controller &controller;
public:
    void printMenu();
    void printMenuAdmin();
    void printMenuUser();
    void addEntities();
    bool addElement(Movie m);
    void startappAdmin();
    bool removeElement(std::string title);
    void listTofile();
    bool updateElement(Movie m);
    UI(Controller &controller);
    void startappUser();
};

#endif //MOVIE_FINAL_UI_H
