#include<iostream>
#include<queue>
using namespace std;

void kSortedArray(int *arr,int k,int size)
{
    priority_queue<int> pq;
    int s=0;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }

    for(int i=k;i<size;i++)
    {
        arr[s]=pq.top();
        s++;
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty())
    {
        arr[s]=pq.top();
        s++;
        pq.pop();
    }
}

void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
}

int main()
{
    int arr[]={10,12,6,7,9};
    kSortedArray(arr,3,5);
    print(arr,5);
    return 0;
}
