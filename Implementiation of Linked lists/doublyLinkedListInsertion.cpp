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

// insertion at the end
node * insertionAtTheEnd(node * head){
    node * temp = head;
    node * n = createNode();

    if(head == NULL){
        head = n;
        return head;
    }
    else{
        while(temp->next != NULL)
        temp = temp->next;

        temp->next = n;
        n->prev = temp;
        return head;
    }
}

// Insertion at any specified position
node * insertionAtSpecifiedPosition(node * head){
    node * temp = head;
    node * n = createNode();
    int pos;
    cout<<"\nPosition: ";
    cin>>pos;

    if(head == NULL && pos <=1 ){
        head = n;
        return head;
    }
    else{
        while(--pos && temp != NULL)
        temp = temp->next;

        if(pos != 0)
        {
            cout<<"\nInvalid POSITION !!!";
            return head;
        }
        n->next = temp->next;
        temp->next = n;
        n->prev = temp;

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
        cout<<"\nSelect any:\n1. Insertion at the TOP\n2. Insertion at the END\n3. Insertion at any specified position\n4. Print List\n\nEnter your choice: ";
        cin>>select;
        switch (select)
        {
        case 1: head = insertionAtTheTop(head);
            break;
        case 2: head = insertionAtTheEnd(head);
            break;
        case 3: head = insertionAtSpecifiedPosition(head);
            break;
        case 4: printDoublyList(head);
            break;
        default:    cout<<"\nINVALID INPUT !!!";
            break;
        }

        cout<<"\n\nWant to continue?(Y/N): ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');

}