//Yaroslav Kolesnik
#include "tree.hpp"
#include "branch.hpp"
#include "garden.hpp"
#include <cstddef>

NODE_TREE::NODE_TREE() {
    this->data = NULL;
    this->next = NULL;
}
NODE_TREE::~NODE_TREE() {
    if (data != NULL) {
        delete data;
        data = NULL;
    }
    if (next != NULL) {
        delete next;
        next = NULL;
    }
}

TREE_CLASS::TREE_CLASS() {
    this->id = 0;
    this->branches_list = new NODE_TREE();
    this->height = 0;
    this->branches_total = 0;
    this->total_weight = 0;
    this->fruits_total = 0;
    this->gardenPointer = NULL;
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
TREE_CLASS::TREE_CLASS(const TREE_CLASS& other) {
    this->height = other.height;
    this->branches_total = other.branches_total;
    this->total_weight = other.total_weight;
    this->fruits_total = other.fruits_total;
    this->id = 0;
    this->branches_list = NULL;

    NODE_TREE* other_current = other.branches_list;
    NODE_TREE* current = NULL;
    NODE_TREE* prev = NULL;

    while (other_current != NULL) {
        current = new NODE_TREE();
        if (prev == NULL) {
            this->branches_list = current;
        }
        else {
            prev->next = current;
        }

        if (other_current->data != NULL) {
            current->data = new BRANCH_CLASS(*other_current->data);
            current->data->setHeight(other_current->data->getHeight());
            current->data->setTreePointer(this);
        }
        else {
            current->data = NULL;
        }

        current->next = NULL;
        prev = current;
        other_current = other_current->next;
    }


}


TREE_CLASS::~TREE_CLASS() {
    if (this->branches_list != NULL) {
        delete this->branches_list;
        this->branches_list = NULL;
    }
    if (this->gardenPointer != NULL) {
        this->gardenPointer->fadeTree();
        this->gardenPointer = NULL;
    }
}


unsigned int TREE_CLASS::getBranchesTotal() {
    return this->branches_total;
}

void TREE_CLASS::addBranch(unsigned int branches) {
    this->branches_total += branches;
    if (getGardenPointer() != NULL)
        getGardenPointer()->addBranch(branches);
}

void TREE_CLASS::fadeBranch() {
    this->branches_total--;
    if (getGardenPointer() != NULL)
        getGardenPointer()->fadeBranch();
}

unsigned int TREE_CLASS::getFruitsTotal() {
    return this->fruits_total;
}

void TREE_CLASS::addFruit(unsigned int fruits) {
    this->fruits_total += fruits;
    if (getGardenPointer() != NULL)
        getGardenPointer()->addFruit(fruits);
}

void TREE_CLASS::fadeFruit() {
    this->fruits_total--;
    if (getGardenPointer() != NULL)
        getGardenPointer()->fadeFruit();
}

unsigned int TREE_CLASS::getWeightsTotal() {
    return this->total_weight;
}
void TREE_CLASS::addWeight(unsigned int weight) {
    this->total_weight += weight;
    if (getGardenPointer() != NULL)
        getGardenPointer()->addWeight(weight);
}

void TREE_CLASS::fadeWeight(unsigned int weight) {
    this->total_weight -= weight;
    if (getGardenPointer() != NULL)
        getGardenPointer()->fadeWeight(weight);
}

unsigned int TREE_CLASS::getNumber() {
    return this->id;
}

void TREE_CLASS::setNumber(unsigned int id) {
    this->id = id;
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
    while (current != NULL) {
        if (current->data != NULL) {
            current->data->growthBranch();
        }
        if (current->next == NULL && this->height % 3 == 0 && this->height > 0) {

            current->next = new NODE_TREE();

            current->next->data = new BRANCH_CLASS(this, this->height);

            current->next->next = NULL;
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
            NODE_TREE* previous = NULL;
            while (current->next != NULL) {
                previous = current;
                current = current->next;
            }
            if (previous != NULL) {
                delete current;
                previous->next = NULL;
            }
            else {
                delete current;
                this->branches_list = NULL;
            }
        }

    }
    fadeHeight();
    NODE_TREE* current = this->branches_list;
    while (current != NULL) {
        if (current->data != NULL)
            current->data->fadeBranch();
        current = current->next;
    }
}


void TREE_CLASS::harvestTree(unsigned int weight) {
    NODE_TREE* current = this->branches_list;
    while (current != NULL) {
        if (current->data != NULL) {
            current->data->harvestBranch(weight);
        }
        current = current->next;
    }
}

void TREE_CLASS::cutTree(unsigned int cut_to_height) {
    if (cut_to_height < this->height) {
        this->height = cut_to_height;
        NODE_TREE* current = this->branches_list;
        unsigned int index = 0;
        while (current != NULL) {
            if (index + 3 > cut_to_height) {
                delete current->next;
                current->next = NULL;
                break;
            }
            index += 3;
            current = current->next;
        }

    }
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS* branch) {
    NODE_TREE* current = this->branches_list;
    while (current != NULL) {
        if (current->data != NULL) {
            if (current->data->getLength() == 0) {
                unsigned int branch_height = current->data->getHeight();
                delete current->data;
                current->data = new BRANCH_CLASS(*branch);
                current->data->setHeight(branch_height);
                current->data->getHeight();
                current->data->setTreePointer(this);
                this->addBranch(1);
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
    while (current != NULL) {

        if (current->data != NULL) {
            if (current->data->getHeight() == on_branch_height_index) {
                return current->data;
            }
        }
        current = current->next;
    }
    return NULL;
}

GARDEN_CLASS* TREE_CLASS::getGardenPointer() {
    return this->gardenPointer;
}

void TREE_CLASS::setGardenPointer(GARDEN_CLASS* garden) {
    this->gardenPointer = garden;
}
