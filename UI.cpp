//
// Created by Suciu Patrick on 2019-04-16.
//

#include "UI.h"
#include <sstream>
#include <string>
#include <unistd.h>

void UI::printMenu(){
    std::cout << "Choose mode: \n";
    std::cout <<"1. Admin ----------- 2. User\n";

}

void UI::printMenuAdmin(){
    std::cout << "Examples for admin\n";
    std::cout << "1.add,Bird Box,Drama,2019,450,insertlinkhere\n2remove,nameofthemovie\n3update,,Bird Box,Drama,2019,450,insertlinkhere\n4.print\n5.Exit";
}

void UI::printMenuUser(){
    std::cout << "Examples for user\n";
    std::cout << "1.genre,Comedy\n2.watched,nameofthemovie\n3.print\n4.Exit";
}

void UI::addEntities(){
    this->controller.add(Movie("Once Upon a Time in Hollywood", "Comedy", 2018, 650, "https://youtu.be/TMrIOUQKXCM"));
    this->controller.add(Movie("Us", "Comedy", 2019, 544, "https://youtu.be/1tzFRIQfwXg"));
    this->controller.add(Movie("Captain Marvel", "Action", 2019, 460, "https://youtu.be/Z1BCujX3pw8"));
    this->controller.add(Movie("Triple Frontier", "Action", 2019, 340, "https://youtu.be/Fo3yRLLrXQA"));
    this->controller.add(Movie("Bird Box", "Drama", 2019, 45, "https://youtu.be/o2AsIXSh2xo"));
    this->controller.add(Movie("Get Out", "Drama", 2017, 700, "https://youtu.be/DzfpyUB60YY"));
    this->controller.add(Movie("Terminator: Genisys", "Drama", 2015, 122, "https://youtu.be/jNU_jrPxs-0"));
    this->controller.add(Movie("Dunkirk", "Action", 2017, 674, "https://youtu.be/F-eMt3SrfFU"));
    this->controller.add(Movie("Vice", "Action", 2018, 354, "https://youtu.be/aSGFt6w0wok"));
    this->controller.add(Movie("Velvet Buzzsaw", "Horror", 2018, 323, "https://youtu.be/XdAR-lK43YU"));
    this->controller.add(Movie("Black Panther", "Action", 2017, 475, "https://youtu.be/xjDjIWPwcPU"));
    this->controller.add(Movie("Hostel", "Horror", 2005, 111, "https://youtu.be/4d5_lrn9v-g"));

    assert(this->controller.getRepo().getDa()[0].getNumberOfLikes() == 650);
    assert(this->controller.getRepo().getDa()[0].getGenre() == "Comedy");
    assert(this->controller.getRepo().getDa()[0].getTitle() == "Once Upon a Time in Hollywood");

    assert(this->controller.getRepo().getDa()[5].getNumberOfLikes() == 700);
    assert(this->controller.getRepo().getDa()[5].getGenre() == "Drama");
    assert(this->controller.getRepo().getDa()[5].getTitle() == "Get Out");

    assert(this->controller.getRepo().getDa()[6].getNumberOfLikes() == 122);
    assert(this->controller.getRepo().getDa()[6].getGenre() == "Drama");
    assert(this->controller.getRepo().getDa()[6].getTitle() == "Terminator: Genisys");

}

bool UI::addElement(Movie m) {
    this->controller.add(m);
    return true;
}

bool UI::removeElement(std::string title){
    if (this->controller.remove(title))
        return true;
    return false;
}

bool UI::updateElement(Movie m) {
    if (this->controller.update(m))
        return true;
    return false;
}

//I implemented the function mySplit in order to split the input because this application in console based.
//input - string, char(examples{,. })
//Output - vector<string> (each word will be a separate token, ex tokens[1], token[2]...)
std::vector<std::string> mySplit(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    bool ok = false;
    while (std::getline(tokenStream, token, delimiter))
    {
        ok = true;
        tokens.push_back(token);
    }
    if (ok == false)
        tokens[0] = s;
    return tokens;
}

//The admin part
void UI::startappAdmin(){
    std::vector<std::string> tokens;
    std::string input, name;

    printMenuAdmin();
    while (true) {
        getline(std::cin, input);
        tokens = mySplit(input, ',');
        if (tokens[0] == "Exit") {
            break;
        }
        //add,"Title","Genre",Year,likes,"trailer"
        else if (tokens[0] == "add") {
            if (addElement(Movie(tokens[1], tokens[2], std::stoi(tokens[3]), std::stoi(tokens[4]), tokens[5])))
                std::cout << "Added succesfully\n";
            else
                std::cout << "Added was not performed.";
        }
        //print
        else if (tokens[0] == "print")
        {
            std::vector<Movie>::iterator it;

            for (it = controller.getRepo().getDa().begin(); it < controller.getRepo().getDa().end(); it++)
                std::cout << it->toString() << '\n';
        }
        //remove,"title"
        else if (tokens[0] == "remove"){
            if (removeElement(tokens[1]))
                std::cout << "The film " << tokens[1] << " " << " was removed.\n";
        }
        //update,"Title","Genre",Year,likes,"trailer" title
        else if (tokens[0] == "update")
        {
            if (updateElement(Movie(tokens[1], tokens[2], std::stoi(tokens[3]), std::stoi(tokens[4]), tokens[5])))
                std::cout << "The movie was updated.\n";
            else
                std::cout << "The movie was not updated.";

        }
        else
            std::cout << "Invalid command.\n";
    }
}

//The User part
void UI::startappUser(){
    std::vector<std::string> tokens;
    std::string input, yesOrNo, next, rate;

    printMenuUser();
    while (true) {
        int index = 0;
        getline(std::cin, input);
        tokens = mySplit(input, ',');
        if (tokens[0] == "Exit") {
            break;
        }
        //genre,comedy
        else if (tokens[0] == "genre"){
            while (index != -1)
            {
                if (tokens[1] == "None")
                    index = controller.getRepo().seeByGenre("None", index);
                else
                    index = controller.getRepo().seeByGenre(tokens[1], index);

                std::cout << controller.getRepo().getDa()[index - 1].toString() << '\n';
                if (index !=-1){
                    std::cout << "Do you want to add it to the watchlist? Yes/No\n";
                    getline(std::cin, yesOrNo);
                    if (yesOrNo == "Yes")
                        controller.getWatchlist().addToWatchList(this->controller.getRepo().getDa()[index - 1]);
                    std::cout << "Do you want to continue?Yes/No\n";
                    getline(std::cin, next);
                    if (next == "No")
                        break;
                }
            }
        }
        //watched "Title"
        else if (tokens[0] == "watched"){
            if (controller.getWatchlist().removeFromRepository(tokens[1])){
                std::cout << "Rate this movie?";
                getline(std::cin, rate);
                if (rate == "Yes")
                    controller.getRepo().increaseRateByTitle(tokens[1]);
            }

        }
        else if (tokens[0] == "print"){
            std::vector<Movie>::iterator it;

            for (it = controller.getWatchlist().getDa().begin(); it < controller.getWatchlist().getDa().end(); it++)
                std::cout << it->toString() << '\n';
        }
    }

}
UI::UI(const Controller &controller) : controller(controller) {}
