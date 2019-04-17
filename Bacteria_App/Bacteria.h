//
// Created by Suciu Patrick on 2019-04-10.
//

#ifndef BACTERIA_TEST_BACTERIA_H
#define BACTERIA_TEST_BACTERIA_H
#include <iostream>


class Bacteria {
private:
    std::string name;
    int nrOfOrganism;
    std::string isImmune;
public:
    const std::string &getName() const;

    int getNrOfOrganism() const;

    const std::string &IsImmune() const;

    Bacteria(const std::string &name, int nrOfOrganism, const std::string &isImmune);
    std::string toString() const;

    void setName(const std::string &name);

    void setNrOfOrganism(int nrOfOrganism);

    void setIsImmune(const std::string &isImmune);
};

#endif //BACTERIA_TEST_BACTERIA_H
