#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * left;
    node * right;

    node(){
        left = right = NULL;
    }

    node(int num)
    {
        data = num;
        left = right = NULL;
    }
};

class Queue{
    public:
    node * front;
    node * rear;
};

Queue * createQueue()
{
    node * temp = new node();
    Queue * Q = new Queue();

    if(!Q)
    return NULL;
    Q->front = Q->rear = NULL;

    return Q;
}

// Returns the front element of the QUEUE:
int frontElement(Queue * Q)
{
    return Q->front->data;
}
// Returns the last element of the QUEUE:
int rearElement(Queue * Q)
{
    return Q->rear->data;
}

// check if Queue is empty or not;
void isEmpty(Queue * Q)
{
    if(Q->front == NULL && Q->rear == NULL)
    cout<<"\nEmpty Queue\n";
    else 
    cout<<"\nNon Empty Queue\n";
}

// Adding element is the queue
void enQueue(Queue * Q, node * newNode)
{
    if(Q->rear == NULL)
    Q->front = Q->rear = newNode;
    else{
        Q->rear->left = newNode;

    }
}