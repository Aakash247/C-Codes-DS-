#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> deleteDup(vector<int> a)
{
    unordered_map<int,bool> mymap;

    for(auto it=a.begin();it!=a.end();it++)
    {
        if(mymap.count(*it)==0)
        {
            mymap[*it]=true;
        }
        else
        {
            a.erase(it);
            it--;

        }

    }
    return a;
}

int main()
{
    vector<int> a={1,2,5,4,1,3,2,5,4,2,1,3,3,2,1,4};
    a=deleteDup(a);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }

}
