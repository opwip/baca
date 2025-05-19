//Yaroslav Kolesnik

#ifndef TREE_HPP
#define TREE_HPP
#include "branch.hpp"
#include <cstddef>
class GARDEN_CLASS;

struct NODE_TREE {
    BRANCH_CLASS* data;
    NODE_TREE* next;

    NODE_TREE() : data(NULL), next(NULL) {}
    ~NODE_TREE() {
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

class TREE_CLASS {
private:
    unsigned int id;
    unsigned int height;
    unsigned int branches_total;
    unsigned int total_weight;
    unsigned int fruits_total;
    NODE_TREE* branches_list;
    GARDEN_CLASS* gardenPointer;
public:
    TREE_CLASS();
    TREE_CLASS(GARDEN_CLASS* garden, unsigned int id);
    TREE_CLASS(const TREE_CLASS& other);
    ~TREE_CLASS();
    unsigned int getBranchesTotal();
    void addBranch(unsigned int branches);
    void fadeBranch();
    unsigned int getFruitsTotal();
    void addFruit(unsigned int fruits);
    void fadeFruit();
    unsigned int getWeightsTotal();
    void addWeight(unsigned int weight);
    void fadeWeight(unsigned int weight);
    unsigned int getNumber();
    void setNumber(unsigned int id);
    unsigned int getHeight();
    void addHeight();
    void fadeHeight();
    void growthTree();
    void fadeTree();
    void harvestTree(unsigned int weight);
    void cutTree(unsigned int height);
    void cloneBranch(BRANCH_CLASS* branch);
    GARDEN_CLASS* getGardenPointer();
    void setGardenPointer(GARDEN_CLASS* garden);

    BRANCH_CLASS* getBranchPointer(unsigned int on_tree_height_index);
};

#endif // TREE_HPP