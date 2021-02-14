#include<iostream>
using namespace std;

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

// calculating the min element in the tree;
int findMin(binaryTreeNode * temp)
{
    int left, right, min = INT_MAX, root_value;
    if(temp != NULL)
    {
        root_value = temp->data;
        left = findMin(temp->left);
        right = findMin(temp->right);

        if(left > right)
        min = right;
        else 
        min = left;
        // checking with the root value;
        if(root_value < min)
        min = root_value;
    }
    return min;
}

// printing the all the nodes of the tree in the postorder method;
void postOrder( binaryTreeNode * temp)
{
    if(temp == NULL)
        return;
    else
    {
        postOrder(temp->left);
        postOrder(temp->right);
        cout<<" -> "<<temp->data;
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
        binaryTreeNode * n = new binaryTreeNode();
        cout<<endl<<"Data: ";
        cin>>n->data;
        store_root = insertIntoBinaryTree(n);
    }

    cout<<endl<<endl<<"Printing all the elements inside the tree in POSTORDER:"<<endl;
    postOrder( store_root);
    cout<<endl<<endl<<"The minimum element present in the Tree: "<<findMin(store_root);

}