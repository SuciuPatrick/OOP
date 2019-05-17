//
// Created by Suciu Patrick on 2019-05-13.
//

#ifndef MOVIE_FINAL_REPOSITORYCSV_H
#define MOVIE_FINAL_REPOSITORYCSV_H

#include "Repository.h"

class RepositoryCSV : public Repository {
public:
    RepositoryCSV();

    virtual ~RepositoryCSV();
    void writeWatchlist() override;
    void showWatchlist()override;
};

#endif //MOVIE_FINAL_REPOSITORYCSV_H
