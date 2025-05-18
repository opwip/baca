//Yaroslav Kolesnik

#ifndef GARDEN_HPP
#define GARDEN_HPP
#include "tree.hpp"
struct NODE_GARDEN {
    TREE_CLASS* data;
    NODE_GARDEN* next;

    NODE_GARDEN() : data(nullptr), next(nullptr) {}
    ~NODE_GARDEN() {
        if (data != nullptr) {
            delete data;
            data = nullptr;
        }
        // if (next != nullptr) {
        //     delete next;
        //     next = nullptr;
        // }
    }
};


class GARDEN_CLASS {
private:
    unsigned int trees_total;
    unsigned int branches_total;
    unsigned int total_weight;
    unsigned int fruits_total;
    NODE_GARDEN* tree_list;
public:
    GARDEN_CLASS();
    ~GARDEN_CLASS();
    unsigned int getTreesTotal();
    void addTree();
    void fadeTree();
    unsigned int getBranchesTotal();
    void addBranch();
    void fadeBranch();
    unsigned int getFruitsTotal();
    void addFruit(unsigned int fruits);
    void fadeFruit();
    unsigned int getWeightsTotal();
    void addWeight(unsigned int weight);
    void fadeWeight(unsigned int weight);
    void plantTree();
    void extractTree(unsigned int id);
    void growthGarden();
    void fadeGarden();
    void harvestGarden(unsigned int weight);
    void cutTree(unsigned int height);
    TREE_CLASS* getTreePointer(unsigned int tree_id);
    void cloneTree(unsigned int TREE_id);

    void DISPLAY_TREES();
};

#endif // GARDEN_HPP