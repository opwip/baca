//Yaroslav Kolesnik
#include "garden.hpp"
#include <cstddef>
GARDEN_CLASS::GARDEN_CLASS() {
    this->tree_list = new NODE_GARDEN();
    this->next_free_id = 0;
    this->trees_total = 0;
    this->branches_total = 0;
    this->total_weight = 0;
    this->fruits_total = 0;
}

GARDEN_CLASS::~GARDEN_CLASS() {
    while (this->tree_list != NULL) {
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

void GARDEN_CLASS::addBranch(unsigned int branches) {
    this->branches_total += branches;
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
    NODE_GARDEN* last = NULL;
    unsigned int locate_lowest_free_id = 0;
    while (current != NULL) {
        if (current->data != NULL) {
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

    if (last != NULL) {
        last->next = new_node;
        new_node->next = current;

    }
    else {
        new_node->next = current;
        this->tree_list = new_node;

    }
} 
// #include <iostream>
// void GARDEN_CLASS::DISPLAY_TREES() {
//     NODE_GARDEN* current = this->tree_list;
//     while (current != nullptr) {
//         if (current->data != nullptr)
//             std::cout << "Tree ID: " << current->data->getNumber() << " -> ";
//         current = current->next;
//     }
//     std::cout << std::endl;
// }
// void GARDEN_CLASS::plantTree() {
//     // Create new node with the next available ID
//     NODE_GARDEN* new_node = new NODE_GARDEN();
//     new_node->data = new TREE_CLASS(this, next_free_id);

//     // Insert at the head of the list
//     new_node->next = this->tree_list;
//     this->tree_list = new_node;

//     // Increment the next available ID
//     next_free_id++;
//     DISPLAY_TREES();

// }
// void GARDEN_CLASS::extractTree(unsigned int id) {
//     NODE_GARDEN* current = this->tree_list;
//     NODE_GARDEN* prev = nullptr;

//     // Search for the node with the given ID
//     while (current != nullptr && current->data->getNumber() != id) {
//         prev = current;
//         current = current->next;
//     }

//     // Check if we found the node
//     if (current != nullptr) {
//         // Update next_free_id if the removed ID is lower
//         if (current->data->getNumber() < next_free_id) {
//             next_free_id = current->data->getNumber();
//         }

//         // Remove the node
//         if (prev != nullptr) {
//             prev->next = current->next;
//         }
//         else {
//             this->tree_list = current->next;
//         }
//         delete current;
//     }
//     DISPLAY_TREES();
//     std::cout << "Free ID " <<  this->next_free_id << std::endl;
// }
void GARDEN_CLASS::extractTree(unsigned int id) {
    NODE_GARDEN* current = this->tree_list;
    NODE_GARDEN* previous = NULL;
    while (current != NULL) {
        if (current->data != NULL) {

            if (current->data->getNumber() == id) {
                if (previous != NULL) {
                    previous->next = current->next;
                }
                else {
                    this->tree_list = current->next;
                }
                delete current;
                break;
            }
        }
        previous = current;
        current = current->next;
    }
}

void GARDEN_CLASS::growthGarden() {
    NODE_GARDEN* current = this->tree_list;
    while (current != NULL) {
        if (current->data != NULL)
            current->data->growthTree();
        current = current->next;
    }
}


void GARDEN_CLASS::fadeGarden() {
    NODE_GARDEN* current = this->tree_list;

    while (current != NULL) {
        if (current->data != NULL)
            current->data->fadeTree();

        current = current->next;
    }
}


void GARDEN_CLASS::harvestGarden(unsigned int weight) {
    NODE_GARDEN* current = this->tree_list;
    while (current != NULL) {
        current->data->harvestTree(weight);
        current = current->next;
    }
}

void GARDEN_CLASS::cloneTree(unsigned int TREE_id) {
    NODE_GARDEN* current = this->tree_list;
    NODE_GARDEN* last = NULL;
    unsigned int locate_lowest_free_id = 0;
    while (current != NULL) {
        if (current->data != NULL) {
            if (current->data->getNumber() > locate_lowest_free_id) {
                break;
            }
            locate_lowest_free_id++;
        }
        last = current;
        current = current->next;

    }
    NODE_GARDEN* new_node = new NODE_GARDEN();
    new_node->data = new TREE_CLASS(*(this->getTreePointer(TREE_id)));
    new_node->data->setGardenPointer(this);
    new_node->data->setNumber(locate_lowest_free_id);

    if (last != NULL) {
        last->next = new_node;
        new_node->next = current;

    }
    else {
        new_node->next = current;
        this->tree_list = new_node;

    }
    this->addTree();
    this->addBranch(new_node->data->getBranchesTotal());
    this->addFruit(new_node->data->getFruitsTotal());
    this->addWeight(new_node->data->getWeightsTotal());
}
TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int TREE_id) {
    NODE_GARDEN* current = this->tree_list;

    while (current != NULL) {
        if (current->data != NULL) {
            if (current->data->getNumber() == TREE_id) {
                return current->data;
            }
        }
        current = current->next;
    }
    return NULL;
}
