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

    node *SearchNode(int val)
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
        newer->next = head;
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
        node *temp = head;
        head = temp->next;
        cout << "Deleted Value : " << temp->data << endl;
        delete temp;
    }

    void DeleteAtEnd(int val)
    {
        if (IsEmpty())
        {
            DeleteAtHead();
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
        node *temp = SearchNode(searchval);

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
        node *temp = SearchNode(searchval);

        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
        }
        else if (temp->next == NULL)
        {
            cout << "Could not Delete After Last Node " << endl;
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
                node *temp1 = head, *temp2;
                temp1 = temp->next;
                temp2 = temp1->next;
                temp->next = temp2;
                delete temp1;
            }
        }
    }

    void InsertBefore(int searchval)
    {
        node *temp = SearchNode(searchval);

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
        node *temp = SearchNode(searchval);

        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
        }
        else if (temp == head)
        {
            cout << "Could not Delete Before Head Node " << endl;
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
    void DeleteParticularNode(int searchval)
    {
        node *temp = SearchNode(searchval);

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
            temp1->next=NULL;
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
};

int main()
{
    Linklist ll;
    ll.InsertAtHead(22);
    ll.InsertAtHead(33);
    ll.InsertAtHead(44);
    ll.InsertAtHead(55);
    ll.InsertAtHead(66);
    ll.ShowList();

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

    // ll.DeleteParticularNode(55);
    // ll.ShowList();
    return 0;
}