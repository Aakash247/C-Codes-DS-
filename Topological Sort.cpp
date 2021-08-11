#include<iostream>
#include<vector>
#include<stack>
using namespace std;
stack<int> s;
void helper(vector<vector<int>> matrix,vector<bool> &visited,int sv)
{
    visited[sv]=true;
    int n=matrix.size();
    for(int i=0;i<n;i++)
    {
        if(matrix[sv][i]==1 && visited[i]==false)
        {
            helper(matrix,visited,i);

        }
    }
    s.push(sv);
}

void topologicalSort(vector<vector<int>> matrix)
{
    int n=matrix.size();
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            helper(matrix,visited,i);
        }
    }

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }

}

int main()
{
    int n,e;
    cout<<"Enter Number Of vertices :";
    cin>>n;
    cout<<"Enter Number Of Edges :";
    cin>>e;
    cout<<"Enter edges:"<<endl;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i=0;i<e;i++)
    {
        int fv,sv;
        cin>>fv>>sv;
        matrix[fv][sv]=1;
    }

    topologicalSort(matrix);

    return 0;
}
