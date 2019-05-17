//
// Created by Suciu Patrick on 2019-05-16.
//

#ifndef MOVIE_FINAL_GUI_H
#define MOVIE_FINAL_GUI_H

#include "/Users/suciupatrick/Qt/5.12.3/clang_64/lib/QtWidgets.framework/Versions/5/Headers/qwidget.h"
#include "Controller.h"
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

class GUI : public QWidget {
private:
    QPushButton *addButton, *removeButton, *updateButton, *chartButton;
    Controller *controller;
    QListWidget *movies;
    QLineEdit *title, *genre, *numberOfLikes, *year, *link;

public:
    GUI(Controller *c);
    void addEntities();
    void clear();
    void mainWindow();
    void Administrator();
    void User();
    void addMovie();
    void updateMovie();
    void removeMovie();
    void chartMovie();
    ~GUI();
};
#endif //MOVIE_FINAL_GUI_H
