//Yaroslav Kolesnik

#include "tree.hpp"
#include "garden.hpp"
#include "iostream"
TREE_CLASS::TREE_CLASS() {
    this->id = 0;
    this->branches_list = new NODE_TREE();
    this->height = 0;
    this->branches_total = 0;
    this->total_weight = 0;
    this->fruits_total = 0;
    this->gardenPointer = nullptr;
}
TREE_CLASS::TREE_CLASS(GARDEN_CLASS* garden, unsigned int id) {
    this->id = id;
    this->gardenPointer = garden;
    this->branches_list = new NODE_TREE();
    this->height = 0;
    this->branches_total = 0;
    this->total_weight = 0;
    this->fruits_total = 0;
    this->gardenPointer->addTree();
}

TREE_CLASS::~TREE_CLASS() {
    if (this->branches_list != nullptr) {
        delete this->branches_list;
        this->branches_list = nullptr;
    }
    if (this->gardenPointer != nullptr) {
        this->gardenPointer->fadeTree();
        this->gardenPointer = nullptr;
    }
}


unsigned int TREE_CLASS::getBranchesTotal() {
    return this->branches_total;
}

void TREE_CLASS::addBranch() {
    this->branches_total++;
    if (getGardenPointer() != nullptr)
        getGardenPointer()->addBranch();
}

void TREE_CLASS::fadeBranch() {
    this->branches_total--;
    if (getGardenPointer() != nullptr)
        getGardenPointer()->fadeBranch();
}

unsigned int TREE_CLASS::getFruitsTotal() {
    return this->fruits_total;
}

void TREE_CLASS::addFruit(unsigned int fruits) {
    this->fruits_total += fruits;
    if (getGardenPointer() != nullptr)
        getGardenPointer()->addFruit(fruits);
}

void TREE_CLASS::fadeFruit() {
    this->fruits_total--;
    if (getGardenPointer() != nullptr)
        getGardenPointer()->fadeFruit();
}

unsigned int TREE_CLASS::getWeightsTotal() {
    return this->total_weight;
}
void TREE_CLASS::addWeight(unsigned int weight) {
    this->total_weight += weight;
    if (getGardenPointer() != nullptr)
        getGardenPointer()->addWeight(weight);
}

void TREE_CLASS::fadeWeight(unsigned int weight) {
    this->total_weight -= weight;
    if (getGardenPointer() != nullptr)
        getGardenPointer()->fadeWeight(weight);
}

unsigned int TREE_CLASS::getNumber() {
    return this->id;
}

unsigned int TREE_CLASS::getHeight() {
    return this->height;
}
void TREE_CLASS::addHeight() {
    this->height++;
}

void TREE_CLASS::fadeHeight() {
    if (this->height > 0)
        this->height--;
}


void TREE_CLASS::growthTree() {
    addHeight();
    NODE_TREE* current = this->branches_list;
    while (current != nullptr) {
        if (current->data != nullptr) {
            current->data->growthBranch();
        }
        if (current->next == nullptr && this->height % 3 == 0) {

            current->next = new NODE_TREE();

            current->next->data = new BRANCH_CLASS(this, this->height);

            current->next->next = nullptr;
            break;
        }

        current = current->next;
    }

}

// TODO BUG FIX FADE TREE (RUN MAIN.cpp) using g++ main.cpp fruit.cpp branch.cpp tree.cpp garden.cpp
void TREE_CLASS::fadeTree() {
    if (this->height > 0) {
        if (this->height % 3 == 0) {
            NODE_TREE* current = this->branches_list;
            while (current != nullptr) {
                if (current->next != nullptr) {
                    if (current->next->next == nullptr) {
                        delete current->next;
                        current->next = nullptr;
                        break;
                    }
                }
                current = current->next;
            }

        }
        fadeTree();
        NODE_TREE* current = this->branches_list;
        while (current != nullptr) {
            current->data->fadeBranch();
            current = current->next;
        }
    }
}


void TREE_CLASS::harvestTree(unsigned int weight) {
    NODE_TREE* current = this->branches_list;
    while (current != nullptr) {
        current->data->harvestBranch(weight);
        current = current->next;
    }
}

void TREE_CLASS::cutTree(unsigned int cut_to_height) {
    if (cut_to_height > 0 && cut_to_height <= this->height) {
        this->height = cut_to_height;
        NODE_TREE* current = this->branches_list;
        unsigned int index = 3;
        while (current != nullptr) {
            if (index + 3 > cut_to_height) {
                delete current->next;
                current->next = nullptr;
                break;
            }
            index += 3;
            current = current->next;
        }

    }
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS* branch) {
    NODE_TREE* current = this->branches_list;
    while (current != nullptr) {
        if (current->data != nullptr) {
            DISPAY_BRANCHES();
            if (current->data->getLength() == 0) {
                unsigned int branch_height = current->data->getHeight();
                delete current->data;
                current->data = new BRANCH_CLASS(*branch);
                current->data->setHeight(branch_height);
                current->data->getHeight();
                current->data->setTreePointer(this);
                this->addBranch();
                this->addFruit(current->data->getFruitsTotal());
                this->addWeight(current->data->getWeightsTotal());

                break;
            }

        }
        current = current->next;
    }
}


BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int on_branch_height_index) {
    NODE_TREE* current = this->branches_list;
    while (current != nullptr) {

        if (current->data != nullptr) {
            if (current->data->getHeight() == on_branch_height_index) {
                return current->data;
            }
        }
        current = current->next;
    }
    return nullptr;
}

GARDEN_CLASS* TREE_CLASS::getGardenPointer() {
    return this->gardenPointer;
}

void TREE_CLASS::DISPAY_BRANCHES() {
    NODE_TREE* current = this->branches_list;
    while (current != nullptr) {
        if (current->data != nullptr)
            std::cout << "Branch ID: " << current->data->getHeight() << " Branch adress " << current->data << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}