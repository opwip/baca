//Yaroslav Kolesnik
NODE_STRUCT* NewNode() {
    NODE_STRUCT* node = new NODE_STRUCT;
    node->object = new OBJECT_TYPE[SIZE];
    node->use = 0;
    node->next = NULL;
    return node;
}

void DeleteNode(NODE_STRUCT* node) {
    if (node != NULL){
        delete[] node->object;
        delete node;
    }
}

void Clear(NODE_STRUCT** node) {
    if (*node == NULL){
        return;
    }
    Clear(&((*node)->next));
    DeleteNode(*node);
    *node = NULL;
}

void AddFirst(NODE_STRUCT** head, OBJECT_TYPE* object_to_add) {
    NODE_STRUCT* newNode;
    if (*head == NULL || (*head)->use == SIZE) {  
        newNode = NewNode();
        newNode->next = *head;
        *head = newNode;
    }
    else { 
        newNode = *head;
        for (BYTE i = newNode->use; i>0; --i){
            *(newNode->object+i) = *(newNode->object + i - 1);
        }
    }
    *(newNode->object) = *object_to_add;
    newNode->use++;
}


void AddLast(NODE_STRUCT** head, OBJECT_TYPE* object_to_add) {
   if (*head == NULL) {  
        *head = NewNode();
        *(*head)->object = *object_to_add;
        (*head)->use = 1;
        return;
    }
    
    NODE_STRUCT* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->use < SIZE) {
        *(temp->object + temp->use) = *object_to_add;
        temp->use++;
    }
    else {
        NODE_STRUCT* newNode = NewNode();
        *newNode->object = *object_to_add;
        newNode->use = 1;
        temp->next = newNode;
    }
}

void GetFirst(NODE_STRUCT* node, NODE_STRUCT** res, BYTE* obj){
    *res = node;
    if (node){
        *obj = 0;
    }
}

void GetLast(NODE_STRUCT* node, NODE_STRUCT** res, BYTE* obj){
    *res = node;
    if (node == NULL){
        return;
    }
    while (node->next != NULL) {
        node = node->next;
    }
    *res = node;
    if (node->use > 0){
        *obj = node->use -1;
    }
    else{
        *obj = 0;
    }
}

void GetPrev(NODE_STRUCT* head, NODE_STRUCT* node, BYTE obj, NODE_STRUCT** res_node, BYTE* res_obj ){
    if (obj > 0) {
        *res_node = node;
        *res_obj = obj - 1;
        return;
    }
    if (head == node && obj == 0) {
        *res_node = NULL; 
        return;
    }
    NODE_STRUCT* current = head;
    while (current && current->next != node) {
        current = current->next;
    }
    if (current) {
        *res_node = current;
        *res_obj = current->use > 0 ? current->use - 1 : 0;
    }
    else {
        *res_node = NULL; 
    }


}


void GetNext(NODE_STRUCT* head, NODE_STRUCT* node, BYTE obj, NODE_STRUCT** res_node, BYTE* res_obj) {
    
    if (obj < node->use - 1) {
        *res_node = node;
        *res_obj = obj + 1;
        return;
    }
    if (node->next != NULL) {
        *res_node = node->next;
        *res_obj = 0;
    }
    else {
        *res_node = NULL;
    }
}

