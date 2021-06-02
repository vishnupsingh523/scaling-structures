#include<iostream>
using namespace std;

// creating node
struct node{
    int data;
    struct node * next;
};

node * createNewNode()
{
    int data;
    cout<<"\nData: ";
    cin>>data;
    node * n = new node;
    n->data = data;
    n->next = NULL;
    return n;
}

// Insertion at the TOP of the linked list
node * insertionAtTheTop(node * head){
    node *n = createNewNode();

    if(head == NULL)
    head = n;
    else{
        n->next = head;
        head = n;
    }
    return head;
}

// Insertion at the End of the Linked List
node * insertionAtTheEnd(node * head){
    node *n = createNewNode();

    node * temp = head;
    if(head == NULL)
    head = n;
    else{
        while(temp->next!= NULL)
        temp = temp->next;

        temp->next = n;
    }
    return head;
}

// Insertion at any particular position
node * insertionInTheMiddle(node * head){
    int pos;
    cout<<"\nPosition: ";
    cin>>pos;

    node *n = createNewNode();

    if(pos<=1)
    {
        n->next= head;
        return n;
    }
    
    node * temp = head;

    while(--pos && temp!=NULL)
        temp=temp->next;
    
    if(temp==NULL)
    return NULL;

    n->next = temp->next;
    temp->next = n;
    return head;
}

// print linked list
void printLinkedList(node * head)
{
    if(head == NULL)
    cout<<"\nThe list is empty!";
    else{
        while(head!=NULL)
        {
            cout<<" --> "<<head->data;
            head = head->next;
        }
    }
}

int main(){
    
    char ch;
    int select;
    node * head = NULL;

    do{
        cout<<"\nSelect any:\n1. Insertion at the TOP\n2. Insertion at the END\n3. Insertion at any specified position\n4. Print List\n\nEnter your choice: ";
        cin>>select;
        switch (select)
        {
        case 1: head = insertionAtTheTop(head);
            break;
        case 2: head = insertionAtTheEnd(head);
            break;
        case 3: head = insertionInTheMiddle(head);
            break;
        case 4: printLinkedList(head);
            break;
        default:    cout<<"\nINVALID INPUT !!!";
            break;
        }

        cout<<"\n\nWant to continue?(Y/N): ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');

    
}