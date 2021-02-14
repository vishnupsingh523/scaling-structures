#include<iostream>
using namespace std;
#define SPACE 10
// here we are creating a binary tree node 
// which includes left and right pointer
// both the pointers stores the another nodes
class binaryTreeNode{
    public:
    int data;
    binaryTreeNode * left;
    binaryTreeNode * right;

    binaryTreeNode(){
        data = 0;
        right = NULL;
        left = NULL;
    }
    // this constructor is used when we will have the data value with us;
    binaryTreeNode(int num){
        data = num;
        left = right = NULL;
    }
};

// creating the root of the tree;
binaryTreeNode * root = NULL;

binaryTreeNode * insertIntoBinaryTree(binaryTreeNode * n)
{
    if(root == NULL)
    root = n;
    else
    {
        binaryTreeNode * temp = root;
        while(temp != NULL)
        {
            //first cheking for the left
            if(n->data <= temp->data)
            {
                if(temp->left == NULL)
                {
                    temp->left = n;
                    break;
                }
                else
                temp = temp->left;
            }
            else if(temp->right == NULL)
                {
                    temp->right = n;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
                
        }
    }
    cout<<endl<<"Node added succesfully.";
    return root;
}


void print2D( binaryTreeNode * temp,int space)
{
    if(temp!= NULL)
    {
        space+=SPACE;
        print2D(temp->right,space);
        cout<<endl;
        for(int i = SPACE; i<space;i++)
        cout<<" ";
        cout<<temp->data<<"\n";
        print2D(temp->left,space);

    }
}

int main()
{
    binaryTreeNode * store_root = NULL;

    int size;
    cout<<"Enter the size of the TREE.";
    cin>>size;

    cout<<endl<<"Enter the data of the nodes";
    for(int i = 0; i<size; i++)
    {
        // creating the new node always for storing the data and adding it to the tree with the help of root
        binaryTreeNode * n = new binaryTreeNode();
        cout<<endl<<"Data: ";
        cin>>n->data;
        store_root = insertIntoBinaryTree(n);
    }

    // here we are printing the tree by using hte print2D funciton.
    cout<<endl<<endl<<"Printing all the elements inside the tree: "<<endl;
    print2D( store_root,SPACE);

}