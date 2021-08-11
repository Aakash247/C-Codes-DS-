#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class TreeNode
{
public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int ele)
    {
        data=ele;
    }

    ~TreeNode()
    {
        for(int i=0;i<children.size();i++)
        {
            delete children[i];
        }
    }

};

void print(TreeNode *root)
{
    if(!root)
        return;
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;


    for(int i=0;i<root->children.size();i++)
    {
        print(root->children[i]);
    }
 }


TreeNode* takeInput()
{
    int rootdata;
    cout<<"Input data:";
    cin>>rootdata;
    TreeNode *root=new TreeNode(rootdata);
    cout<<"Input no of children of "<<rootdata<<": ";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        TreeNode* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode* takeInputIterative()
{
    int rootdata;
    cout<<"Input Root Data:";
    cin>>rootdata;
    TreeNode *root= new TreeNode(rootdata);
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        cout<<"Input Number Of Children of "<<q.front()->data<<":";
        int n;
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            int data;
            cout<<"Input the value of "<<i<<"th child :";
            cin>>data;
            TreeNode *child=new TreeNode(data);
            q.push(child);
            q.front()->children.push_back(child);
        }
        q.pop();
    }
    return root;
}

void printLevelWise(TreeNode* root)
{
    if(!root)
        return;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        cout<<q.front()->data<<" : ";
        int s=q.front()->children.size();
        for(int i=0;i<s;i++)
        {
            q.push(q.front()->children[i]);
            cout<<q.front()->children[i]->data<<",";
        }
        cout<<endl;
        q.pop();
    }
    return;
}

int height(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int mx=0;
    for(int i=0;i<root->children.size();i++)
    {
        int childheight=height(root->children[i]);
        if(childheight>mx)
            mx=childheight;
    }
    return mx+1;

}

void printAtLevelK(TreeNode *root,int k)
{
    if(root==NULL)
        return;
    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        printAtLevelK(root->children[i],k-1);
    }
}

int countLeafNodes(TreeNode *root)
{
    if(root==NULL)
        return 0;

    int size=0;
    for(int i=0;i<root->children.size();i++)
    {

        size=size+countLeafNodes(root->children[i]);
    }

    if(root->children.size()==0)
        size++;
    return size;


}

int count(TreeNode *root)
{
    if(root==NULL)
        return 0;
    int size=1;
    for(int i=0;i<root->children.size();i++)
    {
        size=size+count(root->children[i]);
    }
    return size;
}

void preOrder(TreeNode * root)
{
    if(root==NULL)
        return;
    cout<<root->data<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        preOrder(root->children[i]);
    }
}

void postOder(TreeNode *root)
{
    if(root==NULL)
        return;
    for(int i=0;i<root->children.size();i++)
    {
        postOder(root->children[i]);
    }
    cout<<root->data<<endl;
}

int main()
{
    /*TreeNode<int> *root=new TreeNode<int>(1);
    TreeNode<int> *n1=new TreeNode<int>(2);
    TreeNode<int> *n2=new TreeNode<int>(3);
    root->children.push_back(n1);
    root->children.push_back(n2);
    */

    TreeNode *root=takeInputIterative();
    postOder(root);
    delete root;
    return 0;
}
