#include<iostream>
using namespace std;

class binaryTreeNode{
    public:
    int data;
    binaryTreeNode * left;
    binaryTreeNode * right;

    binaryTreeNode()
    {
        left = right = NULL;
        data = NULL;
    }
    binaryTreeNode(int num)
    {
        data = num;
        left = right = NULL;
    }
};

void insertNodeIntoTree(binaryTreeNode * root, binaryTreeNode * n)
{
    if(root == NULL)
    root = n;
    else
    {
        if(n->data < root->data)
        {
            root = root->left;
        }
        else if
    }
    
}