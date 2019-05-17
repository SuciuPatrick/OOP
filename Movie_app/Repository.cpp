//
// Created by Suciu Patrick on 2019-04-16.
//

#include "Repository.h"
#include "unistd.h"
#include "Errors.h"
#include <fstream>
#include <sstream>

//getter
std::vector<Movie> &Repository::getDa() {
    return da;
}

//Adds a movie to the WatchList !Useless, we can use addToRepository
bool Repository::addToWatchList(Movie m) {
    this->da.push_back(m);
    return true;
}


bool Repository::addToRepository(Movie m) {
    this->da.push_back(m);
    return true;
}

//Removes a movie from the repository. Unique key is the movie title.
//input - title
//output - {true, false} - if the movie was removed succesfully
bool Repository::removeFromRepository(std::string title) {
    std::vector<Movie>::iterator it;

    for (it = this->da.begin(); it <= this->da.end(); it++)
        if (it->getTitle() == title) {
            this->da.erase(it);
            return true;
        }
    throw RepositoryException("The movie is not in the list.\n");
    //return false;
}

//When the user watched a movie he has the option to rate a movie
//The increasing number of likes happens here
//Input: string - title(unique)
//Output: {true, false} - if the increaseRate happened succesfully
bool Repository::increaseRateByTitle(std::string title) {
    std::vector<Movie>::iterator it;

    for (it = this->da.begin(); it <= this->da.end(); it++)
        if (it->getTitle() == title) {
            int x = it->getNumberOfLikes();
            it->setNumberOfLikes(x + 1);
            return true;
        }
    return false;
}


//Update a movie. It will search for the movie by Title and if it is found it will be updated.
//Input: Movie - with the new inputs. Just the name is the same, because is unique
//Output: {true, false}
bool Repository::updateMovie(Movie m) {
    std::vector<Movie>::iterator it;

    for (it = this->da.begin(); it <= this->da.end(); it++)
        if (m.getTitle() == it->getTitle()) {
            *it = m;
            return true;
        }
    throw RepositoryException("The movie is not in the list.\n");
}

//This is a method special for the User
//It searches through the "database" and if a movie is found by the specific genre, 
//it will start a youtube link in the browser(the trailer of the movie), it will stop the search and will return 
//the index of the movie that was found
//input - string(genre), integer(index)
//output - integer
int Repository::seeByGenre(std::string genre, int index) {
    std::vector<Movie>::iterator it;
    int cnt = index;

    if (genre == "None") {
        for (int i = index; i < this->da.size(); i++) {
            cnt++;
            std::string link;
            link = "open " + this->da[i].getTrailer();
            const char *cstr = link.c_str();
            system(cstr);
            return cnt;
        }
    }
    else if (genre != ""){
        for (int i = index; i < this->da.size(); i++) {
            cnt++;
            //std::cout << this->da[i].toString() << '\n';
            if (this->da[i].getGenre() == genre) {
                std::string link;
                link = "open " + this->da[i].getTrailer();
                const char *cstr = link.c_str();
                system(cstr);
                return cnt;
            }
        }
    }
    return -1;
}

Repository::Repository() {

}

Repository::Repository(Repository &r) {
    this->da = r.da;
}

Movie Repository::getMovieByTitle(std::string title) {
    for (int i = 0; i < this->da.size(); i++) {
        if (this->da[i].getTitle() == title)
            return this->da[i];
    }
}

bool Repository::searchByTitle(std::string title) {
    for (int i = 0; i < this->da.size(); i++) {
        if (this->da[i].getTitle() == title)
            return true;
    }
    return false;
}

void Repository::readFromFile(std::string text) {
    std::ifstream in(text);
    Movie m;
    while (in >> m){
        this->da.push_back(m);
    }
    in.close();
}

