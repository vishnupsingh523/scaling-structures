#include<bits/stdc++.h>
using namespace std;

class AVLNode{
    public:
    int data;
    int height;
    AVLNode * left;
    AVLNode * right;

    AVLNode()
    {
        left = NULL;
        right = NULL;
        height = data = 0;
    }

    AVLNode(int num)
    {
        data = num;
        height = 0;
        left = right = NULL;
    }
};

int height(AVLNode * root)
{
    if(root == NULL)
    return -1;
    return root->height;
}

// LEFT LEFT - SINGLE ROTATION
AVLNode * LLrotation(AVLNode * root)
{
    cout<<"\nPerforming LL-Rotation";
    AVLNode * temp = root->left;
    root->left = temp->right;
    temp->right = root;

    root->height = max( height(root->left), height(root->right) )+1;
    temp->height = max( height(temp->left), root->height )+ 1;
    return temp;
}

// Right Right - SINGLE ROTATION
AVLNode * RRrotation(AVLNode * root)
{
    cout<<"\nPerforming RR-Rotation";
    AVLNode * temp = root->right;
    root->right = temp->left;
    temp->left = root;

    root->height = max( height(root->left), height(root->right) )+1;
    temp->height = max( height(temp->right), root->height )+ 1;
    return temp;
}

// LEFT RIGHT - DOUBLE ROTATION
AVLNode * LRrotation(AVLNode * root)
{
    cout<<"\nPerforming LR-Rotation";
    root->left = RRrotation(root->left);
    return LLrotation(root);
}

// RIGHT LEFT - DOUBLE ROTATION
AVLNode * RLrotation(AVLNode * root)
{
    cout<<"\nPerforming RL- Rotation";
    root->right = LLrotation(root->right);
    return RRrotation(root);
}

AVLNode * insert( AVLNode * root, int data)
{
    if(!root)
    {
        root = new AVLNode(data);

        if(!root)
        cout<<"\nMemory Error !!!\n";
        else
        return root;
    }
    else if(data<root->data)
    {
        root->left = insert(root->left, data);

        if( (height(root->left)-height(root->right)) == 2)
        {
            if(data < root->left->data)
            root = LLrotation(root);
            else
            root = LRrotation(root);
        }
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
        if( (height(root->right) - height(root->left)) == 2)
        {
            if(data > root->right->data)
            root = RRrotation(root);
            else
            root = RLrotation(root);
        }
    }

    root->height = max( height(root->left), height(root->right)) + 1;
    return root;
}

void printAVL(AVLNode * root)
{
    if(!root)
    return;
    
    printAVL(root->left);
    cout<<" --> "<<root->data;
    printAVL(root->right);
}

int main()
{
    char ch;
    AVLNode * root = NULL;

    do{
        int val;
        cout<<"\n1. Insert into AVL\n2. Print AVL\nenter your choice....  ";
        cin>>val;
        switch (val)
        {
            case 1: int value;
            cout<<"\nData: ";
            cin>>value;
            root = insert(root, value);
            break;

            case 2: printAVL(root);
            break;

            default: cout<<"\nINVALID INPUT !!!\n";break;
        }

        cout<<"\nWant to continue? (Y?N): ";
        cin>>ch;
    }while ( ch=='y' || ch=='Y');
    
}