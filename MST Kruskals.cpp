#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src,des,wt;
};

vector<int> parent;
vector<Edge> mst;

bool comparator(Edge a,Edge b)
{
	return a.wt < b.wt;
}

int findRoot(int a)
{
    while(parent[a]!= -1 )
    {
        a=parent[a];
    }
    if(parent[a]==-1)
        return a;
}

void unionSet(int src,int dest)
{
    int fi=findRoot(src);
    int si=findRoot(dest);

    if(fi!=si)
    {
        parent[si]=fi;
    }
}


void kruskal(vector<Edge> edge_list)
{
    sort(edge_list.begin(),edge_list.end(),comparator);

    //print sorted edge list
    /*
    for(int i=0;i<edge_list.size();i++)
    {
        cout<<edge_list[i].wt<<endl;
    }
    */

    for(int i=0;i<edge_list.size();i++)
    {
        int fa,fb;
        fa=findRoot(edge_list[i].src);
        fb=findRoot(edge_list[i].des);

        if(fa!=fb)
        {
            unionSet(edge_list[i].src,edge_list[i].des);
            mst.push_back(edge_list[i]);
        }
    }
}

int main()
{
    vector<Edge> edge_list;
    int n,e;
    cout<<"Enter Number Of vertices :";
    cin>>n;
    cout<<"Enter Number Of Edges :";
    cin>>e;
    parent.resize(e);
    for(int i=0;i<parent.size();i++)
        parent[i]=-1;
    cout<<"Enter edges:"<<endl;
    vector<vector<int>> matrix(n,vector<int>(n,INT_MIN));
    for(int i=0;i<e;i++)
    {
        Edge temp;
        int fv,sv,weight;
        cout<<"Enter Source and Destination Nodes : ";
        cin>>fv>>sv;
        cout<<"Enter Weight : ";
        cin>>weight;
        matrix[fv][sv]=weight;
        matrix[sv][fv]=weight;
        temp.src=fv;
        temp.des=sv;
        temp.wt=weight;
        edge_list.push_back(temp);


    }

    kruskal(edge_list);

    for(int i=0;i<mst.size();i++)
    {
        cout<<mst[i].src<<"->"<<mst[i].des<<endl;
    }

    return 0;
}
