#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        int arr[n],counting[n+1];
        string name;
        int badness=0;
        for(int i=0;i<n;i++)
        {

            cin>>name;
            cin>>arr[i];
        }
        for(int i=0;i<n+1;i++)
        {
            counting[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            counting[arr[i]]+=1;
        }


        int rank=1;
        int j=1;
        while(rank<=n && j<n+1)
        {
            if(counting[j]==0)
            {
                j++;
            }
            else
            {
                int temp=abs(rank-j);
                badness+=temp;
                counting[j]--;
                rank++;
            }
        }
        cout<<badness;
        t--;
    }


    return 0;
}
