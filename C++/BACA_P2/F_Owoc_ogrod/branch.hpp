//Yaroslav Kolesnik
#ifndef BRANCH_HPP
#define BRANCH_HPP
#include "fruit.hpp"
#include <cstddef>
class TREE_CLASS;

struct NODE_BRANCH {
    FRUIT_CLASS* data;
    NODE_BRANCH* next;

    NODE_BRANCH() : data(NULL), next(NULL) {}
    ~NODE_BRANCH() {
        if (data != NULL) {
            delete data;
            data = NULL;
        }
        if (next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class BRANCH_CLASS {
private:
    unsigned int length;
    unsigned int height;
    unsigned int total_weight;
    unsigned int fruits_total;
    NODE_BRANCH* fruit_list;
    TREE_CLASS* TreePointer;
public:
    BRANCH_CLASS(TREE_CLASS* tree, unsigned int height);
    BRANCH_CLASS(const BRANCH_CLASS& other);
    ~BRANCH_CLASS();
    unsigned int getFruitsTotal();
    void addFruit();
    void fadeFruit();
    unsigned int getWeightsTotal();
    void addWeight();
    void fadeWeight(unsigned int weight);
    unsigned int getHeight();
    void setHeight(unsigned int height);
    unsigned int getLength();
    void addLength();
    void fadeLength();
    void growthBranch();
    void fadeBranch();
    void harvestBranch(unsigned int weight);
    void cutBranch(unsigned int length);
    FRUIT_CLASS* getFruitPointer(unsigned int on_branch_length_index);
    TREE_CLASS* getTreePointer();
    void setTreePointer(TREE_CLASS* tree);
};

#endif // BRANCH_HPP