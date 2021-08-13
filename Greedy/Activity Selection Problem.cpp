#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second<p2.second;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
        vector<pair<int,int>> v;
        int s,e;
        for(int i=0;i<n;i++)
        {
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }

        sort(v.begin(),v.end(),compare);

        int prev_end=v[0].second;int ans=1;
        for(int i=1;i<n;i++)
        {
            if(v[i].first>=prev_end)
            {
                ans++;
                prev_end=v[i].second;
            }
        }
        cout<<ans<<endl;
    }
}
