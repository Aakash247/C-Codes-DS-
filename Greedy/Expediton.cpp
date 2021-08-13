#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first>p2.first;
}

int main()
{
    int n,d,f,D,F;
    vector<pair<int,int>> v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d>>f;
        v.push_back(make_pair(d,f));
    }

    sort(v.begin(),v.end(),compare);

    cin>>D>>F;

    for(int i=0;i<n;i++)
    {
        v[i].first=D-v[i].first;
    }

    int prev=0,x=0;
    int flag=0,ans=0;
    priority_queue<int> pq;
    while(x<n)
    {
        if(F>=v[x].first-prev)
        {
            pq.push(v[x].second);
            F=F-(v[x].first-prev);
            prev=v[x].first;
        }
        else
        {
            if(pq.empty())
            {
                flag=1;
                break;
            }
            else
            {
                F+= pq.top();
                pq.pop();
                ans++;
                continue;
            }
        }
        x++;
    }

    if(flag==1)
    {
        cout<<-1;
        return 0;
    }

    else
    {
        int dist=D-v[n-1].first;
        if(F>=dist)
        {
            cout<<ans;
            return 0;
        }

        while(F<dist)
        {
            if(pq.empty())
            {
                flag=1;
                break;
            }
            else
            {
                F+=pq.top();
                pq.pop();
                ans++;
            }
        }

        if(flag==1)
        {
            cout<<-1;
            return 0;
        }
        else
        {
            cout<<ans;
            return 0;
        }
    }
}
