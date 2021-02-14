// here we are performing preorder traversing in trees
#include<iostream>
#define SPACE 10
using namespace std;

class node{
    public:

    int data;
    node * left;
    node * right;
    
    node(){ //default consturctor
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(int num){
        data = num;
        left = NULL;
        right = NULL;
    }
};

class binaryTree{
    public:

    node * root= NULL;

    bool isEmpty(){
        if(root == NULL)
        return true;
        else
        return false;
    }
    // adding node to the tree

    node * appendNode(node * n)
    {
        if(root == NULL)
        {
            root = n;
            cout<<"Node appended successfully."<<endl;
        }
        else
        { 
            node * temp = root;
            while(temp != NULL)
            {
                //inserting at the left
                if(n->data <= temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = n;
                        break;
                    }
                    else
                        temp= temp->left;
                }
                else if(temp->right == NULL)
                {
                    temp->right = n;
                    break;
                }
                else
                    temp= temp->right;
            }
            cout<<"Node added successfully.";
            return root;
        }
    }

    
    // void print2D(node * r , int space)
    // {
    //     if(r == NULL)
    //     return;

    //     space += SPACE;
    //     print2D(r->right , space);
    //     cout<<endl;
    //     for(int i = SPACE ; i < space; i++)
    //     cout<<" ";
    //     cout<<r->data<<endl;
    //     print2D(r->left, space);
    // }

    
    
};

void Inorder(node *n) 
    {
        if(n == NULL)
            return;
        Inorder(n->left);
        cout<<"-->"<<n->data;
        Inorder(n->right);
    } 
// void preorder(node * root)
// {
//     if(root != NULL)
//     {
//         cout<<" -> "<<root->data;
//         preorder(root->left);
//         preorder(root->left);
//     }
// }

int main()
{
    binaryTree b;
    int size;
    cout<<"Enter the size of the binary tree: ";
    cin>>size;
    node * root = NULL;

    while(size--)
    {
        node * n = new node();
        cout<<"\nData: ";
        cin>>n->data;
        if(!n)
        cout<<"\nMemory Error.\n";
        else
        root = b.appendNode(n);
    }

    cout<<"\nPrinting all the nodes here: \n";
    Inorder(root);
    // b.print2D(b.root, 5);
    cout<<endl<<endl<<"All nodes are printed successfullly.";
    return 0;
}