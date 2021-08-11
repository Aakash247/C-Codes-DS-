#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int coinChange(int coins[],int n,int money)
{
    int ans=0;
    while(money>0)
    {
        auto it=upper_bound(coins,coins+n,money);
        int index=distance(coins,it)-1;
        //or int index=upper_bound(coins,coins+n,money)-coins-1;
        //cout<<index<<endl;
        money-=coins[index];
        ans++;
    }
    return ans;
}



int main() {
    int coins[]={1,2,5,10,20,50,100,500,2000};
    int money;
    cin>>money;
    int change=coinChange(coins,9,money);
    cout<<change;
}
