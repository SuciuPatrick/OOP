#include <iostream>
#include "Player.h"
#include "Controller.h"
#include "UI.h"


void addPlayers(Controller &controller)
{
    Player a = Player("Isabelle", "ROM", "Steaua", 80);
    controller.add(Player("Cristina Neagu", "ROU", "Rapid", 70));
    controller.add(Player("Dorel Neagu", "ROU", "Rapid", 30));
    controller.add(Player("Marcel Neagu", "ROU", "Rapid", 45));
    controller.add(a);
    controller.update("Cristina Neagu", "PULA");
}

int main(){

    {
        std::vector<Player> da;
        Repository repository = Repository(da);
        Controller controler = Controller(repository);
        addPlayers(controler);
        UI ui = UI(controler);
        std::cout << "from main:" << controler.getRepo().getDa().size();
        ui.startApp();
    }

    /*{
    std::vector<Player> da;
    Repository repository = Repository(da);
    Controller controller = Controller(repository);
    addPlayers(controller);
    std::vector<Player> *aux = &controller.getRepo().getDa();

    printf("%p\n", aux);
    printf("%p\n", &controller.getRepo().getDa());
    auto sortRule = [](Player &s1, Player &s2) {
        return s1.getNumberOfGoals() < s2.getNumberOfGoals();
    };
    std::sort(aux->begin(), aux->end(), sortRule);
    // std::cout << aux->front().toString();
    for (std::vector<Player>::iterator it = aux->begin(); it != aux->end(); it++)
        std::cout << it->toString() << '\n';

    for (int i = 0; i < controller.getRepo().getDa().size(); i++)
        std::cout << controller.getRepo().getDa()[i].toString() << '\n';
    }*/
    return 0;
}