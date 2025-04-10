#include <iostream>

typedef unsigned char BYTE;
typedef int OBJECT_TYPE;
BYTE SIZE = 4;


struct NODE_STRUCT {
    OBJECT_TYPE* object;
    BYTE use;
    NODE_STRUCT* next;
};

void PrintList(NODE_STRUCT* head) {
    while (head != NULL) {
        for (BYTE i = 0; i < head->use; i++) {
            std::cout << *(head->object + i) << " ";
        }
        std::cout << std::endl;
        head = head->next;
    }
}

void PrintAll(NODE_STRUCT* head) {
    while (head != NULL) {
        for (BYTE i = 0; i < head->use; i++) {
            std::cout << *(head->object + i) << " ";
        }
        std::cout << "NODE " << std::endl;
        head = head->next;
    }
}


NODE_STRUCT* NewNode(void) {
    NODE_STRUCT* node = new NODE_STRUCT;
    node->object = new OBJECT_TYPE[SIZE];
    node->use = 0;
    node->next = NULL;
    return node;
}

void DeleteNode(NODE_STRUCT* node) {
    delete[] node->object;
    delete node;
}

void Clear(NODE_STRUCT** node) {
    if (*node == NULL) {
        return;
    }
<<<<<<< Updated upstream
    // node = NULL;
=======
    while (*node) {
        NODE_STRUCT* temp = (*node)->next;
        DeleteNode(*node);
        *node = temp;
    }
    node = NULL;
>>>>>>> Stashed changes
}

void AddFirst(NODE_STRUCT** node, OBJECT_TYPE* obj) {
    NODE_STRUCT* newNode;
    if (node == NULL || (*node)->use == SIZE) {
        newNode = NewNode();
        newNode->next = (*node);
        *node = newNode;
    }
    else {
        newNode = *node;
        for (BYTE i = newNode->use; i > 0; --i) {
            *(newNode->object + i) = *(newNode->object + i - 1);
        }
    }
    *(newNode->object) = *obj;
    newNode->use++;
}

void AddLast(NODE_STRUCT** node, OBJECT_TYPE* obj) {
    if (node == NULL) {
        *node = NewNode();
        *((*node)->object) = *obj;
        (*node)->use = 1;
        return;
    }
    NODE_STRUCT* lastNode = *node;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    if (lastNode->use < SIZE) {
        *(lastNode->object + lastNode->use) = *obj;
        lastNode->use++;
    }
    else {
        NODE_STRUCT* newNode = NewNode();
        *(newNode->object) = *obj;
        newNode->use = 1;
        lastNode->next = newNode;
    }
}

void GetFirst(NODE_STRUCT* node, NODE_STRUCT** node_ptr, BYTE* object) {
    *node_ptr = node;
    if (node != NULL) {
        *object = 0;
    }
}

void GetLast(NODE_STRUCT* node, NODE_STRUCT** node_ptr, BYTE* object) {
    *node_ptr = node;
    if (node == NULL) {
        return;
    }
    while (node->next != NULL) {
        node = node->next;
    }
    *node_ptr = node;
    if (node->use > 0) {
        *object = node->use - 1;
    }
    else {
        *object = 0;
    }
}

void RemoveCurrent(NODE_STRUCT** head, NODE_STRUCT* node, BYTE obj) {
    if (node == NULL || obj < 0 || obj >= node->use) {
        return;
    }
    for (BYTE i = obj; i < node->use - 1; i++) {
        *(node->object + i) = *(node->object + i + 1);
    }
    node->use--;
    if (node->use == 0) {
        if (*head == node) {
            *head = node->next;
            DeleteNode(node);
        }
        else {
            NODE_STRUCT* current = *head;
            while (current->next != node) {
                current = current->next;
            }
            current->next = node->next;
            DeleteNode(node);
        }
    }
}

void InsertNext(){
    //ALWAYS CREATS NEW NODE IF USE == SIZE WITH USE = 1
}

void Reverse(){
    //GET HEAD AND TAIL AND SWAP ELEMENTS USING 2 POINTERS REVERSE METHOD 
}

int main() {
    int arr[SIZE*3 - 1];
    for (int i = 0; i < (SIZE*3-1); i++){
        arr[i] = i+1;
    }
    NODE_STRUCT* head = NewNode();
    for (int i = 0; i < 8; i++) {
        // PrintList(head);
        AddLast(&head, &arr[i]);

    }
    PrintAll(head);
    std::cout << head << std::endl;
    for (int i = 0; i < 3; i++) {
        // PrintList(head);
        AddFirst(&head, &arr[i]);

    }
    
    PrintAll(head);
    std::cout << head << std::endl;
    NODE_STRUCT* rem = head->next;
    RemoveCurrent(&head, rem, 3);

    PrintAll(head);
    std::cout << head << std::endl;
    Clear(&head);
    PrintAll(head);
    std::cout << head << std::endl;
    return 0;
}