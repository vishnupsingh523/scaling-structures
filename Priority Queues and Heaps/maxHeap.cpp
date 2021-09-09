#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int * arr;
    int capacity;
    int count=0;
    // int heap_type;
};

heap * createHeap(int capacity)
{
    heap * h = new heap();
    if(h==NULL)
    {
        cout<<"\nCan't create Heap - MEMORY ERROR !!!";
        return NULL;
    }

    cout<<"Heap Created Succesfully\n";
    h->capacity = capacity;
    // h->heap_type = heap_type;
    h->count= 0;
    h->arr = new int(capacity);

    if(h->arr == NULL)
    {
        cout<<"\nCan't create Heap - MEMORY ERROR !!!";
        return NULL;
    }
    cout<<"Array created succesfully\n";
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
int getMaxMin(heap * h)
{
    if(h->count = 0)
    return -1;
    
    return h->arr[0];
}

// RESIZING heap function 
heap * resizeHeap(heap * h)
{
    int * oldArr = h->arr;
    h->arr = new int(h->capacity * 2);
    if(!h->arr)
    {
        cout<<"MEMORY ERROR !!!";
        return NULL;
    }

    for(int i=0;i<h->capacity; i++)
    h->arr[i] = oldArr[i];

    h->capacity = h->capacity * 2;
    delete oldArr;
    return h;
}


// function to insert into heap
heap * insertElement(heap * h, int data){
    int i;
    if(h->count == h->capacity)
    h = resizeHeap(h);

    i = h->count;
    h->count++;
    while(i>0 && data > h->arr[(i-1)/2])
    {
        h->arr[i] = h->arr[(i-1)/2];
        i = (i-1)/2;
    }

    h->arr[i] = data;

    cout<<"Element inserted Succesfully and value : "<<data<<"\n";
    return h;
}

void percolateDown(heap * h, int index)
{
    int l, r, temp, max;
    l = leftChild(h,index);
    r = rightChild(h, index);

    if(l!=-1 && h->arr[l]>h->arr[index])
    max = l;
    else
    max = index;

    if(r!=-1 && h->arr[r] > h->arr[max])
    max = r;

    if(max != index)
    {
        // Swapping the elements here;
        temp = h->arr[index];
        h->arr[index] = h->arr[max];
        h->arr[max] = temp;
    }

    percolateDown(h, max);
}
// Deleting element fucntion
heap * deleteMax(heap * h)
{
    int data;
    if(h->count ==0)
    {
        cout<<"Heap Is empty !!\n";
    }
    else{
        data = h->arr[0];
        h->arr[0] = h->arr[h->count-1];
        h->count--;

        percolateDown(h,0);

        cout<<"\nDeleted Element : "<<data;
    }
    return h;
}

void destroyHeap(heap * h)
{
    if(h==NULL)
    return;
    delete h->arr;
    delete h;
}

// Main function
int main()
{
    heap * h = createHeap(10);
    int value;
    char ch;

    do{
        cout<<"\n\n1. Insert\n2. Delete\n3. Find Maximum\n4. Print\nEnter your choice : ";
        int size;
        cin>>size;

        switch(size)
        {
            case 1:
                cin>>value;
                h = insertElement(h, value);
                break;
            case 2: 
                h = deleteMax(h);
                break;
            case 3:
                cout<<"\nMaximum : "<<getMaxMin(h);
                break;
            case 4:
                cout<<"\nHeap values : ";
                for(int i=0;i<h->count;i++)
                cout<<h->arr[i]<<" ";
                break;

            default: cout<<"\nINVALID INPUT !!!";

        }
        
        cout<<"\nDo you want to continue (Y?N) : ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');

    destroyHeap(h);

    return 0;
}