//Yaroslav Kolesnik
#include "garden.hpp"
#include "tree.hpp"
#include <cstddef>

NODE_GARDEN::NODE_GARDEN() {
    this->data = NULL;
    this->next = NULL;
}
NODE_GARDEN::~NODE_GARDEN() {
    if (data != NULL) {
        delete data;
        data = NULL;
    }
}

GARDEN_CLASS::GARDEN_CLASS() {
    this->tree_list = new NODE_GARDEN();
    this->next_free_id = 0;
    this->trees_total = 0;
    this->branches_total = 0;
    this->total_weight = 0;
    this->fruits_total = 0;
    this->number_storage = new FREE_NUMBER_STORAGE(0);
}

GARDEN_CLASS::~GARDEN_CLASS() {
    while (this->tree_list != NULL) {
        NODE_GARDEN* current = this->tree_list;
        this->tree_list = current->next;
        delete current;
    }
    while (this->number_storage != NULL) {
        FREE_NUMBER_STORAGE* current = this->number_storage;
        this->number_storage = current->next;
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


// #include <iostream>
// void GARDEN_CLASS::DISPLAY_TREES() {
//     NODE_GARDEN* current = this->tree_list;
//     while (current != NULL) {
//         if (current->data != NULL)
//             std::cout << "Tree ID: " << current->data->getNumber() << " -> ";
//         current = current->next;
//     }
//     std::cout << std::endl;
// }

// void GARDEN_CLASS::DISPLAY_NUMBERS() {
//     FREE_NUMBER_STORAGE* current = this->number_storage;
//     while (current != NULL) {
//         std::cout << "Number ID: " << current->number << " -> ";
//         current = current->next;
//     }
//     std::cout << std::endl;
// }
void GARDEN_CLASS::plantTree() {
    unsigned int locate_lowest_free_id;
    if (this->number_storage->next != NULL) {
        locate_lowest_free_id = this->number_storage->next->number;
        FREE_NUMBER_STORAGE* current = this->number_storage->next;
        if (current->next != NULL) {
            this->number_storage->next = current->next;
        }
        else {
            this->number_storage->next = NULL;
        }
        delete current;
    }
    else {
        locate_lowest_free_id = this->number_storage->number;
        this->number_storage->number++;
    }

    NODE_GARDEN* new_node = new NODE_GARDEN();
    new_node->data = new TREE_CLASS(this, locate_lowest_free_id);
    new_node->next = this->tree_list;
    this->tree_list = new_node;
    // DISPLAY_TREES();
    // DISPLAY_NUMBERS();

}

void GARDEN_CLASS::extractTree(unsigned int id) {
    if (this->getTreePointer(id) == NULL) {
        return;
    }
    NODE_GARDEN* current = this->tree_list;
    NODE_GARDEN* previous = NULL;
    while (current != NULL) {
        if (current->data != NULL) {

            if (current->data->getNumber() == id) {
                FREE_NUMBER_STORAGE* freed = new FREE_NUMBER_STORAGE(id);
                if (this->number_storage->next != NULL) {
                    FREE_NUMBER_STORAGE* current_num = this->number_storage->next;
                    FREE_NUMBER_STORAGE* last_num = this->number_storage;
                    bool found = false;
                    while (current_num != NULL) {
                        if (current_num->number > id) {
                            last_num->next = freed;
                            freed->next = current_num;
                            found = true;
                            break;
                        }
                        last_num = current_num;
                        current_num = current_num->next;

                    }
                    if (!found) {
                        last_num->next = freed;
                    }
                }
                else {
                    this->number_storage->next = freed;
                }
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
    // DISPLAY_TREES();
    // DISPLAY_NUMBERS();
}
// void GARDEN_CLASS::plantTree() {
//     NODE_GARDEN* current = this->tree_list;
//     NODE_GARDEN* last = NULL;
//     unsigned int locate_lowest_free_id = 0;

//     if (current == NULL) {
//         NODE_GARDEN* new_node = new NODE_GARDEN();
//         new_node->data = new TREE_CLASS(this, 0);
//         new_node->next = NULL;
//         this->tree_list = new_node;
//         return;
//     }

//     while (current != NULL) {
//         if (current->data != NULL) {
//             unsigned int current_id = current->data->getNumber();
//             if (current_id > locate_lowest_free_id) {
//                 break;
//             }
//             locate_lowest_free_id++;  
//         }
//         last = current;
//         current = current->next;
//         // DISPLAY_TREES();
//     }

//     NODE_GARDEN* new_node = new NODE_GARDEN();
//     new_node->data = new TREE_CLASS(this, locate_lowest_free_id);

//     if (last != NULL) {
//         new_node->next = current;
//         last->next = new_node;
//     } else {
//         new_node->next = this->tree_list;
//         this->tree_list = new_node;
//     }
// }


// void GARDEN_CLASS::extractTree(unsigned int id) {
//     if (this->getTreePointer(id) == NULL){
//         return;
//     }
//     NODE_GARDEN* current = this->tree_list;
//     NODE_GARDEN* previous = NULL;
//     while (current != NULL) {
//         if (current->data != NULL) {

//             if (current->data->getNumber() == id) {
//                 if (previous != NULL) {
//                     previous->next = current->next;
//                 }
//                 else {
//                     this->tree_list = current->next;
//                 }
//                 delete current;
//                 break;
//             }
//         }
//         previous = current;
//         current = current->next;
//     }
// }

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
        if (current->data != NULL) {
            current->data->harvestTree(weight);
        }
        current = current->next;
    }
}

void GARDEN_CLASS::cloneTree(unsigned int TREE_id) {
    if (this->getTreePointer(TREE_id) == NULL) {
        return;
    }
    unsigned int locate_lowest_free_id;
    if (this->number_storage->next != NULL) {
        locate_lowest_free_id = this->number_storage->next->number;
        FREE_NUMBER_STORAGE* current = this->number_storage->next;
        if (current->next != NULL) {
            this->number_storage->next = current->next;
        }
        else {
            this->number_storage->next = NULL;
        }
        delete current;
    }
    else {
        locate_lowest_free_id = this->number_storage->number;
        this->number_storage->number++;
    }
    NODE_GARDEN* new_node = new NODE_GARDEN();
    new_node->data = new TREE_CLASS(*(this->getTreePointer(TREE_id)));
    new_node->data->setGardenPointer(this);
    new_node->data->setNumber(locate_lowest_free_id);
    new_node->next = this->tree_list;
    this->tree_list = new_node;

    this->addTree();
    this->addBranch(new_node->data->getBranchesTotal());
    this->addFruit(new_node->data->getFruitsTotal());
    this->addWeight(new_node->data->getWeightsTotal());
    // DISPLAY_TREES();
    // DISPLAY_NUMBERS();

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
