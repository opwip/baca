//Yaroslav Kolesnik
#include "branch.hpp"
#include "tree.hpp"
#include <cstddef>
BRANCH_CLASS::BRANCH_CLASS() {
    this->height = 0;
    this->TreePointer = NULL;
    this->length = 0;
    this->total_weight = 0;
    this->fruits_total = 0;
    this->fruit_list = new NODE_BRANCH();
}
BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS* tree, unsigned int height) {
    this->height = height;
    this->TreePointer = tree;
    this->length = 0;
    this->total_weight = 0;
    this->fruits_total = 0;
    this->fruit_list = new NODE_BRANCH();
    this->TreePointer->addBranch(1);
}
BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS& other) {
    this->length = other.length;
    this->total_weight = other.total_weight;
    this->fruits_total = other.fruits_total;
    this->height = other.height;
    this->fruit_list = NULL;

    NODE_BRANCH* other_current = other.fruit_list;
    NODE_BRANCH* current = NULL;
    NODE_BRANCH* prev = NULL;

    while (other_current != NULL) {
        current = new NODE_BRANCH();


        if (prev == NULL) {
            this->fruit_list = current;
        }
        else {
            prev->next = current;
        }


        if (other_current->data != NULL) {
            current->data = new FRUIT_CLASS(*other_current->data);
            current->data->setBranchPointer(this);
        }
        else {
            current->data = NULL;
        }


        current->next = NULL;


        prev = current;
        other_current = other_current->next;
    }
}

BRANCH_CLASS::~BRANCH_CLASS() {
    this->length = 0;
    if (this->fruit_list != NULL) {
        delete this->fruit_list;
        this->fruit_list = NULL;
    }
    if (this->TreePointer != NULL){
        this->TreePointer->fadeBranch();
        this->TreePointer = NULL;
    }
}

unsigned int BRANCH_CLASS::getFruitsTotal() {
    return this->fruits_total;
}

void BRANCH_CLASS::addFruit() {
    this->fruits_total++;
    if (this->TreePointer != NULL){
        this->TreePointer->addFruit(1);
    }
}

void BRANCH_CLASS::fadeFruit() {
    this->fruits_total--;
    if (this->TreePointer != NULL){
        this->TreePointer->fadeFruit();
    }
}


unsigned int BRANCH_CLASS::getWeightsTotal() {
    return this->total_weight;
}
void BRANCH_CLASS::addWeight() {
    this->total_weight++;
    if (this->TreePointer != NULL){
        this->TreePointer->addWeight(1);
    }
}

void BRANCH_CLASS::fadeWeight(unsigned int weight) {
    this->total_weight -= weight;
    if (this->TreePointer != NULL)
        this->TreePointer->fadeWeight(weight);
}

unsigned int BRANCH_CLASS::getLength() {
    return this->length;
}

void BRANCH_CLASS::addLength() {
    this->length++;
}

void BRANCH_CLASS::fadeLength() {
    if (this->length > 0)
        this->length--;
}

unsigned int BRANCH_CLASS::getHeight() {
    return this->height;
}
void BRANCH_CLASS::setHeight(unsigned int height) {
    this->height = height;
}

void BRANCH_CLASS::growthBranch() {
    addLength();
    NODE_BRANCH* current = this->fruit_list;

    while (current != NULL) {
        if (current->data != NULL) {
            current->data->growthFruit();
        }
        if (current->next == NULL && this->length % 2 == 0) {
            current->next = new NODE_BRANCH();
            current->next->data = new FRUIT_CLASS(this, this->length);
            current->next->data->setBranchPointer(this);
            current->next->next = NULL;
            break;
        }


        current = current->next;
    }

}


void BRANCH_CLASS::fadeBranch() {
    if (this->length > 0) {
        if (this->length % 2 == 0) {
            NODE_BRANCH* current = this->fruit_list;
            NODE_BRANCH* previous = NULL;
            while (current->next != NULL) {
                previous = current;
                current = current->next;
            }
            if (previous != NULL) {
                delete previous->next;

                previous->next = NULL;
            }
            else {
                delete current;
                current - NULL;
                this->fruit_list = NULL;
            }
        }
        fadeLength();
        NODE_BRANCH* current = this->fruit_list;
        while (current != NULL) {
            if (current->data != NULL) {
                current->data->fadeFruit();
            }
            current = current->next;
        }
    }
}


void BRANCH_CLASS::harvestBranch(unsigned int weight) {
    NODE_BRANCH* current = this->fruit_list;
    while (current != NULL) {
        if (current->data != NULL){
            if (current->data->getWeight() >= weight) {
                current->data->pluckFruit();
            }
        }
        current = current->next;
    }
}

void BRANCH_CLASS::cutBranch(unsigned int cut_to_length) {
    if (cut_to_length < this->length){
            this->length = cut_to_length;
            NODE_BRANCH* current = this->fruit_list;
            unsigned int index = 0;
            while (current != NULL) {
                if (index + 2 > cut_to_length) {
                    if (current->next != NULL){
                        delete current->next;
                        current->next = NULL;
                    }
                    break;
                }
                index += 2;
                current = current->next;
        }
    }
}

FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int on_branch_length_index) {
    NODE_BRANCH* current = this->fruit_list;
    while (current != NULL) {

        if (current->data != NULL) {
            if (current->data->getLength() == on_branch_length_index) {
                return current->data;
            }
        }
        current = current->next;
    }
    return NULL;
}

TREE_CLASS* BRANCH_CLASS::getTreePointer() {
    return this->TreePointer;
}
void BRANCH_CLASS::setTreePointer(TREE_CLASS* tree) {
    this->TreePointer = tree;
}