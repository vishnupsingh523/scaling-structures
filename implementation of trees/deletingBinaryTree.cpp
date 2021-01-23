#include<iostream>
using namespace std;

class binaryTreeNode{
    public:
    int data;
    binaryTreeNode * left;
    binaryTreeNode * right;
};


// insert into binary search tree
binaryTreeNode * insertIntoBST(binaryTreeNode * &temp , binaryTreeNode * newNode)
{
    if(temp == NULL)
    {
        temp = newNode;
        cout<<"Node inseted as the ROOT.";
        return temp;
    }
    else
    {
        if(temp->data > newNode->data)
        {
            if(temp->left == NULL)
            {
                temp->left = newNode;
                cout<<"Node inserted Succesfully";
            }
            else
            {
                insertIntoBST(temp->left, newNode);
            }
        }
        
        if(temp->data < newNode->data)
        {
            if(temp->right == NULL)
            {
                temp->right = newNode;
                cout<<"Node inserted Succesfully";
            }
            else
            {
                insertIntoBST(temp->right, newNode);
            }
        }
    }
    
}

// printing the node as the inorder traversal
void inorderPrint(binaryTreeNode * temp)
{
    if(temp != NULL)
    {
        inorderPrint(temp->left);
        cout<<" -> "<<temp->data;
        inorderPrint(temp->right);
    }
    
}

// Deleting The whole tree
binaryTreeNode * deleteTree(binaryTreeNode * root)
{
    if(root == NULL)
    return NULL;
    else
    {
        deleteTree(root->left);
        deleteTree(root->right);
        cout<<" -> "<<root->data<<endl;
        delete root;
        return NULL;
    }
}

// checking if tree is empty it will return true else return false;
bool isEmpty(binaryTreeNode * root)
{
    if(root == NULL)
    return true;
    else
    return false;
}
int main()
{
    binaryTreeNode * root = NULL;
    cout<<"Enter the number of nodes in the BST: ";
    int size;
    cin>>size;
    for(int i=0;i<size; i++)
    {
        int value;
        cout<<"\nData: ";
        // creating a new node and assigning the value at the same time
        binaryTreeNode * newNode = new binaryTreeNode;
        cin>>newNode->data;
        newNode->left = NULL;
        newNode->right = NULL;

       insertIntoBST(root,newNode);
    }

    cout<<endl<<endl<<"Printing the Whole TREE: \n";
    // printing fuction;
    inorderPrint(root);

    cout<<endl<<endl<<"Deleting the TREE:\n";
    root = deleteTree(root);

    // check weather the tree is empty or not;
    if(isEmpty(root))
    cout<<endl<<"Tree is empty NOW";
    else
    {
        cout<<endl<<"Tree is not empty";
    }
    
}