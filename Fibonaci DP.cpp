#include<iostream>
using namespace std;

//top down
int fib(int *arr,int n)
{
    if(n==0 || n==1)
        {
            return n;
        }

    if(arr[n]!=0)
            return arr[n];
    int output=fib(arr,n-1)+fib(arr,n-2);
    arr[n]=output;
    return output;
}

//bottom up
int fib2(int n)
{
    int *arr=new int[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    int output=arr[n];
    delete []arr;
    return output;
}

int main()
{
    cout<<"Enter n :";
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
        arr[i]=0;
    cout<<fib2(n)<<endl;
    cout<<fib(arr,n)<<endl;
    delete []arr;
    return 0;
}
