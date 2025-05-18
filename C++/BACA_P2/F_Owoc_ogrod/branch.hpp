//Yaroslav Kolesnik
#ifndef BRANCH_HPP
#define BRANCH_HPP
#include "fruit.hpp"
class TREE_CLASS;

struct NODE_BRANCH {
    FRUIT_CLASS* data;
    NODE_BRANCH* next;

    NODE_BRANCH() : data(nullptr), next(nullptr) {}
    ~NODE_BRANCH() {
        if (data != nullptr) {
            delete data;
            data = nullptr;
        }
        if (next != nullptr) {
            delete next;
            next = nullptr;
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
    BRANCH_CLASS(BRANCH_CLASS& other);
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