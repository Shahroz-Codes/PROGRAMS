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
    node *last;

public:
    Linklist() : last(NULL) {};

    bool IsEmpty()
    {
        return last == NULL;
    }

    node *SearchNode(int val)
    {
        node *temp = last;

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
        node *temp = last;
        cout << "Link-List : ";
        while (temp->next != NULL)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert(int val)
    {
        node *newer = new node();
        newer->data = val;
        newer->next = last;
        last = newer;
    }

    void InsertAtEnd(int val)
    {
        if (IsEmpty())
        {
            insert(val);
        }
        else
        {
            node *temp = last;
            if (temp->next == NULL)
            {
                DeleteAtlast();
            }
            else
            {
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
    }

    void DeleteAtlast()
    {
        if (IsEmpty())
        {
            cout << "Empty List" << endl;
            return;
        }
        else if (last->next == NULL)
        {
            cout << "Deleted Value : " << last->data << endl;
            last = NULL;
        }
        else
        {
            node *temp = last;
            last = temp->next;
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
        else if (last->next == NULL)
        {
            cout << "Deleted Value : " << last->data << endl;
            last = NULL;
        }
        else
        {
            node *temp = last, *temp1;
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
                node *temp1 , *temp2;
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
        else if (temp == last)
        {
            node *newer = new node();

            cout << "Enter a new value : ";
            cin >> newer->data;
            cout << endl;

            newer->next = temp;
            last = newer;
        }
        else // if (temp->next == NULL)
        {
            node *temp1 = last;
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
        else if (temp == last)
        {
            cout << "Could not Delete Before last Node " << endl;
        }
        else if (temp->next == temp)
        {
            node *temp1 = last;
            last = temp;
            delete temp1;
        }
        else
        {
            node *temp1 = last, *temp2;
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
        else if (temp == last)
        {
            node *temp1 = last->next;
            last = temp1;
            delete temp;
        }
        else if (temp->next == NULL)
        {
            node *temp1 = last;
            while (temp1->next != temp)
            {
                temp1 = temp1->next;
            }
            temp1->next = NULL;
            delete temp;
        }
        else
        {
            node *temp1 = last, *temp2 = temp->next;
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
    ll.insert(22);
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