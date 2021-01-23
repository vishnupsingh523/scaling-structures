#include<iostream>
using namespace std;

class queueNode{
    public:
    int data;
    queueNode * next;
};
// Queue class created to insert all the nodes of the Binary Search Tree
class Queue{
    public:
    queueNode * front = NULL;

    void insertNode(queueNode * newNode)
    {
        if(front == NULL)
        front = newNode;
        else
        {
            while(front->next != NULL)
            {
                front = front->next;
            }
            front->next = newNode;
        }
    }
};

// Binary tree NODE
class node{
    public:
    int data;
    node * left;
    node * right;
    node()
    {
        data =0;
        left = right = NULL;
    }
    node(int num)
    {
        data = num; left = right = NULL;
    }
};

node * insertIntoBST(node * &root, node * newNode)
{
    if(root == NULL)
    {
        root = newNode;
        cout<<"Node inserted as ROOT";
        return root;
    }
    else
    {
        bool check = false;
        if(newNode->data <= root->data)
        {
            if(root->left == NULL)
            {
                root->left = newNode;
                cout<<"Node inserted succesfully";
            }
            else
            insertIntoBST(root->left,newNode);
        }
        
        if(newNode->data > root->data)
        {
            if(root->right == NULL)
            {
                cout<<"Node inserted succesfully";
                root->right = newNode;
            }
            else
            insertIntoBST(root->right, newNode);
        }
    }
}

void printBST(node * root)
{
    if(root != NULL)
    {
        printBST(root->left);
        cout<<" -> "<<root->data;
        printBST(root->right);
    }
    else
    {
        cout<<"Not able to print it.";
    }
    
}

int main()
{
    cout<<"Enter the size of BST: ";
    int size;
    cin>>size;

    node * root = NULL;
    while(size--)
    {
        int value;
        cout<<endl<<"Data: ";
        cin>>value;
        node * newNode = new node(value);
        root = insertIntoBST(root, newNode);   
    }

    // print BST;
    cout<<endl<<endl<<"Print the binary Tree: ";
    printBST(root);
}