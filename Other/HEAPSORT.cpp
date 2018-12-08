#include<iostream>
#include<stdio.h>

using namespace std;

int a[20],n;
void heapify();

void display()
{
    int i;
    for(i=1;i<=n;i++)
    cout<<" "<<a[i];
    cout<<"\n";
}
void insert(int num,int pos)
{
    int parent;
    while(pos>0)
    {
        parent=pos/2;
        if (num>=a[parent])
        {
            a[pos]=num;
            return;
        }
        a[pos]=a[parent];
        pos=parent;
    }
    a[n]=num;
}

void heapify()
{
    int i;
    for(i=1;i<=n;i++)
    insert(a[i],i);
}

void percolate()
{
    int left,right,i,save;
    i=1;
    save = a[1];
    cout<<" "<<save;
    swap(a[i],a[n--]);
    heapify();
}

void heap_sort()
{
    int start;  int k = n;
    for(start=1; start<=k; start++)
        percolate();
}

int main()
{
    int i;
    cout<<"\nEnter number of elements : ";
        cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    cout<<"\nEntered list is :\n";
    display();
    heapify();
    cout<<"\nHeap is : \n";
    display();
        cout<<"\nSorted list is : \n";
    heap_sort();
    return 0;
}
/*
void heap_sort()
{
    int start,i,pos;  int k = n, parent;
    for(start=1; start<=k; start++){
        cout<<" "<<a[1];
        swap(a[1],a[n--]);
        for(i=1;i<=n;i++){
            pos = i;
            while(pos>0)
            {
                parent=pos/2;
                if (a[i]>=a[parent]){
                    a[pos]=a[i];
                    break;
                }
                a[pos]=a[parent];
                pos=parent;
            }
            a[n]=a[i];
        }
    }
}*/
