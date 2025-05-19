//Yaroslav Kolesnik

#ifndef FRUIT_HPP
#define FRUIT_HPP
#include <cstddef>
class BRANCH_CLASS;

class FRUIT_CLASS {
private:
    unsigned int weight;
    unsigned int length;
    BRANCH_CLASS* branchPointer;
public:
    FRUIT_CLASS(BRANCH_CLASS* branch, unsigned int length);
    FRUIT_CLASS(const FRUIT_CLASS& other);
    ~FRUIT_CLASS();
    unsigned int getLength();
    unsigned int getWeight();
    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    void setBranchPointer(BRANCH_CLASS* branch);
    BRANCH_CLASS* getBranchPointer();
};

#endif 