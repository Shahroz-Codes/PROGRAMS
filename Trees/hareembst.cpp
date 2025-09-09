#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;    // Pointer to left child
    Node *right;   // Pointer to right child or inorder successor
    bool isThread; // True if the right pointer is a thread

    Node(int val) : data(val), left(nullptr), right(nullptr), isThread(false) {}
};

class ThreadedBinaryTree
{
private:
    Node *root;

public:
    // Constructor
    ThreadedBinaryTree() : root(nullptr) {}

    // Insert a new node
    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (root == nullptr)
        {
            root = newNode;
            cout << value << " added as root.\n";
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        // Find the correct position for the new node
        while (current != nullptr)
        {
            parent = current;
            if (value < current->data)
            {
                /* if (current->left == nullptr)
                     break;*/
                current = current->left;
            }
            else if (!current->isThread)
            {
                current = current->right;
            }
            else
            {
                break;
            }
        }

        if (value < parent->data)
        {
            parent->left = newNode;
            newNode->right = parent;
            newNode->isThread = true;
            cout << value << " added to the left of " << parent->data << ".\n";
        }
        else
        {
            newNode->right = parent->right; // Inherit parent's thread
            parent->right = newNode;
            parent->isThread = false; // Replace parent's thread
            newNode->isThread = true;
            cout << value << " added to the right of " << parent->data << ".\n";
        }
    }

    void inorder()
    {
        Node *temp = root;

        // Move to the leftmost node
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }

        // Traverse the tree
        while (temp != nullptr)
        {
            // Print the current node's data
            cout << temp->data << " ";

            // If the current node is threaded, follow the thread
            if (temp->isThread)
            {
                temp = temp->right;
            }
            else
            {
                // Otherwise, move to the leftmost node in the right subtree
                temp = temp->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }
            }
        }
    }
};

int main()
{
    ThreadedBinaryTree tree;

    tree.insert(6);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(10);
    tree.insert(40);
    tree.insert(1);

    cout << "In-order Traversal: ";
    tree.inorder();

    return 0;
}