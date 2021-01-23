#include<iostream>
using namespace std;

struct binaryTreeNode{
    int data;
    binaryTreeNode * left;
    binaryTreeNode * right;
    // this constructor is called while creating an new node of binary tree
    binaryTreeNode()
    {
        data = 0;
        left = right = NULL;
    }
    // this fucntion is called if we are already having the data value
    binaryTreeNode(int k)
    {
        data = k;
        left = right = NULL;
    }
};

class binaryTree{
    public:
    binaryTreeNode * root;
    binaryTree()
    {
        root = NULL;
    }

    binaryTree(binaryTreeNode * n){
        root = n;
    }
    
    void insertNode(binaryTreeNode * n){
        binaryTreeNode * temp = root;
        if(temp == NULL)
        {
            temp = n;
            cout<<"Node appended succesfully.\n";
        }
        else
        {
            while(temp != NULL)
            {
                if(n->data < temp->data)
                {
                    if(temp->left == NULL)
                    {
                        temp->left = n;
                        cout<<"Node appended succesfully."<<endl;
                        break;
                    }
                    else
                    temp = temp->left;
                }
                
                if(n->data > temp->data)
                {
                    if(temp->right == NULL)
                    {
                        temp->right = n;
                        cout<<"Node appended succesfully."<<endl;
                        break;
                    }
                    else
                    temp = temp->right;
                }
                else
                {
                    cout<<"\nSorry the node already exists with the value : "<<n->data;
                    break;
                }
            }
        }
        
    }

    void inorderTraversal(binaryTreeNode * temp)
    {
        if(temp!= NULL)
        {
            inorderTraversal(temp->left);
            cout<<" --> "<<temp->data;
            inorderTraversal(temp->right);
        }
        else
        {
            return;
        }
        
    }

    void searchElement(binaryTreeNode * temp,int data)
    {
        if(temp!=NULL)
        {
            searchElement(temp->left,data);
            if(data == temp->data)
            {
                cout<<"\nYes, element if found.";
                return;
            }
            searchElement(temp->right,data);
        }
    }
};

int main()
{
    binaryTree b = binaryTree();
    cout<<"Enter the size of the TREE: ";
    int size;
    cin>>size;

    while(size--)
    {
        binaryTreeNode * n = new binaryTreeNode;
        n->left = NULL;
        n->right = NULL;
        cout<<"\nData: ";
        cin>>n->data;
        b.insertNode(n);
    }

    cout<<endl<<endl<<"Printing the whole tree in inorder Traversal: \n";
    b.inorderTraversal(b.root);

    int element;
    cout<<endl<<endl<<"Enter the element to be searched: ";
    cin>>element;
    //calling search function from the whole tree;
    b.searchElement(b.root,element);
}