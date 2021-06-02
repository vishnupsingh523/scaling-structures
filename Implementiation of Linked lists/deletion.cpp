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

// Deletion at the top
node * deletionAtTheTop(node * head){
    node * curr;
    if(head == NULL)
    {
        cout<<"\nUNDERFLOW !!! The List is empty!";
        return NULL;
    }
    else{
        curr = head;
        head = head->next;
        cout<<"\nThe node has been deleted and its value is : "<<curr->data;
        delete curr;
        return head;
    }
}

// Deletion at the top
node * deletionAtTheEnd(node * head){
    node * curr;
    node * temp = head;
    if(head == NULL)
    {
        cout<<"\nUNDERFLOW !!! The List is empty!";
        return NULL;
    }
    else{
        while(temp->next != NULL)
        {
            curr = temp;
            temp = temp->next;
        }
        curr->next = temp->next;
        cout<<"\nThe node has been deleted and its value is : "<<temp->data;
        delete temp;
        return head;
    }
}

// Deletion from any specified position
node * deletionFromSpecifiedPosition(node * head){
    node * curr;
    node * temp = head;
    int pos;
    cout<<"\nEnter Position: ";
    cin>>pos;
    
    if(head == NULL)
    {
        cout<<"\nUNDERFLOW !!! The List is empty!";
        return NULL;
    }
    else{
        while(--pos && temp != NULL)
        {
            curr = temp;
            temp = temp->next;
        }
        curr->next = temp->next;
        temp->next = NULL;
        cout<<"\nThe node has been deleted and its value is : "<<temp->data;
        delete temp;
        return head;
    }
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
        cout<<"\nSelect any:\n1. Insertion\n2. Deletion at the END\n3. Deletion at the TOP\n4. Deletion at any specified position\n5. Print List\n\nEnter your choice: ";
        cin>>select;
        switch (select)
        {
        case 1: head = insertionAtTheTop(head);
            break;
        case 2: head = deletionAtTheEnd(head);
            break;
        case 3: head = deletionAtTheTop(head);
            break;
        case 4: head = deletionFromSpecifiedPosition(head);
            break;
        case 5: printLinkedList(head);
            break;
        default:    cout<<"\nINVALID INPUT !!!";
            break;
        }

        cout<<"\n\nWant to continue?(Y/N): ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');

    
}