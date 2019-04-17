//
// Created by Suciu Patrick on 2019-04-10.
//

#include "Bacteria.h"

const std::string &Bacteria::getName() const {
    return name;
}

int Bacteria::getNrOfOrganism() const {
    return nrOfOrganism;
}

const std::string &Bacteria::IsImmune() const {
    return isImmune;
}

Bacteria::Bacteria(const std::string &name, int nrOfOrganism, const std::string &isImmune) : name(name), nrOfOrganism(nrOfOrganism),
                                                                               isImmune(isImmune) {}

std::string Bacteria::toString()const {
    std::string allFields;

    allFields = this->getName() + " " + std::to_string(this->getNrOfOrganism()) + " " +  this->IsImmune();
    return allFields;
}

void Bacteria::setName(const std::string &name) {
    Bacteria::name = name;
}

void Bacteria::setNrOfOrganism(int nrOfOrganism) {
    Bacteria::nrOfOrganism = nrOfOrganism;
}

void Bacteria::setIsImmune(const std::string &isImmune) {
    Bacteria::isImmune = isImmune;
}
