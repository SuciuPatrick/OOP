//
// Created by Suciu Patrick on 2019-05-09.
//

#include "UndoAction.h"

void UndoAdd::executeUndo() {
    this->r->removeFromRepository(this->addMovie.getTitle());
}

UndoAdd::~UndoAdd() {

}

UndoAdd::UndoAdd(Movie addMovie, Repository *r) : r(r){
    this->addMovie = addMovie;
}

UndoAction::UndoAction() {

}

UndoRemove::~UndoRemove() {

}

UndoRemove::UndoRemove(Movie deletedMovie, Repository *r) : r(r){
    this->deletedMovie = deletedMovie;
}

void UndoRemove::executeUndo() {
    this->r->addToRepository(this->deletedMovie);
}

