//Yaroslav Kolesnik
#include "garden.hpp"
#include "iostream"
GARDEN_CLASS::GARDEN_CLASS() {
    this->tree_list = new NODE_GARDEN();
    this->trees_total = 0;
    this->branches_total = 0;
    this->total_weight = 0;
    this->fruits_total = 0;
}

GARDEN_CLASS::~GARDEN_CLASS() {
    while (this->tree_list != nullptr) {
        NODE_GARDEN* current = this->tree_list;
        this->tree_list = current->next;
        delete current;
    }
}


unsigned int GARDEN_CLASS::getTreesTotal() {
    return this->trees_total;
}

void GARDEN_CLASS::addTree() {
    this->trees_total++;
}

void GARDEN_CLASS::fadeTree() {
    this->trees_total--;
}

unsigned int GARDEN_CLASS::getBranchesTotal() {
    return this->branches_total;
}

void GARDEN_CLASS::addBranch() {
    this->branches_total++;
}

void GARDEN_CLASS::fadeBranch() {
    this->branches_total--;
}

unsigned int GARDEN_CLASS::getFruitsTotal() {
    return this->fruits_total;
}

void GARDEN_CLASS::addFruit(unsigned int fruits) {
    this->fruits_total += fruits;
}

void GARDEN_CLASS::fadeFruit() {
    this->fruits_total--;
}

unsigned int GARDEN_CLASS::getWeightsTotal() {
    return this->total_weight;
}
void GARDEN_CLASS::addWeight(unsigned int weight) {
    this->total_weight += weight;
}

void GARDEN_CLASS::fadeWeight(unsigned int weight) {
    this->total_weight -= weight;
}

void GARDEN_CLASS::plantTree() {

    NODE_GARDEN* current = this->tree_list;
    NODE_GARDEN* last = nullptr;
    unsigned int locate_lowest_free_id = 0;
    while (current != nullptr) {
        if (current->data != nullptr) {
            if (current->data->getNumber() > locate_lowest_free_id) {
                break;
            }
            locate_lowest_free_id++;
        }
        last = current;
        current = current->next;

    }
    NODE_GARDEN* new_node = new NODE_GARDEN();
    new_node->data = new TREE_CLASS(this, locate_lowest_free_id);

    if (last != nullptr) {
        last->next = new_node;
        new_node->next = current;

    }
    else {
        new_node->next = current;
        this->tree_list = new_node;

    }

    // std::cout << "Tree planted with id " << new_node->data->getNumber() << std::endl;
    this->DISPLAY_TREES();
}

void GARDEN_CLASS::extractTree(unsigned int id) {
    NODE_GARDEN* current = this->tree_list;
    NODE_GARDEN* previous = nullptr;
    while (current != nullptr) {
        if (current->data->getNumber() == id) {
            if (previous != nullptr) {
                previous->next = current->next;
            }
            else {
                this->tree_list = current->next;
            }
            delete current;
            break;
        }
        previous = current;
        current = current->next;
    }
}

void GARDEN_CLASS::growthGarden() {
    NODE_GARDEN* current = this->tree_list;
    std::cout << "GARDEN GROWTH" << std::endl;
    while (current != nullptr) {
        if (current->data != nullptr)
            current->data->growthTree();
        current = current->next;
    }
}


void GARDEN_CLASS::fadeGarden() {
    NODE_GARDEN* current = this->tree_list;
    while (current != nullptr) {
        current->data->fadeTree();
        current = current->next;
    }
}


void GARDEN_CLASS::harvestGarden(unsigned int weight) {
    NODE_GARDEN* current = this->tree_list;
    while (current != nullptr) {
        current->data->harvestTree(weight);
        current = current->next;
    }
}


void GARDEN_CLASS::cloneTree(unsigned int TREE_id) {
    NODE_GARDEN* current = this->tree_list;
    while (current != nullptr) {
        if (current->next == nullptr) {
            delete current->data;
            plantTree();
            break;
        }
        current = current->next;
    }
}


TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int TREE_id) {
    NODE_GARDEN* current = this->tree_list;

    while (current != nullptr) {
        if (current->data != nullptr) {

            if (current->data->getNumber() == TREE_id) {
                std::cout << "Tree ID: " << current->data->getNumber() << std::endl;
                return current->data;
            }
        }
        current = current->next;
    }
    return nullptr;
}

void GARDEN_CLASS::DISPLAY_TREES() {
    NODE_GARDEN* current = this->tree_list;
    while (current != nullptr) {
        if (current->data != nullptr)
            std::cout << "Tree ID: " << current->data->getNumber() << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}