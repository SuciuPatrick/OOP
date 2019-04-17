//
// Created by Suciu Patrick on 2019-04-10.
//
#include "UI.h"
#include <sstream>
#include <string>

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

bool UI::addElement(Bacteria bacteria) {
    if (controller.add(bacteria))
        return true;
    return false;
}

void UI::startApp() {
    std::vector<std::string> tokens;
    std::string input, name;

    while (true) {
        getline(std::cin, input);
        tokens = mySplit(input, ',');
        if (tokens[0] == "Exit") {
            std::cout << "da";
            break;
        }
        else if (tokens[0] == "add"){
            bool ok = false;

            for (int i = 0; i < controller.getRepo().getDa().size(); i++)
            {
                if (tokens[1] == controller.getRepo().getDa()[i].getName()) {
                    int nr = controller.getRepo().getDa()[i].getNrOfOrganism();
                    controller.getRepo().getDa()[i].setNrOfOrganism(nr + 1);
                    ok = true;
                }
            }
            if (ok == false) {
                addElement(Bacteria(tokens[1], std::stoi(tokens[2]), tokens[3]));
                std::cout << "Succesfully added.\n";
            }
        }
        else if (tokens[0] == "print"){
            for (int i = 0; i < controller.getRepo().getDa().size(); i++)
                std::cout << controller.getRepo().getDa()[i].toString() << '\n';
        }
        else if (tokens[0] == "sort"){
            std::vector<Bacteria> aux = controller.getRepo().getDa();
            auto sortRule = [](Bacteria &s1, Bacteria &s2) {
                return s1.getName() < s2.getName();
            };
            std::sort(aux.begin(), aux.end(), sortRule);
            for (std::vector<Bacteria>::iterator it = aux.begin(); it != aux.end(); it++)
                std::cout << it->toString() << '\n';
        }
        else if (tokens[0] == "environment") {
            /*
             * If the envir. is equal with sugar the pop will double.
             * If envir is eq with antibiotic
            */
            if (tokens[1] == "sugar")
                for (int i = 0; i < controller.getRepo().getDa().size(); i++)
                {
                    int nr = controller.getRepo().getDa()[i].getNrOfOrganism();
                    controller.getRepo().getDa()[i].setNrOfOrganism(nr * 2);
                }
            if (tokens[1] == "antibiotic"){
                for (int i = 0; i < controller.getRepo().getDa().size(); i++)
                {
                    if (controller.getRepo().getDa()[i].IsImmune() == "false") {
                        int nr = controller.getRepo().getDa()[i].getNrOfOrganism();
                        controller.getRepo().getDa()[i].setNrOfOrganism(nr / 2);
                    }
                }
            }
        }
    }
}

UI::UI(const Controller &controller) : controller(controller) {}
