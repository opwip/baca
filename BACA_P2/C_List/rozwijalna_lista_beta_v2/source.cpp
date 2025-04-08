// Yaroslav Kolesnik


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
    while (*node != NULL) {
        NODE_STRUCT* temp = *node;
        *node = (*node)->next;
        DeleteNode(temp);
    }
}

void AddFirst(NODE_STRUCT** head, OBJECT_TYPE* object_to_add) {
    if ((*head)->use < SIZE) {
        for (BYTE i = (*head)->use; i > 0; i--) {
            *((*head)->object + i) = *((*head)->object + i - 1);
        }
        *((*head))->object = *object_to_add;
        (*head)->use++;
    }
    else if ((*head) == NULL) {
        NODE_STRUCT* newNode = NewNode();
        *(newNode->object) = *object_to_add;
        newNode->use = 1;
        newNode->next = NULL;
        *head = newNode;
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