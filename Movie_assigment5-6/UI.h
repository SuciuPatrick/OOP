//
// Created by Suciu Patrick on 2019-04-10.
//

#ifndef BACTERIA_TEST_UI_H
#define BACTERIA_TEST_UI_H

#include "Controller.h"

class UI {
private:
    Controller controller;
public:
    bool addElement(Bacteria);
    void startApp();

    UI(const Controller &controller);
};


#endif //BACTERIA_TEST_UI_H
