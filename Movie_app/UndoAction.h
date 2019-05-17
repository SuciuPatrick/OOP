//
// Created by Suciu Patrick on 2019-05-09.
//

#ifndef MOVIE_FINAL_UNDOACTION_H
#define MOVIE_FINAL_UNDOACTION_H

#include "Repository.h"

class UndoAction {
public:
    virtual void executeUndo() = 0;
    virtual ~UndoAction(){}
    UndoAction();
};

class UndoAdd : public UndoAction {
private:
    Movie addMovie;
    Repository *r;
public:
    UndoAdd(Movie addMovie, Repository *r);
    ~UndoAdd();
    void executeUndo() override;
};

class UndoRemove : public UndoAction {
private:
    Movie deletedMovie;
    Repository *r;
public:
    void executeUndo() override;
    UndoRemove(Movie deletedMovie, Repository *r);
    ~UndoRemove();
};

#endif //MOVIE_FINAL_UNDOACTION_H
