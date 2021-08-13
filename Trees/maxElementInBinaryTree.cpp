#include<bits/stdc++.h>
using namespace std;

class node{
    public:

    int data;
    node * left;
    node * right;

    node(int num)
    {
        data = num;
        left = NULL;
        right = NULL;
    }
};

node * insertIntoBinaryTree(node * root, node * newNode){

    if(root == NULL)
    return newNode;
    else{
        node * temp = root;
        if(newNode->data < root->data)
        {
            if(temp->left == NULL)
            {
                temp->left = newNode;
                return root;
            }
            else 
            temp->left = insertIntoBinaryTree(temp->left, newNode);
        }
        else{
            if(temp->right == NULL)
            {
                temp->right = newNode;
                return root;
            }
            else 
            temp->right = insertIntoBinaryTree(temp->right, newNode);
        }
    }
}

int maxElementInBT(node * root)
{
    int max = INT_MIN, left, right, rootValue;
    
    if(root!=NULL)
    {
        rootValue = root->data;
        left = maxElementInBT(root->left);
        right = maxElementInBT(root->right);

        if(right>left)
        max = right;
        else max = left;

        if(max<rootValue)
        max = rootValue;
    }

    return max;
}

void inorderTraversal(node * root)
{
    if(root == NULL)
    return;

    inorderTraversal(root->left);
    cout<<" --> "<<root->data;
    inorderTraversal(root->right);
}

int main()
{
    cout<<"Enter size: ";
    int size;
    cin>>size;

    int value;
    node * root = NULL;

    cout<<"Enter Values: ";
    for(int i=0;i<size;i++)
    {
        cin>>value;
        
        node * newNode = new node(value);
        root = insertIntoBinaryTree(root, newNode);
    }

    cout<<"\nInorder Traversal : ";
    inorderTraversal(root);

    cout<<"\nMaximum Element : "<<maxElementInBT(root);
}