#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * next;
};

// create node 
node * createNode(){
    int data;
    cout<<"\nData: ";
    cin>>data;
    node * n = new node;
    n->data = data;
    n->next = NULL;
}

// insert element into stack
node * insertElement(node * head){
    node * n = createNode();

    if(head == NULL)
    return n;
    
    n->next = head;
    head = n;
    return head;
}

// deleteing element from the STACK
node * deleteElement(node * head){
    if(head == NULL)
    {
        cout<<"\nUNDERFLOW ! The stack is empty.";
        return NULL;
    }

    node * temp = head;
    head = head->next;
    temp->next = NULL;
    cout<<"\nThe element is deleted and its value is : "<<temp->data;
    delete temp;

    return head;
}

// Printing the STACK
void printStack(node * head)
{
    if(head == NULL)
    cout<<"\nThe Stack is empty!";
    else{
        while(head != NULL)
        {
            cout<<" --> "<<head->data;
            head = head->next;
        }
    }
}

int main(){
    node * head = NULL;
    int select;
    char ch;
    
    do{
        cout<<"\nSelect any:\n1. Insertion in STACK\n2. Deletion in STACK\n3. Print STACK\n\nEnter your choice: ";
        cin>>select;
        switch (select)
        {
        case 1: head = insertElement(head);
            break;
        case 2: head = deleteElement(head);
            break;
        case 3: printStack(head);
            break;
        default:    cout<<"\nINVALID INPUT !!!";
            break;
        }

        cout<<"\n\nWant to continue?(Y/N): ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
}