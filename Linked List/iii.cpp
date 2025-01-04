Here are specific member functions to solve the given problems:

9. Find Middle Element of Linked List


int findMiddleElement() {
    Node* slow = head;
    Node* fast = head;

    if (head != nullptr) {
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    return slow->data;
}


13. Insert New Node at Any Position in Singly Linked List


void insertAtPosition(int data, int position) {
    Node* newNode = new Node();
    newNode->data = data;

    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


19. Remove All Even Elements from a Queue


void removeEvenElements() {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data % 2 == 0) {
            Node* nodeToDelete = temp;
            temp = temp->next;
            delete nodeToDelete;
        } else {
            temp = temp->next;
        }
    }
}


23. Remove All Duplicate Elements from a Queue


void removeDuplicates() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* runner = temp;
        while (runner->next != nullptr) {
            if (runner->next->data == temp->data) {
                Node* nodeToDelete = runner->next;
                runner->next = runner->next->next;
                delete nodeToDelete;
            } else {
                runner = runner->next;
            }
        }
        temp = temp->next;
    }
}


34. Check if Two Queues are Equal


bool areQueuesEqual(Node* queue1, Node* queue2) {
    while (queue1 != nullptr && queue2 != nullptr) {
        if (queue1->data != queue2->data) {
            return false;
        }
        queue1 = queue1->next;
        queue2 = queue2->next;
    }
    return (queue1 == nullptr && queue2 == nullptr);
}


Note: These functions assume that the linked list/queue has a Node struct with data and next members, and a head pointer to the first node in the list.