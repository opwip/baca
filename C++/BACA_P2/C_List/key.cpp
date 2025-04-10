#include <iostream>

typedef unsigned char BYTE;
typedef int OBJECT_TYPE;
BYTE SIZE = 8;


struct NODE_STRUCT {
    OBJECT_TYPE* object;
    BYTE use;
    NODE_STRUCT* next;
};

NODE_STRUCT* NewNode(void) {
    NODE_STRUCT* node = new NODE_STRUCT;
    node->object = new OBJECT_TYPE[SIZE];
    node->use = 0;
    node->next = NULL;
    return node;
}

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

void DeleteNode(NODE_STRUCT* node) {
    delete[] node->object;
    delete node;
}

void Clear(NODE_STRUCT** node) {
    while (*node != NULL) {
        NODE_STRUCT* temp = *node;
        *node = (*node)->next;
        DeleteNode(temp);
    }
    node = NULL;
}

void AddFirst(NODE_STRUCT** head, OBJECT_TYPE* object_to_add) {
    if (*head == NULL) {  
        NODE_STRUCT* newNode = NewNode();
        *(newNode->object) = *object_to_add;
        newNode->use = 1;
        newNode->next = NULL;
        *head = newNode;
    }
    else if ((*head)->use < SIZE) {  
        for (BYTE i = (*head)->use; i > 0; i--) {
            *((*head)->object + i) = *((*head)->object + i - 1);
        }
        *((*head)->object) = *object_to_add;
        (*head)->use++;
    }
    else { 
        NODE_STRUCT* newNode = NewNode();
        *(newNode->object) = *object_to_add;
        newNode->use = 1;
        newNode->next = *head;
        *head = newNode;
    }
}


void AddLast(NODE_STRUCT** head, OBJECT_TYPE* object_to_add) {
   if (*head == NULL) {  
        NODE_STRUCT* newNode = NewNode();
        *(newNode->object) = *object_to_add;
        newNode->use = 1;
        newNode->next = NULL;
        *head = newNode;
        return;
    }
  
    NODE_STRUCT* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->use < SIZE) {
        *(temp->object + temp->use) = *object_to_add;
        temp->use++;
        return;
    }
    else {
        NODE_STRUCT* newNode = NewNode();
        *(newNode->object) = *object_to_add;
        newNode->use = 1;
        temp->next = newNode;
        newNode->next = NULL;
    }
}

void RemoveCurrent(NODE_STRUCT** head, NODE_STRUCT* node, BYTE obj) {
    if (node == NULL) {
        return;
    }
    if (node->use > 0) {
        for (BYTE i = obj; i < node->use; i++) {
            *(node->object + i - 1) = *(node->object + i);
        }
        node->use--;
    }
    else {
        NODE_STRUCT* temp = *head;
        while (temp != NULL && temp->next != node) {
            temp = temp->next;
        }
        if (temp != NULL) {
            temp->next = node->next;
            DeleteNode(node);
        }
    }
    if (node->use == 0) {
        NODE_STRUCT* temp = *head;
        while (temp != NULL && temp->next != node) {
            temp = temp->next;
        }
        if (temp != NULL) {
            temp->next = node->next;
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
    // int arr[SIZE*3 - 1];
    // for (int i = 0; i < (SIZE*3-1); i++){
    //     arr[i] = i+1;
    // }
    // NODE_STRUCT* head = NewNode();
    // for (int i = 0; i < 8; i++) {
    //     // PrintList(head);
    //     AddLast(&head, &arr[i]);

    // }
    // PrintAll(head);
    // std::cout << head << std::endl;
    // for (int i = 0; i < 3; i++) {
    //     // PrintList(head);
    //     AddFirst(&head, &arr[i]);

    // }
    
    // PrintAll(head);
    // std::cout << head << std::endl;
    // NODE_STRUCT* rem = head->next;
    // RemoveCurrent(&head, rem, 3);

    // PrintAll(head);
    // std::cout << head << std::endl;
    // Clear(&head);
    // PrintAll(head);
    // std::cout << head << std::endl;
    // return 0;
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    
    // Start with an empty list
    NODE_STRUCT* head = NULL;

    // Add elements as per the test input
    AddFirst(&head, &values[0]);  // AF 1
    PrintAll(head); 
    AddLast(&head, &values[1]);   // AL 2
    PrintAll(head); 
    AddFirst(&head, &values[2]);  // AF 3
    PrintAll(head); 
    AddLast(&head, &values[3]);   // AL 4
    PrintAll(head); 
    AddFirst(&head, &values[4]);  // AF 5
    PrintAll(head); 
    AddLast(&head, &values[5]);   // AL 6
    PrintAll(head); 
    AddFirst(&head, &values[6]);  // AF 7
    PrintAll(head); 
    AddLast(&head, &values[7]);   // AL 8
    PrintAll(head); 
    AddFirst(&head, &values[8]);  // AF 9
    PrintAll(head); 
    AddLast(&head, &values[9]);   // AL 10
    PrintAll(head); 
    AddFirst(&head, &values[10]); // AF 11
    PrintAll(head); 
    AddLast(&head, &values[11]);  // AL 12
    PrintAll(head); 
    AddFirst(&head, &values[12]); // AF 13
    PrintAll(head); 
    AddLast(&head, &values[13]);  // AL 14
    PrintAll(head); 
    AddFirst(&head, &values[14]); // AF 15
    PrintAll(head); 
    AddLast(&head, &values[15]);  // AL 16

    // Print the list
    PrintAll(head);               // P

    // Clean up memory before quitting
    Clear(&head);

    // Quit
    return 0;                     // Q
}