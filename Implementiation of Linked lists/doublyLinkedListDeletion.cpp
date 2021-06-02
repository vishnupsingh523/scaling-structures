#include<iostream>
using namespace std;

// creating node
struct node{
    int data;
    struct node * next;
    struct node * prev;
};

node * createNode(){
    int data;
    cout<<"\nData: ";
    cin>>data;
    node * n = new node;
    n->data = data;
    n->next = n->prev = NULL;
    return n;
}

// insertion at the TOP
node * insertionAtTheTop(node * head)
{
    node * n = createNode();

    if(head == NULL)
    {
        head = n;
        return head;
    }
    else{
        n->next = head;
        head->prev = n;
        head = n;
        return head;
    }
}

// deletion at the TOP
node * deletionAtTheTop(node * head)
{
    node * temp = NULL;

    if(head == NULL)
    {
        cout<<"\nUNDERFLOW!!! The list is empty!";
        return NULL;
    }
    else{
        if(head->next == NULL)
        {
            cout<<"\nThe element is deleted and its value is : "<<head->data;
            delete head;
            return NULL;
        }
        temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        
        cout<<"\nThe element is deleted and its value is : "<<temp->data;
        delete temp;
        return head;
    }
}

// insertion at the end
node * deletionAtTheEnd(node * head){
    node * temp = head;
    node * curr = NULL;

    if(head == NULL){
        cout<<"\nUNDERFLOW!!! The list is empty!";
        return NULL;
    }
    else{
        if(head->next == NULL)
        {
            cout<<"\nThe element is deleted and its value is : "<<head->data;
            delete head;
            return NULL;
        }

        while(temp->next != NULL)
        {
            curr = temp;
            temp = temp->next;
        }
        curr->next = temp->next;
        temp->prev = NULL;

        cout<<"\nThe element is deleted and its value is : "<<temp->data;
        delete temp;
        return head;
    }
}

// Insertion at any specified position
node * deletionAtSpecifiedPosition(node * head){
    node * temp = head;
    node * del = NULL;

    int pos;
    cout<<"\nPosition: ";
    cin>>pos;

    if(head == NULL){
        cout<<"\nUNDERFLOW!!! The list is empty!";
        return NULL;
    }
    else{
        while(--pos && temp != NULL)
        del = temp,temp = temp->next;

        if(pos != 0)
        {
            cout<<"\nInvalid POSITION !!!";
            return head;
        }

        if(head->next == NULL)
        {
            cout<<"\nThe element is deleted and its value is : "<<head->data;
            delete head;
            
            return NULL;
        }
        del->next = temp->next;
        temp->prev = NULL;
        temp->next->prev = del;

        cout<<"\nThe element is deleted and its value is : "<<temp->data;
        delete temp;

        return head;
    }
}

// Printing the Doubly Linked List
void printDoublyList(node * head)
{
    if(head == NULL)
    cout<<"\nThe List is Empty!!!";
    else{
        while(head != NULL)
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
        cout<<"\nSelect any:\n1. Insertion at the TOP\n2. Deletion at the TOP\n3. Deletion at the END\n4. Deletion at any specified position\n5. Print List\n\nEnter your choice: ";
        cin>>select;
        switch (select)
        {
        case 1: head = insertionAtTheTop(head);
            break;
        case 2: head = deletionAtTheTop(head);
            break;
        case 3: head = deletionAtTheEnd(head);
            break;
        case 4: head = deletionAtSpecifiedPosition(head);
            break;
        case 5: printDoublyList(head);
            break;
        default:    cout<<"\nINVALID INPUT !!!";
            break;
        }

        cout<<"\n\nWant to continue?(Y/N): ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');

}