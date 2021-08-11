#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void printDFS(vector<vector<int>> v,vector<bool> &visited,int sv)
{
    cout<<sv<<endl;
    visited[sv]=true;

    //traversing in row to find next adjacent vertex
    for(int i=0;i<v.size();i++)
    {
        if(v[sv][i]==1 && visited[i]==false)
        {
            printDFS(v,visited,i);
        }
    }
}

void DFS(vector<vector<int>> matrix)
{
    int n=matrix.size();
    vector<bool> visited(n,false);
    int connected=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            connected++;
            printDFS(matrix,visited,i);
        }
    }
    cout<<"Connected Components= "<<connected;
}

void printBFS(vector<vector<int>> v)
{
    vector<bool> visited(v.size(),false);
    queue<int> q;
    int sv;
    int connected=0;
    int n=visited.size();
    for(int j=0;j<n;j++)
    {
        if(!visited[j])
        {
            connected++;
            sv=j;
            q.push(sv);
            visited[sv]=true;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                cout<<node<<endl;
                for(int i=0;i<v.size();i++)
                {
                    if(v[node][i]==1 && visited[i]==false)
                    {
                        q.push(i);
                        visited[i]=true;
                    }
                }
            }
        }
    }
    cout<<"Connected Components= "<<connected;
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
        matrix[sv][fv]=1;
    }

    printBFS(matrix);



    return 0;
}
