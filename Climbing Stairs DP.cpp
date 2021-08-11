#include<iostream>
using namespace std;

int climbingStairs(int n,int k)
{
    int *arr=new int[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++)
    {
        int ans=0;
        for(int j=1;i-j>=0 && j<=k;j++)
        {
            ans=ans+arr[i-j];
        }
        arr[i]=ans;
    }
    int output=arr[n];
    delete []arr;
    return output;
}

int main()
{
    cout<<climbingStairs(8,2);
    return 0;
}
