#include<iostream>
using namespace std;

class treeNode{
    public:
    int data;
    treeNode * left;
    treeNode * right;

    treeNode(){
        data = 0;
        left = right = NULL;
    }
    treeNode(int num)
    {
        data = num;
        left = right = NULL;
    }
};

treeNode * insertIntoBinary(treeNode * n,treeNode * &root)
{
    treeNode * current = root;
    treeNode * previous = NULL;
    if(current == NULL)
    {
        root = n;
    }
    while(current != NULL)
    {
        previous = current;
        if(n->data< current->data)
        current = current->left;
        else 
        current = current->right;
    }

    if(previous == NULL)
    previous = n;
    else if(previous->data > n->data)
    previous->left = n;
    else
    previous->right = n;
}

void printTree(treeNode * root)
{
    if(root != NULL)
    {
        cout<<" -> "<<root->data;
        printTree(root->left);
        printTree(root->right);
    }
    else
    {
        return;
    }
    
}

int main()
{
    treeNode * root = NULL;
    int select;
    treeNode * n = new treeNode();
    int i=0;
    do
    {
        cout<<"\n\nSelect options:\n1- Insert into Tree\n2- Print the whole tree\n0- To exit\n\n...  ";
        cin>>select;
        switch(select){
        case 1:
        cout<<"\nData: ";
        cin>>n->data;
        root = insertIntoBinary(n,root);
        cout<<"\nNode successfully added to the tree.\n\n";
        break;
        case 2:
        cout<<"\nPrinting all the elements of the TREE:\n";
        printTree(root);
        break;
        default: cout<<"Wrong Input";
    }
    } while (select != 0);
    
    
}