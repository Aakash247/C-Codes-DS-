#include<iostream>
using namespace std;

void inplaceHeapSort(int *arr,int n)
{
    //build heap
    for(int i=1;i<n;i++)
    {
        int childIndex=i;

        //this loop compares parent  and child  and swaps if child is greater than parent
        //this loop traverse upward since called up heapify
        while(childIndex>0 && arr[childIndex]<arr[((childIndex-1)/2)])
        {
            swap(arr[childIndex],arr[((childIndex-1)/2)]);
            childIndex=((childIndex-1)/2);
        }
    }

    //remove min element n times
    int size=n;
    while(size>=1)
    {
        swap(arr[0],arr[size-1]);
        size--;

        int pi=0;
        while(true)
        {
            int mini,li,ri;
            mini=pi;
            li=pi*2+1;
            ri=pi*2+2;

            if(li<size && arr[li]<arr[mini])
            {
                mini=li;
            }
            if(ri<size && arr[ri]<arr[mini])
            {
                mini=ri;
            }
            if(pi==mini)
            {
                break;
            }
            swap(arr[pi],arr[mini]);
            pi=mini;
        }
    }





}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int arr[]={4,7,2,1,8,10,12,3};
    inplaceHeapSort(arr,8);
    print(arr,8);
    return 0;
}
