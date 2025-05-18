//Yaroslav Kolesnik

#ifndef TREE_HPP
#define TREE_HPP
#include "branch.hpp"
class GARDEN_CLASS;

struct NODE_TREE {
    BRANCH_CLASS* data;
    NODE_TREE* next;

    NODE_TREE() : data(nullptr), next(nullptr) {}
    ~NODE_TREE() {
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
    ~TREE_CLASS();
    unsigned int getBranchesTotal();
    void addBranch();
    void fadeBranch();
    unsigned int getFruitsTotal();
    void addFruit(unsigned int fruits);
    void fadeFruit();
    unsigned int getWeightsTotal();
    void addWeight(unsigned int weight);
    void fadeWeight(unsigned int weight);
    unsigned int getNumber();
    unsigned int getHeight();
    void addHeight();
    void fadeHeight();
    void growthTree();
    void fadeTree();
    void harvestTree(unsigned int weight);
    void cutTree(unsigned int height);
    void cloneBranch(BRANCH_CLASS* branch);
    GARDEN_CLASS* getGardenPointer();
    BRANCH_CLASS* getBranchPointer(unsigned int on_tree_height_index);

    void DISPAY_BRANCHES();
};

#endif // TREE_HPP