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

    node *getroot()
    {
        return root;
    }
    node *SearchBST(node *temp, int val)
    {
        if (temp == NULL)
            return NULL;
        if (val == temp->data)
        {
            return NULL;
        };
        SearchBST(temp->left, val);
        SearchBST(temp->right, val);
        return temp;
    }
    int NumberofNodes(node *temp)
    {
        if (temp == NULL)
            return 0;
        int count = 1;
        count += NumberofNodes(temp->left);
        count += NumberofNodes(temp->right);
        return count;
    }
    int NumberofLeafNodes(node *temp)
    {
        int count = 0;
        if (temp == NULL)
            return 0;
        if (temp->left == NULL && temp->right == NULL )
        {
            return 1;
        }
        return NumberofLeafNodes(temp->left) + NumberofLeafNodes(temp->right);
    }
    int SumofNodes(node *temp)
    {
        if (temp == NULL)
            return 0;
        int sum = temp->data;
        sum += SumofNodes(temp->left);
        sum += SumofNodes(temp->right);
        return sum;
    }

    void Delete(int val) {}
};

int main()
{
    BinarySearchTree bb;
    bb.insert(20);
    bb.insert(12);
    bb.insert(14);
    bb.insert(8);
    bb.insert(30);
  

    // cout << "NumberofNodes: " << bb.NumberofNodes(bb.getroot()) << endl;
    // cout << "SumofNodes: " << bb.SumofNodes(bb.getroot()) << endl;
    // if (bb.SearchBST(bb.getroot(), 60) == NULL)
    // {
    //     cout << "value not found " << endl;
    // }
    // else
    // {
    //     cout << "value  found " << endl;
    // }
    cout << "NumberofLeafNodes: " << bb.NumberofLeafNodes(bb.getroot()) << endl;

    return 0;
}