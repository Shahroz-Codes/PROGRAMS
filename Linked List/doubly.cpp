#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
};

class DoublyLinkList
{
private:
    node *head;

public:
    DoublyLinkList() : head(NULL) {};

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
            temp = temp->right;
        }
        return temp;
    }
    void ShowList()
    {
        node *temp = head;
        cout << "Link-List : ";
        while (temp != NULL)
        {
            cout << temp->data << " <=> ";
            temp = temp->right;
        }
        cout << "NULL" << endl;
    }
    void InsertAtHead(int val)
    {
        node *newer = new node();
        newer->data = val;
        newer->left = NULL;
        if (head == NULL)
        {
            newer->right = NULL;
        }
        else
        {
            node *temp = head;
            newer->right = temp;
            temp->left = newer;
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

            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            node *newer = new node();
            newer->data = val;
            newer->left = temp;
            newer->right = NULL;
            temp->right = newer;
        }
    }
    void DeleteAtHead()
    {
        if (IsEmpty())
        {
            cout << "Empty List" << endl;
            return;
        }
        else
        {
            node *temp = head;
            if (temp->right == NULL)
            {
                cout << "Deleted Value : " << head->data << endl;
                head = NULL;
                delete temp;
            }
            else
            {
                node *temp1 = temp->right;
                head = temp1;
                temp1->left = NULL;
                cout << "Deleted Value : " << temp->data << endl;
                delete temp;
            }
        }
    }
    void DeleteAtEnd()
    {
        if (IsEmpty())
        {
            cout << "Empty List" << endl;
            return;
        }
        else
        {
            node *temp = head, *temp1;
            while (temp->right != NULL)
            {
                temp1 = temp;
                temp = temp->right;
            }
            if (temp->left == NULL)
            {
                cout << "Deleted Value : " << head->data << endl;
                head = NULL;
                delete temp;
            }
            else
            {
                temp1->right = NULL;
                cout << "Deleted Value : " << temp->data << endl;
                delete temp;
            }
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
            node *temp1 = temp->right;
            node *newer = new node();

            cout << "Enter a new value : ";
            cin >> newer->data;
            cout << endl;

            temp->right = newer;
            newer->right = temp1;
            if (temp1 != NULL)
            {
                temp1->left = newer;
            }
        }
    }
    void DeleteAfter(int searchval)
    {
        node *temp = SearchNode(searchval);

        if (temp == NULL)
        {
            cout << "Could not find node " << endl;
        }
        else if (temp->right == NULL)
        {
            cout << "Could not Delete After Last Node " << endl;
        }
        else
        {
            node *temp1;
            temp1 = temp->right;
            if (temp1->right == NULL)
            {
                temp->right = NULL;
                delete temp1;
            }
            else
            {
                node *temp2;
                temp2 = temp1->right;
                temp->right = temp2;
                temp2->left = temp;
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

            newer->right = temp;
            newer->left = NULL;
            temp->left = newer;
            head = newer;
        }
        else
        {
            node *temp1 = temp->left;
            
            node *newer = new node();

            cout << "Enter a new value : ";
            cin >> newer->data;
            cout << endl;

            newer->right = temp;
            newer->left = temp1;
            temp->left = newer;
            temp1->right = newer;
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
        else
        {
            node *temp1 = temp->left, *temp2 = temp1->left;
            temp->left = temp2;
            if (temp->left == NULL)
                head = temp;

            else
                temp2->right = temp;

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
            DeleteAtHead();
        }
        else if (temp->right == NULL)
        {
          DeleteAtEnd();
        }
        else
        {
            node *temp1 = temp->left, *temp2 = temp->right;
            
            temp1->right = temp2;
            temp2->left = temp1;
            delete temp;
        }
    }
};

int main()
{
    DoublyLinkList ll;
    ll.InsertAtHead(12);
    ll.InsertAtHead(-56);
    ll.InsertAtHead(44);
    ll.ShowList();

    // ll.DeleteAtHead();
    // ll.ShowList();

    // ll.DeleteAtEnd();
    // ll.ShowList();

    // ll.InsertAtEnd(77);
    // ll.ShowList();

    // ll.DeleteAfter(12);
    // ll.ShowList();

    // ll.InsertAfter(44);
    // ll.ShowList();

    // ll.InsertBefore(12);
    // ll.ShowList();

    // ll.DeleteBefore(6);
    // ll.ShowList();

    ll.DeleteParticularNode(-56);
    ll.ShowList();
    return 0;
}