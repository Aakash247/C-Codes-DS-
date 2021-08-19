#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int join_ropes(int arr[],int n)
{
    int ans=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }



    while(pq.size()!=1)
    {
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        ans+=x+y;
        pq.push(x+y);
    }
    return ans;

}

int main() {
    int ropes[]={4,3,2,6};
    int n=4;
    cout<<join_ropes(ropes,n)<<endl;
    return 0;
}
