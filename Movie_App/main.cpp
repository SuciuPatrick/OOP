#include <iostream>
#include <vector>

#include "Movie.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"

int main() {
    Repository repo = Repository();
    Controller controller = Controller(repo);
    UI ui = UI(controller);
    ui.addEntities();
    std::string input, name;

    ui.printMenu();
    while (true) {
        getline(std::cin, input);
        if (input == "Admin"){
            ui.startappAdmin();
        }
        else if (input == "User"){
            ui.startappUser();
        }
        else if (input == "Exit"){
            std::cout << "Exit application";
            break;
        }
        else
            std::cout << "Invalid command";
    }

    /*
     std::vector<Movie>::iterator it;

    controller.getRepo().removeFromRepository("Regele plajei");
    controller.getRepo().removeFromRepository("Black Panther");
    controller.getRepo().updateMovie(Movie("Free Solo", "Comedy", 2200, 1000, "dassda"));

    for (it = controller.getRepo().getDa().begin(); it < controller.getRepo().getDa().end(); it++)
        std::cout << it->toString() << '\n';
    */
    return 0;
}