void InsertPrev(NODE_STRUCT** head, NODE_STRUCT* node, BYTE obj, OBJECT_TYPE* object_to_add){
    if (*head == NULL){
        return;
    }
    NODE_STRUCT* currentNode = *head;
    while (currentNode != node) currentNode = currentNode->next;
    if (currentNode->use < SIZE) {
        OBJECT_TYPE* insertionPoint = currentNode->object + obj;
        for (int i = currentNode->use; i > obj; i--) {
            *(currentNode->object + i) = *(currentNode->object + i - 1);
        }
        *insertionPoint = *object_to_add;
        currentNode->use++;
    }
    else {
        OBJECT_TYPE newElement;
        if (obj!= 0) {
            newElement = *(currentNode->object);
            for (int i = 0; i < obj - 1; i++) {
                *(currentNode->object + i) = *(currentNode->object + i + 1);
            }
            *(currentNode->object + obj - 1) = *object_to_add;
        }
        else {
            newElement = *object_to_add;
        }
        if (*head != node) {
            currentNode = *head;
            while (currentNode->next != node) currentNode = currentNode->next;
            if (currentNode->use < SIZE) {
                *(currentNode->object + currentNode->use) = newElement;
                currentNode->use++;
                return;
            }
        }
        NODE_STRUCT* newNode = NewNode();
        *newNode->object = newElement;
        newNode->use = 1;
        if (*head == node) {
            newNode->next = *head;
            *head = newNode;
        }
        else {
            currentNode = *head;
            while (currentNode->next != node) currentNode = currentNode->next;
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }
}
void InsertNext(NODE_STRUCT* head, NODE_STRUCT* node, BYTE obj, OBJECT_TYPE* object_to_add){
     if (node->use < SIZE) {
        for (int i = node->use; i > obj + 1; i--) {
            *(node->object + i) = *(node->object + i - 1);
        }
        *(node->object + obj + 1) = *object_to_add;
        node->use += 1;
    }
    else {
        if (obj == SIZE - 1) {
            AddFirst(&(node->next), object_to_add);
        }
        else {
            AddFirst(&(node->next), (node->object + SIZE - 1));
            for (int i = node->use - 1; i > obj + 1; i--) {
                *(node->object + i) = *(node->object + i - 1);
            }
            *(node->object + obj + 1) = *object_to_add;
        }
    }
}

void RemoveFirst(NODE_STRUCT** head) {
    if((*head) == NULL){
        return;
    }
    if ((*head)->use > 1){
        for (int i = 1; i < (*head)->use; i++){
            *((*head)->object + i - 1) = *((*head)->object + i);
        }
        (*head)->use--;
    }
    else {
        NODE_STRUCT* temp = (*head)->next;
        DeleteNode(*head);
        *head = temp;
    }
}

void RemoveCurrent(NODE_STRUCT** head, NODE_STRUCT* node, BYTE obj) {
    if (node == NULL || obj >= node->use){
        return;
    }
    for (int i = obj; i < node->use - 1; i++){
        *(node->object + i) = *(node->object+i+1);
    }
    node->use--;
    if (node->use == 0){
        if (*head == node){
            *head = node->next;
            DeleteNode(node);
        }
        else{
            NODE_STRUCT* cur = *head;
            while (cur->next != node){
                cur = cur->next;
            }
            cur->next = node->next;
            DeleteNode(node);
        }
    }
}


void RemovePrev(NODE_STRUCT** head, NODE_STRUCT* node, BYTE obj){
    if (obj > 0) {
        RemoveCurrent(head, node, obj - 1);
        return;
    } 
    if (obj == 0 && *head == node) {
        return;
    }
    NODE_STRUCT* current = *head;
    while (current && current->next != node) {
        current = current->next;
    }
    if (current && current->use > 0) {
        RemoveCurrent(head, current, current->use - 1);
    }
}

void RemoveNext(NODE_STRUCT* head, NODE_STRUCT* node, BYTE obj){
    if (node == NULL){
        return;
    }
    if (obj < node->use - 1){
        RemoveCurrent(&head, node, obj + 1);
    }
    else {
        RemoveCurrent(&head, node->next,0);
    }
}

void RemoveLast(NODE_STRUCT** head){
    if(*head == NULL){
        return;
    }
    NODE_STRUCT* prev = NULL;
    NODE_STRUCT* current = *head;
    while (current->next != NULL){
        prev = current;
        current = current->next;
    }
    if (current -> use > 1){
        RemoveCurrent(head, current, current->use - 1);
    }
    else {
        if (prev != NULL){
            prev -> next = NULL;
        }
        else {
            *head = NULL;
        }
        DeleteNode(current);
    }

}

void Find(NODE_STRUCT* head, OBJECT_TYPE* obj_to_find, NODE_STRUCT** res_node, BYTE* res_obj){
    NODE_STRUCT* current = head;
    while (current != NULL){
        for (int i = 0; i < current->use; ++i) {
            if (*(current->object+i) == *obj_to_find){
                *res_node = current;
                *res_obj = i;
                return;
            }
        }
        current = current->next;
    }
    *res_node = NULL;
}



void Compress(NODE_STRUCT* head) {

    NODE_STRUCT* current = head;
    while (current && current->next) {       
        while (current->use < SIZE && current->next->use > 0) {   
            OBJECT_TYPE nextObj = *(current->next->object);
            *(current->object + current->use) = nextObj;
            current->use++;
            RemoveCurrent(&(current->next), current->next, 0);
        }       
        if (current->use == SIZE) {
            current = current->next;
        }
    }
}

void Reverse(NODE_STRUCT* head) {
    
    if (head == NULL) return;
    
    NODE_STRUCT* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    NODE_STRUCT* left_node = head;
    NODE_STRUCT* right_node = last;
    OBJECT_TYPE* left_elem = left_node->object;
    OBJECT_TYPE* right_elem = right_node->object + (right_node->use - 1);
    bool first;
    bool second;
    while (true){
        OBJECT_TYPE temp = *(left_elem);
        *(left_elem) = *(right_elem);
        *(right_elem) = temp;
        
        if (left_elem < (left_node->object + (left_node->use - 1))){
            left_elem += 1;
        }
        else {
            left_node = left_node->next;
            left_elem = left_node->object;
        }
        if (right_elem > right_node->object){
            right_elem -= 1;
        }
        else {
            NODE_STRUCT* prev = head;
            while (prev->next != right_node){
                prev = prev->next;
            }
            right_node = prev;
            right_elem = right_node->object + (right_node->use - 1);
        }
        
        first = (left_node == right_node && (right_elem <= left_elem));
        if (first){
            break;
        }
        std::cout << "Hero" << std::endl;
        second = ((left_node->object + (left_node->use - 1)) == left_elem && right_node->object == right_elem && left_node->next == right_node);
        if (second){
            break;
        }
    }
    Compress(head);
    

}

