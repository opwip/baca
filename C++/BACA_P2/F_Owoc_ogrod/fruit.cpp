//Yaroslav Kolesnik

#include "fruit.hpp"
#include "branch.hpp"
#include <cstddef>

FRUIT_CLASS::FRUIT_CLASS(BRANCH_CLASS* branch, unsigned int length) {
    this->length = length;
    this->weight = 0;
    this->branchPointer = branch;
    this->branchPointer->addFruit();
}
FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS& other) {
    this->length = other.length;
    this->weight = other.weight;
}
FRUIT_CLASS::~FRUIT_CLASS() {
    pluckFruit();
    this->branchPointer->fadeFruit();
    this->branchPointer = NULL;
}
unsigned int FRUIT_CLASS::getLength() {
    return this->length;
}
unsigned int FRUIT_CLASS::getWeight() {
    return this->weight;
}

void FRUIT_CLASS::growthFruit() {
    this->weight++;
    this->branchPointer->addWeight();
}
void FRUIT_CLASS::fadeFruit() {
    if (this->weight > 0) {
        this->weight--;
        this->branchPointer->fadeWeight(1);
    }
}
void FRUIT_CLASS::pluckFruit() {
    this->branchPointer->fadeWeight(this->weight);
    this->weight = 0;
}

BRANCH_CLASS* FRUIT_CLASS::getBranchPointer() {
    return this->branchPointer;
}
void FRUIT_CLASS::setBranchPointer(BRANCH_CLASS* branch) {
    this->branchPointer = branch;
}
