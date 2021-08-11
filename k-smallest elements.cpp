#include<iostream>
#include<queue>
using namespace std;

void kSmallestElements(int *a,int n,int k)
{
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(a[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(a[i]<pq.top())
        {
            pq.pop();
            pq.push(a[i]);
        }
    }

    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}

void kSmallestElements2(int *a,int n,int k)
{
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(a[i]);
    }
    for(int i=k;i<n;i++)
    {
        pq.push(a[i]);
        pq.pop();
    }

    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}

int main()
{
    int arr[]={5,2,7,3,9,0,6};
    kSmallestElements2(arr,7,3);
    return 0;
}
