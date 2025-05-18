//Yaroslav Kolesnik
#include "branch.hpp"
#include "tree.hpp"
#include "iostream"
BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS* tree, unsigned int height) {
    this->height = height;
    this->TreePointer = tree;
    this->length = 0;
    this->total_weight = 0;
    this->fruits_total = 0;
    this->fruit_list = new NODE_BRANCH();
    this->TreePointer->addBranch();
}
BRANCH_CLASS::BRANCH_CLASS(BRANCH_CLASS& other) {
    NODE_BRANCH* current = new NODE_BRANCH();
    this->fruit_list = current;
    this->length = other.length;
    this->total_weight = other.total_weight;
    this->fruits_total = other.fruits_total;
    this->height = 0;
    NODE_BRANCH* other_current = other.fruit_list;

    while (other_current != nullptr) {
        if (other_current->data != nullptr) {

            current->data = new FRUIT_CLASS(*other_current->data);
            current->data->setBranchPointer(this);
        }
        else {
            current->data = nullptr;
        }
        current->next = new NODE_BRANCH();
        current = current->next;
        other_current = other_current->next;
    }
    current->next = nullptr;
}

BRANCH_CLASS::~BRANCH_CLASS() {
    this->length = 0;
    if (this->fruit_list != nullptr) {
        delete this->fruit_list;
        this->fruit_list = nullptr;
    }
    this->TreePointer->fadeBranch();
}

unsigned int BRANCH_CLASS::getFruitsTotal() {
    return this->fruits_total;
}

void BRANCH_CLASS::addFruit() {
    this->fruits_total++;
    getTreePointer()->addFruit(1);
}

void BRANCH_CLASS::fadeFruit() {
    this->fruits_total--;
    getTreePointer()->fadeFruit();
}


unsigned int BRANCH_CLASS::getWeightsTotal() {
    return this->total_weight;
}
void BRANCH_CLASS::addWeight() {
    this->total_weight++;
    getTreePointer()->addWeight(1);
}

void BRANCH_CLASS::fadeWeight(unsigned int weight) {
    this->total_weight -= weight;
    getTreePointer()->fadeWeight(weight);
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

    while (current != nullptr) {
        if (current->data != nullptr) {
            current->data->growthFruit();
        }
        if (current->next == nullptr && this->length % 2 == 0) {
            current->next = new NODE_BRANCH();
            current->next->data = new FRUIT_CLASS(this, this->length);
            current->next->next = nullptr;
            break;
        }

        current = current->next;
    }

}


void BRANCH_CLASS::fadeBranch() {
    if (this->length > 0) {
        if (this->length % 2 == 0) {
            NODE_BRANCH* current = this->fruit_list;
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
        fadeLength();
        NODE_BRANCH* current = this->fruit_list;
        while (current != nullptr) {
            current->data->fadeFruit();
            current = current->next;
        }
    }
}


void BRANCH_CLASS::harvestBranch(unsigned int weight) {
    NODE_BRANCH* current = this->fruit_list;
    while (current != nullptr) {
        FRUIT_CLASS* fruit = current->data;
        if (fruit->getWeight() >= weight) {
            fruit->pluckFruit();
        }
        current = current->next;
    }
}

void BRANCH_CLASS::cutBranch(unsigned int cut_to_length) {
    if (cut_to_length >= 0) {

        this->length = cut_to_length;
        NODE_BRANCH* current = this->fruit_list;
        unsigned int index = 2;

        while (current != nullptr) {
            if (index + 2 > cut_to_length) {
                delete current->next;
                current->next = nullptr;
                break;
            }
            index += 2;
            current = current->next;
        }

    }
}

FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int on_branch_length_index) {
    unsigned int index = 1;
    NODE_BRANCH* current = this->fruit_list;
    while (current != nullptr && index <= on_branch_length_index) {
        if (index % 2 == 0) {
            if (index == on_branch_length_index) {
                return current->data;
            }
            current = current->next;
        }
        index++;
    }
    return nullptr;
}

TREE_CLASS* BRANCH_CLASS::getTreePointer() {
    return this->TreePointer;
}
void BRANCH_CLASS::setTreePointer(TREE_CLASS* tree) {
    this->TreePointer = tree;
}