#include <bits/stdc++.h>
using namespace std;

int main() {
    /* code here */
    int t;
    cin>>t;
    while(t--)
    {
        priority_queue<int> left;
        priority_queue<int,vector<int>,greater<int>> right;

        int n;
        cin>>n;

        int d;
        cin>>d;

        float median=d;
        left.push(d);
        cout<<"Median="<<median<<endl;

        for(int i=1;i<n;i++)
        {
            cin>>d;

            if(left.size()>right.size())
            {
                if(d<=median)
                {
                    right.push(left.top());
                    left.pop();
                    left.push(d);
                }
                else
                {
                    right.push(d);
                }

                median=(left.top()+right.top())/2.0;
            }
            else if(left.size()==right.size())
            {
                if(d<=median)
                {
                    left.push(d);
                    median=left.top();
                }
                else
                {
                    right.push(d);
                    median=right.top();
                }
            }
            else
            {
                if(d>median)
                {
                    left.push(right.top());
                    right.pop();
                    right.push(d);
                }
                else
                {
                    left.push(d);
                }

                median=(left.top()+right.top())/2.0;
            }

            cout<<"Median="<<median<<endl;
        }
    }
    return 0;
}
