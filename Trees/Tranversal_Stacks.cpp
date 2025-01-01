#include <iostream>
using namespace std;
const int SIZE = 100;

class node
{
public:
    int data;
    node *left;
    node *right;
};

class stack
{
private:
    int top;
    node *item[SIZE];

public:
    stack() : top(-1) {}
    void push(node *val)
    {
        if (Isfull())
        {
            cout << "stack ids full!\n";
        }
        item[++top] = val;
    }
    node *pop()
    {
        if (empty())
        {
            cout << "stack is empty!\n";
        }
        return item[top--];
    }
    bool Isfull() // stack is full
    {

        if (top == SIZE - 1)
            return true;
        else
            return false;
    }
    bool empty() /// stack is empty
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

class BinarySearchTree
{
private:
    node *root;
    void inorder(node *temp)
    {
        stack s;
        node *p;
        p = root;
        do
        {
            while (p != NULL)
            {
                s.push(p);
                p = p->left;
            }
            if (!s.empty())
            {
                p = s.pop();
                cout << p->data << " , ";
                p = p->right;
            }
        } while (!s.empty() || p != NULL);
    }
    void preorder(node *temp)
    {
        stack s;
        node *p;
        p = root;
        do
        {
            while (p != NULL)
            {
                cout << p->data << " , ";
                s.push(p);
                p = p->left;
            }
            if (!s.empty())
            {
                p = s.pop();
                p = p->right;
            }
        } while (!s.empty() || p != NULL);
    }
    void postorder(node *temp)
    {
        stack s1, s2; // Two stacks for postorder
        node *p = root;

        s1.push(p);
        while (!s1.empty())
        {
            p = s1.pop();
            s2.push(p);

            // Push left and right children to the first stack
            if (p->left != NULL)
                s1.push(p->left);
            if (p->right != NULL)
                s1.push(p->right);
        }

        // Print nodes in reverse order (from s2)
        while (!s2.empty())
        {
            p = s2.pop();
            cout << p->data << " , ";
        }
    }

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
    void PreorderTraverse()
    {
        preorder(root);
    }
    void PostorderTraverse()
    {
        postorder(root);
    }
    void InorderTraverse()
    {
        inorder(root);
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

    bb.InorderTraverse();
    cout << endl;

    // 14 ; 5 ; 9 ; 7 ; 16 ; 15 ; 18 ;
    bb.PreorderTraverse();
    cout << endl;

    //7 ; 9 ; 5 ; 15 ; 18 ; 16 ; 14 ;
    bb.PostorderTraverse();
    cout << endl;
    
    return 0;
}