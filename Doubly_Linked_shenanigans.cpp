void push(node **head, node **tail, int target_val, int where) {
    node *newNode = create(target_val);
    if (*head == NULL) {
        *head = newNode;
        *tail = *head;
        return;
    }
    else if ((*head)->val == where) {
        newNode->next = *head;          // Bug 1 fixed
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    else {
        node *curr = *head;
        while (curr->next != NULL && curr->next->val != where) {
            curr = curr->next;
        }
        if (curr->next == NULL) {
            newNode->prev = curr;
            curr->next = newNode;
            *tail = newNode;
            return;
        }
        else {
            node *target = curr->next;  // Bugs 2 & 3 fixed
            newNode->prev = curr;
            newNode->next = target;
            curr->next = newNode;
            target->prev = newNode;
            return;
        }
    }
}

void del(node **head, node **tail, int target_value) {
    if (*head == NULL) return;

    else if ((*head)->val == target_value) {
        node *temp = *head;
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        else
            *tail = NULL;
        free(temp);
        return;
    }
    else if ((*tail)->val == target_value) {
        node *temp = *tail;
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
        free(temp);
        return;
    }
    else {
        node *curr = *head;
        while (curr->next != NULL && curr->next->val != target_value) { // Bug 4 fixed
            curr = curr->next;
        }
        if (curr->next == NULL) return; // not found
        node *temp = curr->next;
        curr->next = temp->next;
        temp->next->prev = curr;        // Bug 5 fixed
        free(temp);
        return;
    }
}