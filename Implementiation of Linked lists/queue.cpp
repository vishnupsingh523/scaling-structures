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

// insert element into queue from FRONT
node * insertFromFront(node * head){
    node * n = createNode();

    if(head == NULL)
    return n;
    
    n->next = head;
    head = n;
    return head;
}


// insert element into queue from REAR
node * insertFromRear(node * head){
    node * n = createNode();

    if(head == NULL)
    return n;
    
    node * temp = head;

    while(temp->next != NULL)
    temp = temp->next;
    temp->next = n;

    return head;
}

// deleteing element from the QUEUE from FRONT
node * deleteFromFront(node * head){
    if(head == NULL)
    {
        cout<<"\nUNDERFLOW ! The QUEUE is empty.";
        return NULL;
    }

    node * temp = head;
    head = head->next;
    temp->next = NULL;
    cout<<"\nThe element is deleted and its value is : "<<temp->data;
    delete temp;

    return head;
}


// deleteing element from the QUEUE from REAR
node * deleteFromRear(node * head){
    if(head == NULL)
    {
        cout<<"\nUNDERFLOW ! The QUEUE is empty.";
        return NULL;
    }

    if(head->next == NULL)
    {
        cout<<"\nThe element is deleted and its value is : "<<head->data;
        return NULL;
    }
    
    node * temp = head;
    node * curr = NULL;

    while(temp->next != NULL)
    {
        curr = temp;
        temp = temp->next;
    }
    curr->next = temp->next;
    temp->next = NULL;
    cout<<"\nThe element is deleted and its value is : "<<temp->data;
    delete temp;

    return head;
}
// Printing the STACK
void printQueue(node * head)
{
    if(head == NULL)
    cout<<"\nThe QUEUE is empty!";
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
        cout<<"\nSelect any operations to be perfomed in QUEUE:\n1. Insertion from FRONT\n2. Insertion from REAR\n3. Deletion from FRONT\n4. Deletion from REAR\n5. Print QUEUE\n\nEnter your choice: ";
        cin>>select;
        switch (select)
        {
        case 1: head = insertFromFront(head);
            break;
        case 2: head = insertFromRear(head);
            break;
        case 3: head = deleteFromFront(head);
            break;
        case 4: head = deleteFromRear(head);
            break;
        case 5: printQueue(head);
            break;
        default:    cout<<"\nINVALID INPUT !!!";
            break;
        }

        cout<<"\n\nWant to continue?(Y/N): ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
}