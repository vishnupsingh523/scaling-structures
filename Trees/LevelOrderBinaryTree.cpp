#include<bits/stdc++.h>
using namespace std;

// Creating Binary Tree Data Structure;
struct binaryTreeNode{
    int data;
    struct binaryTreeNode * left;
    struct binaryTreeNode * right;
};

void insertIntoBinaryTree(struct binaryTreeNode * &root, struct binaryTreeNode * newNode)
{
    if(root==NULL)
    {
        root = newNode;
        cout<<"\nNew Node Inserted Succesfully :)";
    }
    else
    {
        if(newNode->data> root->data)
        {
            if(root->left == NULL)
            {
                root->left = newNode;
                cout<<"\nNew Node Inserted Succesfully :)";
            }
            else
            insertIntoBinaryTree(root->left, newNode);
        }
        else{
            if(root->right == NULL)
            {
                root->right = NULL;
                cout<<"\nNew Node Inserted Succesfully :)";
            }
            else
            insertIntoBinaryTree(root->right, newNode);
        }
    }

}
//****************************************************************************************+
//****************************************************************************************+

// Creating a Queue data structure;
struct Queue{
    int data;
    struct binaryTreeNode * left;
    struct binaryTreeNode * right;
    struct Queue * next;
};

struct Queue * createQueue()
{
    Queue * root = new Queue();
    root->left = root->right = NULL;
    root->next =NULL;
    return root;
}

bool isEmpty(struct Queue * root)
{
    if(root == NULL)
    return true;
    
    return false;
}

void enQueue(struct Queue * root, struct binaryTreeNode * node)
{
    struct Queue * n = new Queue();
    n->data = node->data;
    n->right = node->right;
    n->left = node->left;

    if(isEmpty(root))
    root = n;
    else
    {
        n->next = root;
        root = n->next;
    }
}
binaryTreeNode * deQueue(struct Queue * root)
{
    if(isEmpty(root))
    return NULL;
    else
    {
        struct Queue * temp = root;
        struct Queue * prev = NULL;
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        
        struct binaryTreeNode * n = new binaryTreeNode();
        n->data = temp->data;
        n->right = temp->right;
        n->left = temp->left;
        
        delete temp;
        return n;
    }
}

// Delete Queue function which deletes the whole queue
void deleteQueue(struct Queue * root)
{
    if(root)
    {
        deleteQueue(root->next);
        cout<<" -> "<<root->data;
        delete root;
    }
}

// *****************************************
//        -- LEVEL ORDER TRAVERSAL --
// *****************************************
void levelOrderTraversal(struct binaryTreeNode * root)
{
    binaryTreeNode * temp;
    struct Queue * Q = createQueue();

    if(!root)
    return;

    enQueue(Q, root);

    while(!isEmpty(Q))
    {
        temp = deQueue(Q);
        cout<<" -> "<<temp->data;
        
        if(temp->left)
        enQueue(Q, temp->left);
        if(temp->right)
        enQueue(Q, temp->right);
    }
    deleteQueue(Q);
}

/**************************************
 * Main Function
 **************************************/
int main(){

    int size, data;
    struct binaryTreeNode * root = new binaryTreeNode();
    
    cout<<"\nEnter Size : ";
    cin>>size;

    while(size--)
    {
        cout<<"\nEneter Data: ";
        cin>>data;

        binaryTreeNode * newNode = new binaryTreeNode();
        newNode->data = data;
        newNode->left = newNode->right = NULL;

        insertIntoBinaryTree(root, newNode);
    }

    levelOrderTraversal(root);

    return 0;
}