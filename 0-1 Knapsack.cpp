#include<iostream>
#include<vector>
using namespace std;
int knapSack(int items,vector<int> price,vector<int> weight,int w)
{
    if(items==0 || w==0)
        return 0;

    if(weight[items]>w)
        return knapSack(items-1,price,weight,w);
    else
    {
        int include=price[items-1]+knapSack(items-1,price,weight,w-weight[items-1]);
        int exclude=0+knapSack(items-1,price,weight,w);
        return max(include,exclude);
    }
}

int knapSackDP(int n,int w,vector<int> price,vector<int> weight)
{
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(weight[i-1]>j)
                dp[i][j]=dp[i-1][j];

            else
            {
                int include,exclude;
                include=price[i-1]+dp[i-1][j-weight[i-1]];
                exclude=dp[i-1][j];
                dp[i][j]=max(include,exclude);
            }
        }
    }

    return dp[n][w];
}

int main()
{
    vector<int> price={25,10,20,60};
    vector<int> weight={4,3,5,6};
    int w=10,items=4;
    cout<<knapSackDP(4,w,price,weight);
    return 0;
}
