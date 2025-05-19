//Yaroslav Kolesnik

#ifndef GARDEN_HPP
#define GARDEN_HPP
#include "tree.hpp"
#include <cstddef>
struct NODE_GARDEN {
    TREE_CLASS* data;
    NODE_GARDEN* next;

    NODE_GARDEN() : data(NULL), next(NULL) {}
    ~NODE_GARDEN() {
        if (data != NULL) {
            delete data;
            data = NULL;
        }

    }
};


class GARDEN_CLASS {
private:
    unsigned int trees_total;
    unsigned int branches_total;
    unsigned int total_weight;
    unsigned int fruits_total;
    unsigned int next_free_id;
    NODE_GARDEN* tree_list;
public:
    GARDEN_CLASS();
    ~GARDEN_CLASS();
    unsigned int getTreesTotal();
    void addTree();
    void fadeTree();
    unsigned int getBranchesTotal();
    void addBranch(unsigned int branches);
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