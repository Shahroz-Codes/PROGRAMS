#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    bool rthread;
    node(int val) : data(val), left(NULL), right(NULL), rthread(false) {}
};

class ThreadedBinaryTree
{
private:
    node *root;

public:
    ThreadedBinaryTree() : root(NULL) {};

    void insert(int val)
    {
        node *newer = new node(val);
        if (root == NULL)
        {
            root = newer;
            cout << val << " inserted as root." << endl;
            return;
        }

        node *current = root, *tracer, *temp;
        while (current != NULL)
        {
            tracer = current;
            if (val == current->data)
            {
                cout << "Duplicate data not entered" << endl;
                delete newer;
                return;
            }
            else if (val < current->data)
            {
                current = current->left;
            }
            else if (!current->rthread)
            {
                current = current->right;
            }
            else
            {
                break;
            }
        }
        if (val > tracer->data)
        {
            temp = tracer->right;
            tracer->right = newer;
            newer->right = temp;
            newer->rthread = true;
            cout << val << " inserted at right of " << tracer->data << endl;
        }
        else
        {

            tracer->left = newer;
            newer->right = tracer;
            newer->rthread = true;
            cout << val << " inserted at left of " << tracer->data << endl;
        }
    }
    
};
int main()
{
    ThreadedBinaryTree bb;
    bb.insert(14);
    bb.insert(16);
    bb.insert(18);
    bb.insert(5);
    bb.insert(9);
    bb.insert(7);
    bb.insert(15);
    return 0;
}