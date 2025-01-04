#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *last;

public:
    CircularLinkedList() : last(NULL) {};

    bool IsEmpty()
    {
        return last == NULL;
    }

    Node *SearchNode(int val)
    {
        Node *temp = last;
        if (temp == NULL)
            return NULL;
        do
        {
            if (temp->data == val)
                break;
            temp = temp->next;
        } while (temp != last);
        return temp;
    }

    void ShowList()
    {
        Node *temp = last;
        if (temp == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        do
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        } while (temp != last);
        cout << "Last" << endl;
    }

    void insert(int val)
    {
        Node *newer = new Node();
        newer->data = val;
        if (last == NULL)
        {
            last = newer;
            newer->next = last;
        }
        else
        {
            newer->next = last->next;
            last->next = newer;
            last = newer;
        }
    }

    void InsertAtEnd(int val)
    {
        Node *newer = new Node();
        newer->data = val;
        if (last == NULL)
        {
            last = newer;
            newer->next = last;
        }
        else
        {
            newer->next = last->next;
            last->next = newer;
            last = newer;
        }
    }

    void DeleteAtLast()
    {
        if (last == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        else if (last->next == last)
        {
            cout << "Deleted Value : " << last->data << endl;
            delete last;
            last = NULL;
        }
        else
        {
            Node *temp = last->next;
            while (temp->next != last)
                temp = temp->next;
            cout << "Deleted Value : " << last->data << endl;
            temp->next = last->next;
            delete last;
            last = temp;
        }
    }

    void DeleteAtEnd()
    {
        if (last == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        else if (last->next == last)
        {
            cout << "Deleted Value : " << last->data << endl;
            delete last;
            last = NULL;
        }
        else
        {
            Node *temp = last->next;
            while (temp->next != last)
                temp = temp->next;
            cout << "Deleted Value : " << temp->data << endl;
            temp->next = last->next;
            delete temp;
        }
    }

    void InsertAfter(int searchval)
    {
        Node *temp = SearchNode(searchval);
        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
            return;
        }
        Node *newer = new Node();
        cout << "Enter a new value : ";
        cin >> newer->data;
        cout << endl;
        if (temp == last)
        {
            newer->next = temp->next;
            temp->next = newer;
            last = newer;
        }
        else
        {
            newer->next = temp->next;
            temp->next = newer;
        }
    }

    void DeleteAfter(int searchval)
    {
        Node *temp = SearchNode(searchval);
        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
            return;
        }
        if (temp->next == last)
        {
            cout << "Could not Delete After Last Node " << endl;
            return;
        }
        Node *temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
    }

    void InsertBefore(int searchval)
    {
        Node *temp = SearchNode(searchval);
        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
            return;
        }
        if (temp == last->next)
        {
            Node *newer = new Node();
            cout << "Enter a new value : ";
            cin >> newer->data;
            cout << endl;
            newer->next = last->next;
            last->next = newer;
            last = newer;
        }
        else
        {
            Node *temp1 = last->next;
            while (temp1->next != temp)
                temp1 = temp1->next;
            Node *newer = new Node();
            cout << "Enter a new value : ";
            cin >> newer->data;
            cout << endl;

            newer->next = temp1->next;
            temp1->next = newer;
        }
    }

    void DeleteBefore(int searchval)
    {
        Node *temp = SearchNode(searchval);
        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
            return;
        }
        if (temp == last->next)
        {
            cout << "Could not Delete Before First Node " << endl;
            return;
        }
        Node *temp1 = last->next;
        while (temp1->next != temp)
            temp1 = temp1->next;
        temp1->next = temp->next;
        delete temp;
    }

    void DeleteParticularNode(int searchval)
    {
        Node *temp = SearchNode(searchval);
        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
            return;
        }
        if (temp == last && temp->next == last)
        {
            cout << "Deleted Value : " << temp->data << endl;
            delete temp;
            last = NULL;
        }
        else if (temp == last)
        {
            Node *temp1 = last->next;
            while (temp1->next != last)
                temp1 = temp1->next;
            cout << "Deleted Value : " << last->data << endl;
            temp1->next = last->next;
            delete last;
            last = temp1;
        }
        else
        {
            Node *temp1 = last->next;
            while (temp1->next != temp)
                temp1 = temp1->next;
            cout << "Deleted Value : " << temp->data << endl;
            temp1->next = temp->next;
            delete temp;
        }
    }
};

int main()
{
    CircularLinkedList cll;
    cll.insert(22);
    cll.insert(33);
    cll.insert(44);
    cll.ShowList();
    cll.DeleteParticularNode(33);
    cll.ShowList();
    return 0;
}