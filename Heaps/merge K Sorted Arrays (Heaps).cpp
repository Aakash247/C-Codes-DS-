#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> node;


vector<int> mergeKSortedArrays(vector<vector<int>> v,int k,int n)
{
    priority_queue<node,vector<node>,greater<node>> pq;
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        pq.push(make_pair(v[i][0],make_pair(i,0)));
    }




    while(!pq.empty())
    {
        node temp=pq.top();
        pq.pop();
        int x=temp.second.first;
        int y=temp.second.second;
        int val=temp.first;
        ans.push_back(val);

        if(y+1<n)
        {
            pq.push(make_pair(v[x][y+1],make_pair(x,y+1)));
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> v;
    int k,n;
    cin>>k>>n;
    for(int i=0;i<k;i++)
    {
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            int ele;
            cin>>ele;
            temp.push_back(ele);
        }
        v.push_back(temp);
    }

    /*
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }*/
    vector<int> result;
    result=mergeKSortedArrays(v,k,n);

    for(auto z:result)
        cout<<z<<" ";

}
