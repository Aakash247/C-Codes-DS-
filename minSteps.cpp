#include<iostream>
using namespace std;

//recursive
int minSteps(int n)
{
    if(n==1)
        return 0;
    if(n%2==0 && n%3==0)
    {
        int output=1+min(minSteps(n-1),min(minSteps(n/2),minSteps(n/3)));
        return output;
    }
    else if(n%2==0 && n%3!=0)
    {
        int output=1+min(minSteps(n-1),minSteps(n/2));
        return output;
    }
    else if(n%2!=0 && n%3==0)
    {
        int output=1+min(minSteps(n-1),minSteps(n/3));
        return output;
    }
    else
    {
        int output=1+minSteps(n-1);
        return output;
    }

}

//top down
int minSteps2(int n,int *arr)
{
    if(n==1)
        return 0;

    if(arr[n]!=-1)
    {
        return arr[n];
    }

    else
    {
        if(n%2==0 && n%3==0)
        {
            int output=1+min(minSteps2(n-1,arr),min(minSteps2(n/2,arr),minSteps2(n/3,arr)));
            arr[n]=output;
            return output;
        }
        else if(n%2==0 && n%3!=0)
        {
            int output=1+min(minSteps2(n-1,arr),minSteps2(n/2,arr));
            arr[n]=output;
            return output;
        }
        else if(n%2!=0 && n%3==0)
        {
            int output=1+min(minSteps2(n-1,arr),minSteps2(n/3,arr));
            arr[n]=output;
            return output;
        }
        else
        {
            int output=1+minSteps2(n-1,arr);
            arr[n]=output;
            return output;
        }
    }
}

//bottom up
int minSteps3(int n)
{
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
        arr[i]=-1;
    arr[1]=0;
    for(int i=2;i<=n;i++)
    {
        int x,y=INT_MAX,z=INT_MAX;
        x=arr[i-1];
        if(i%2==0)
        {
            y=arr[i/2];
        }
        if(i%3==0)
        {
            z=arr[i/3];
        }
        arr[i]=min(x,min(y,z))+1;
    }
    int output=arr[n];
    delete []arr;
    return output;
}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=-1;
    }
    cout<<minSteps(n)<<endl;
    cout<<minSteps2(n,arr)<<endl;
    cout<<minSteps3(n)<<endl;
    delete []arr;
    return 0;
}
