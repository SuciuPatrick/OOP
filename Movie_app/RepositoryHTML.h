//
// Created by Suciu Patrick on 2019-05-14.
//

#ifndef MOVIE_FINAL_REPOSITORYHTML_H
#define MOVIE_FINAL_REPOSITORYHTML_H

#include "Repository.h"

class RepositoryHTML : public Repository {
public:
    RepositoryHTML();
    virtual ~RepositoryHTML();

    void writeWatchlist() override;
    void showWatchlist()override;
};
#endif //MOVIE_FINAL_REPOSITORYHTML_H
