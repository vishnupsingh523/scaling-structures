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
    node * temp = head;
    if(head == NULL)
    {
        n->next = n;
        return n;
    }
    if(head->next = head)
    {
        head->next = n;
        n->next = head;
        head = n;
        return head;
    }
    else{

        n->next = temp;
        while(temp->next != head)
        temp = temp->next;

        temp->next = n;
        head = n;
    }
    return head;
}


// insert element into queue from REAR
node * insertFromRear(node * head){
    node * n = createNode();
    node * temp = head;
    if(head == NULL)
    {
        n->next = n;
        return n;
    }
    if(head->next = head)
    {
        head->next = n;
        n->next = head;
        return head;
    }
    else{

        while(temp->next != head)
        temp = temp->next;

        n->next = head;
        temp->next = n;
    }
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
    node * curr = head;
    while(temp ->next != head)
    temp = temp->next;

    temp->next = curr->next;
    head = curr->next;
    curr->next = NULL;
    cout<<"\nThe element is deleted and its value is : "<<curr->data;
    delete curr;

    return head;
}


// deleteing element from the QUEUE from REAR
node * deleteFromRear(node * head){
    if(head == NULL)
    {
        cout<<"\nUNDERFLOW ! The QUEUE is empty.";
        return NULL;
    }

    if(head->next == head)
    {
        cout<<"\nThe element is deleted and its value is : "<<head->data;
        delete head;
        return NULL;
    }
    
    node * temp = head;
    node * curr = NULL;

    while(temp->next != head)
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
void printCyclicList(node * head)
{
    if(head == NULL)
    cout<<"\nThe QUEUE is empty!";
    else{
        node * temp = head;
        do
        {
            cout<<" --> "<<temp->data;
            temp = temp->next;
        }while(temp->next != head);
    }
}

int main(){
    node * head = NULL;
    int select;
    char ch;
    
    do{
        cout<<"\nSelect any operations to be perfomed in Cyclic List:\n1. Insertion from FRONT\n2. Insertion from REAR\n3. Deletion from FRONT\n4. Deletion from REAR\n5. Print Cyclic Linked LIst\n\nEnter your choice: ";
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
        case 5: printCyclicList(head);
            break;
        default:    cout<<"\nINVALID INPUT !!!";
            break;
        }

        cout<<"\n\nWant to continue?(Y/N): ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
}