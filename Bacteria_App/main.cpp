#include <iostream>
#include "Bacteria.h"
#include "Controller.h"
#include "UI.h"


void testController()
{
    std::vector<Bacteria> ds;
    Repository rep = Repository(ds);
    Controller c = Controller(rep);

    c.add(Bacteria("xamin", 200, "true"));
    assert(c.getRepo().getDa()[0].getName() == "xamin");
    assert(c.getRepo().getDa()[0].getNrOfOrganism() == 200);
    assert(c.getRepo().getDa()[0].IsImmune() == "true");


}

int main() {
    std::vector<Bacteria> da;
    Repository repo = Repository(da);
    Controller controller = Controller(repo);

    controller.add(Bacteria("xamin", 200, "true"));
    controller.add(Bacteria("E_coli", 100, "false"));
    controller.add(Bacteria("Mycobacterium", 150, "true"));
    controller.add(Bacteria("Steptococ", 200, "false"));

    UI ui = UI(controller);
    ui.startApp();
    //std::cout << a.toString();
    return 0;
}