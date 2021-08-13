#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        //all inputs
        int n;
        cin>>n;
        int c[n],d[n];
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>d[i];
        }


        //logic code
        int x=0,ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        while(x<n)
        {
            pq.push(c[x]);
            ans=ans+(pq.top()*d[x]);
            x++;
        }

        cout<<ans<<endl;



    }
}
