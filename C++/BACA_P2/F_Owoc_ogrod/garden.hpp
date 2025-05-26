//Yaroslav Kolesnik

#include <cstddef>
class TREE_CLASS;
struct NODE_GARDEN {
    TREE_CLASS* data;
    NODE_GARDEN* next;

    NODE_GARDEN();
    ~NODE_GARDEN();
};

struct FREE_NUMBER_STORAGE{
    unsigned int number;
    FREE_NUMBER_STORAGE* next;
    FREE_NUMBER_STORAGE(unsigned int number1){
        number = number1;
        next = NULL;
    } 
    ~FREE_NUMBER_STORAGE(){
        number = 0;
        next = NULL;
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
    FREE_NUMBER_STORAGE* number_storage;
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
    void DISPLAY_NUMBERS();
};
