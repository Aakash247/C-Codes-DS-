#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,deltax=0,deltay=0;
    vector<int> X,Y;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        X.push_back(x);
        Y.push_back(y);
    }

    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());

    for(int i=1;i<n;i++)
    {
        deltax=max(deltax,X[i]-X[i-1]-1);
        deltay=max(deltay,Y[i]-Y[i-1]-1);
    }

    cout<<deltax*deltay;
    return 0;
}
