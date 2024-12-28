
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
    node *returnhead()
    {
        return head;
    }
    void linkodd(node *odd)
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = odd;
    }
    void DeleteAtHead()
    {
        node *temp = head;
        head = temp->next;
        delete temp;
    }
    void DeleteAtEnd()
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
            delete temp;
        }
    }
    void ReArrange()
    {
        if (IsEmpty())
        {
            return;
        }
        else
        {
            node *temp = head, *temp1;
            Linklist tt;

            while (temp->next != NULL)
            {
                if (temp->data % 2 != 0)
                {
                    if (temp == head)
                    {
                        DeleteAtHead();
                    }
                    else if (temp->next == NULL)
                    {
                        DeleteAtEnd();
                    }
                    else
                    {
                        temp1->next = temp->next;
                    }

                    tt.InsertAtEnd(temp->data);
                }
                temp1 = temp;
                temp = temp->next;
            }
            linkodd(tt.returnhead());
        }
    }
};
int main()
{
    Linklist ll;
    ll.InsertAtHead(22);
    ll.InsertAtHead(44);
    ll.InsertAtHead(2);
    ll.InsertAtHead(23);
    ll.InsertAtHead(5);
    ll.InsertAtHead(87);
    ll.ShowList();
    ll.ReArrange();
    ll.ShowList();
    return 0;
}