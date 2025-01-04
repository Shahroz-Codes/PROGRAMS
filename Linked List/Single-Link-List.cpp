#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class Linklist
{
private:
    node *head;

public:
    Linklist() : head(NULL) {};

    bool IsEmpty()
    {
        return head == NULL;
    }
    node *Searchnode(int val)
    {
        node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == val)
                break;
            temp = temp->next;
        }
        return temp;
    }
    void ShowList()
    {
        node *temp = head;
        cout << "Link-List : ";
        while (temp != NULL)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void InsertAtHead(int val)
    {
        node *newer = new node();
        newer->data = val;
        if (head == NULL)
        {
            newer->next = NULL;
        }
        else
        {
            node *temp = head;
            newer->next = temp;
        }
        head = newer;
    }
    void InsertAtEnd(int val)
    {
        if (IsEmpty())
        {
            InsertAtHead(val);
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            node *newer = new node();
            newer->data = val;
            newer->next = NULL;
            temp->next = newer;
        }
    }
    void DeleteAtHead()
    {
        if (IsEmpty())
        {
            cout << "Empty List" << endl;
            return;
        }
        else if (head->next == NULL)
        {
            cout << "Deleted Value : " << head->data << endl;
            head = NULL;
        }
        else
        {
            node *temp = head;
            head = temp->next;
            cout << "Deleted Value : " << temp->data << endl;
            delete temp;
        }
    }
    void DeleteAtEnd()
    {
        if (IsEmpty())
        {
            cout << "Empty List" << endl;
            return;
        }
        else if (head->next == NULL)
        {
            cout << "Deleted Value : " << head->data << endl;
            head = NULL;
        }
        else
        {
            node *temp = head, *temp1;
            while (temp->next != NULL)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = NULL;
            cout << "Deleted Value : " << temp->data << endl;
            delete temp;
        }
    }
    void InsertAfter(int searchval)
    {
        node *temp = Searchnode(searchval);

        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
        }
        else
        {
            node *temp1 = temp->next;
            node *newer = new node();

            cout << "Enter a new value : ";
            cin >> newer->data;
            cout << endl;

            temp->next = newer;
            newer->next = temp1;
        }
    }
    void DeleteAfter(int searchval)
    {
        node *temp = Searchnode(searchval);

        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
        }
        else if (temp->next == NULL)
        {
            cout << "Could not Delete After Last node " << endl;
        }
        else
        {
            node *last;
            last = temp->next;
            if (last->next == NULL)
            {
                temp->next = NULL;
                delete last;
            }
            else
            {
                node *temp1, *temp2;
                temp1 = temp->next;
                temp2 = temp1->next;
                temp->next = temp2;
                delete temp1;
            }
        }
    }
    void InsertBefore(int searchval)
    {
        node *temp = Searchnode(searchval);

        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
        }
        else if (temp == head)
        {
            node *newer = new node();

            cout << "Enter a new value : ";
            cin >> newer->data;
            cout << endl;

            newer->next = temp;
            head = newer;
        }
        else // if (temp->next == NULL)
        {
            node *temp1 = head;
            while (temp1->next != temp)
            {
                temp1 = temp1->next;
            }
            node *newer = new node();

            cout << "Enter a new value : ";
            cin >> newer->data;
            cout << endl;

            newer->next = temp;
            temp1->next = newer;
        }
    }
    void DeleteBefore(int searchval)
    {
        node *temp = Searchnode(searchval);

        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
        }
        else if (temp == head)
        {
            cout << "Could not Delete Before Head node " << endl;
        }
        else if (temp->next == temp)
        {
            node *temp1 = head;
            head = temp;
            delete temp1;
        }
        else
        {
            node *temp1 = head, *temp2;
            while (temp1->next != temp)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = temp;
            delete temp1;
        }
    }
    void DeleteParticularnode(int searchval)
    {
        node *temp = Searchnode(searchval);

        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
        }
        else if (temp == head)
        {
            node *temp1 = head->next;
            head = temp1;
            delete temp;
        }
        else if (temp->next == NULL)
        {
            node *temp1 = head;
            while (temp1->next != temp)
            {
                temp1 = temp1->next;
            }
            temp1->next = NULL;
            delete temp;
        }
        else
        {
            node *temp1 = head, *temp2 = temp->next;
            while (temp1->next != temp)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp2;
            delete temp;
        }
    }
    void reverseLinkedList()
    {
        // Initialize pointers for the reversal process
        node *currentnode = head;
        node *previousnode = nullptr;
        node *nextnode = nullptr;

        // Traverse the linked list and reverse the node pointers
        while (currentnode != nullptr)
        {
            // Store the next node before reversing the link
            nextnode = currentnode->next;

            // Reverse the link of the current node
            currentnode->next = previousnode;

            // Move the pointers one step forward
            previousnode = currentnode;
            currentnode = nextnode;
        }

        // Update the head pointer to the new first node
        head = previousnode;
    }
};

int main()
{
    Linklist ll;
    ll.InsertAtHead(33);
    ll.InsertAtHead(34);
    ll.InsertAtHead(36);
    ll.InsertAtHead(22);
    ll.ShowList();

    // ll.reverseLinkedList();
    // ll.ShowList();

    cout << endl;

    // ll.InsertAtEnd(77);
    // ll.ShowList();

    // ll.InsertAfter(22);
    // ll.ShowList();

    // ll.InsertBefore(44);
    // ll.ShowList();

    // ll.DeleteBefore(22);
    // ll.ShowList();

    // ll.DeleteAfter(55);
    // ll.ShowList();

    // ll.DeleteParticularnode(55);
    // ll.ShowList();
    return 0;
}