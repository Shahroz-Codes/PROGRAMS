#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

class BinarySearchTree
{
private:
    node *root;

public:
    BinarySearchTree() : root(NULL) {};

    void insert(int val)
    {
        node *newer = new node();
        newer->data = val;
        newer->left = NULL;
        newer->right = NULL;

        if (root == NULL)
        {
            root = newer;
            cout << val << " inserted as root." << endl;
            return;
        }

        node *temp = root, *tracer;
        while (temp != NULL)
        {
            tracer = temp;
            if (val > temp->data)
            {
                temp = temp->right;
            }
            else if (val < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                cout << "Duplicate data not entered" << endl;
                delete newer;
                return;
            }
        }
        if (val > tracer->data)
        {
            tracer->right = newer;
            cout << val << " inserted at right of " << tracer->data << endl;
        }
        else
        {
            tracer->left = newer;
            cout << val << " inserted at left of " << tracer->data << endl;
        }
    }
};

int main()
{
    BinarySearchTree bb;
    bb.insert(14);
    bb.insert(16);
    bb.insert(16);
    bb.insert(18);
    bb.insert(5);
    bb.insert(9);
    bb.insert(7);
    bb.insert(15);

    return 0;
}