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

        for(int i=0;i<n;i++)
        {
            counting[arr[i]]+=1;
        }
        for(int i=0;i<n;i++)
        {
            cout<<counting[i];
        }

        /*for(int i=1;i<=n;i++)
        {
            int j=0;
            while(counting[j]==0&&j<=n)
            {
                j++;
            }
            if(counting[j]!=0)
            {
                badness=badness+i-j;
                counting[j]--;
            }
        }*/
        cout<<badness;
        t--;
    }


    return 0;
}
