#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int * arr;
    int capacity;
    int count=0;
    int heap_type;
};

heap * createHeap(int capacity, int heap_type)
{
    heap * h = new heap();
    if(!h)
    {
        cout<<"\nCan't create Heap - MEMORY ERROR !!!";
        return NULL;
    }

    h->capacity = capacity;
    h->heap_type = heap_type;
    h->count= 0;
    h->arr = new int(capacity);

    if(!h->arr)
    {
        cout<<"\nCan't create Heap - MEMORY ERROR !!!";
        return NULL;
    }
    return h;
}

int parent(heap * h, int i)
{
    if(i<=0 || i>= h->capacity)
    return -1;

    return (i-1)/2;
}

// returning left child index
int leftChild(heap * h, int i)
{
    int left = 2*i+1;
    if(left >= h->count)
    return -1;
    
    return left;
}

// returning right child index;
int rightChild(heap * h, int i)
{
    int right = 2*i+2;
    if(right >= h->count)
    return -1;

    return right;
}

// getting maximum element fromt he heap
int getMax(heap * h)
{
    if(h->count = 0)
    return -1;
    
    return h->arr[0];
}
int main()
{
    int size;
    cout<<"Size: ";
    cin>>size;

    heap * h = createHeap(size,0);

    cout<<"\nEnter Values: ";
    int value;
    for(int i=0;i<size;i++)
    {
        cin>>h->arr[i];
        h->count++;
    }

    cout<<endl<<endl;
    for(int i=0;i<h->count;i++)
    cout<<h->arr[i]<<" ";
}