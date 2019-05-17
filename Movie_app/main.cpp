#include <iostream>
#include <vector>
#include <fstream>
#include "UI.h"
#include "RepositoryCSV.h"
#include <zconf.h>
#include "RepositoryHTML.h"
#include <QApplication>
#include <QDebug>
#include <QWidget>
#include "GUI.h"

void mainTestPatrick() {
    std::ofstream out;
    out.open("file.txt");
    Movie m = Movie("Once Upon a Time in Hollywood", "Comedy", 2018, 650, "https://youtu.be/TMrIOUQKXCM");
    out << m;
    // std::cin >> m;
    //std::cout << m;
    int s;
    while (true) {
        std::cin >> s;
        break;
    }

    /*
     std::vector<Movie>::iterator it;

    controller.getRepo().removeFromRepository("Regele plajei");
    controller.getRepo().removeFromRepository("Black Panther");
    controller.getRepo().updateMovie(Movie("Free Solo", "Comedy", 2200, 1000, "dassda"));

    for (it = controller.getRepo().getDa().begin(); it < controller.getRepo().getDa().end(); it++)
        std::cout << it->toString() << '\n';
    */
}

void startappWithUI(){
    Repository *repo, *watchlist;
    std::string input, name;
    while (true){
        std::cout << "html or csv: ";
        getline(std::cin, input);
        if (input == "csv"){
            repo = new RepositoryCSV();
            watchlist = new RepositoryCSV();
            break;
        }
        else {
            //html
            repo = new RepositoryHTML();
            watchlist = new RepositoryHTML();
            break;
        }
    }
    repo->readFromFile("data.txt");
    while (true) {
        Controller controller {repo, watchlist};
        UI ui {controller};
        //ui.addEntities();
        ui.printMenu();
        getline(std::cin, input);
        if (input == "Admin") {
            ui.startappAdmin();
        } else if (input == "User") {
            ui.startappUser();
        } else if (input == "Exit") {
            std::cout << "Exit application";
            break;
        } else
            std::cout << "Invalid command";
    }
}


int startappWithGUI(int argc, char *argv[]){
    QApplication a(argc, argv);
    Repository *repo, *watchlist;
    repo = new RepositoryCSV();
    watchlist = new RepositoryCSV();
    repo->readFromFile("data.txt");
    Controller *controller = new Controller{repo, watchlist};

    GUI gui {controller};
    gui.show();


    return QApplication::exec();
}

int main(int argc, char *argv[]) {
    startappWithGUI(argc, argv);
//   startappWithUI();
    return 0;
}