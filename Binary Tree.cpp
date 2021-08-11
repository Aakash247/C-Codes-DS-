#include<iostream>
#include<queue>
using namespace std;

class BTNode
{
public:
    int data;
    BTNode *left;
    BTNode *right;

    BTNode(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BTNode()
    {
        delete left;
        delete right;
    }
};


void printRecursively(BTNode *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<":";
    if(root->left!=NULL)
    {
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right!=NULL)
    {
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printRecursively(root->left);
    printRecursively(root->right);
}


BTNode* takeInputRecursively()
{
    cout<<"Enter Data: ";
    int rootdata;
    cin>>rootdata;
    if(rootdata==0)
        return 0;
    BTNode *root=new BTNode(rootdata);
    cout<<"Enter left child of "<<root->data<<endl;
    root->left=takeInputRecursively();
    cout<<"Enter right child of "<<root->data<<endl;
    root->right=takeInputRecursively();
    return root;
}


BTNode* takeInputLevelWise()
{
    cout<<"Enter Data: ";
    int rootdata;
    cin>>rootdata;
    if(rootdata==0)
        return 0;
    BTNode *root=new BTNode(rootdata);
    queue<BTNode*> q;
    q.push(root);

    while(!q.empty())
    {
        BTNode *temp=q.front();
        q.pop();

        cout<<"Enter Left child of "<<temp->data<<" :";
        int leftc;
        cin>>leftc;
        if(leftc!=0)
        {
            BTNode *leftchild=new BTNode(leftc);
            q.push(leftchild);
            temp->left=leftchild;
        }

        cout<<"Enter Right child of "<<temp->data<<" :";
        int rightc;
        cin>>rightc;
        if(rightc!=0)
        {
            BTNode *rightchild=new BTNode(rightc);
            q.push(rightchild);
            temp->right=rightchild;
        }

    }
    return root;

}


void printLevelWise(BTNode *root)
{
    queue<BTNode*> q;
    q.push(root);

    while(!q.empty())
    {
        BTNode *temp=q.front();
        q.pop();
        cout<<temp->data<<" : ";
        if(temp->left!=NULL)
        {
            q.push(temp->left);
            cout<<"L"<<temp->left->data<<" ";
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
            cout<<"R"<<temp->right->data<<" ";
        }
        cout<<endl;
    }
}


void printLevels(BTNode *root)
{
    if(root==NULL)
        return;
    queue<BTNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        BTNode *f=q.front();
        q.pop();
        if(f==NULL)
        {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<f->data<<" ";
            if(f->left!=NULL)
                q.push(f->left);
            if(f->right!=NULL)
                q.push(f->right);
        }
    }
}


int countNodes(BTNode *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    else
    {
        return 1+countNodes(root->left)+countNodes(root->right);
    }
}


void inorder(BTNode *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}


void preorder(BTNode *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}


void postorder(BTNode *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}


int depth(BTNode *root)
{
    if(root==NULL)
        return 0;

    int left=depth(root->left);
    int right=depth(root->right);
    return 1+max(left,right);
}


bool search(BTNode *root,int node)
{
    if(root==NULL) return false;
    if(root->data==node) return true;
    return search(root->left,node)|| search(root->right,node);
}


int minValueiterative(BTNode *root)
{
    if(root==NULL)
        return 0;
    int minimun=root->data;
    queue<BTNode*> q;
    q.push(root);

    while(!q.empty())
    {
        BTNode *temp=q.front();
        q.pop();
        if(temp->data<minimun)
        {
            minimun=temp->data;
        }
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
    return minimun;
}


int minValue(BTNode *root)
{
    if(root==NULL)
        return INT_MAX;
    int leftmin=minValue(root->left);
    int rightmin=minValue(root->right);
    return min(root->data,min(leftmin,rightmin));
}

void minValueRefrence(BTNode *root,int &ans)
{
    if(root==NULL)
        return;
    if(root->data<ans)
        ans=root->data;
    minValueRefrence(root->left,ans);
    minValueRefrence(root->right,ans);
}

int maxValue(BTNode *root)
{
    if(root==NULL)
        return INT_MIN;
    int leftmax=maxValue(root->left);
    int rightmax=maxValue(root->right);
    return max(root->data,max(leftmax,rightmax));
}


int countLeafNodes(BTNode *root)
{
    int size=0;
    if(root==NULL)
        return size;
    if(root->right==NULL && root->left==NULL)
        return ++size;
    int rightnodes=countLeafNodes(root->right);
    int leftnodes=countLeafNodes(root->left);
    return leftnodes+rightnodes;
}


bool getPath(BTNode *root,int val,vector<int> &v)
{
    if(root==NULL)
        return false;
    v.push_back(root->data);
    if(root->data==val)
        return true;


    bool left=getPath(root->left,val,v);
    bool right=getPath(root->right,val,v);
    if(!right && !left)
    {
        v.pop_back();
        return false;
    }
    return left || right;
}

//1 2 3 4 5 0 6 7 0 0 8 0 0 0 0 0 0
int main()
{
    /*BTNode *root=new BTNode(1);
    BTNode *n1=new BTNode(2);
    BTNode *n2=new BTNode(3);

    root->left=n1;
    root->right=n2;
    */

    //BTNode *root=takeInputRecursively();

    BTNode *root=takeInputLevelWise();

    //printRecursively(root);
    printLevelWise(root);
    //printLevels(root);

    /*
    cout<<endl<<"In-order Traversal:"<<endl;
    inorder(root);
    cout<<endl<<"Pre-order Traversal:"<<endl;
    preorder(root);
    cout<<endl<<"Post-order Traversal:"<<endl;
    postorder(root);
    */
    cout<<endl<<"Number of Nodes="<<countNodes(root)<<endl;
    cout<<"Height of the tree="<<depth(root)<<endl;
    /*
    cout<<"Enter Number to be searched: ";
    int node;
    cin>>node;
    cout<<"Node is present: "<<search(root,node)<<endl;
    cout<<"Minimum node value of the tree is: "<<minValue(root)<<endl;
    int mnvalue=INT_MAX;
    minValueRefrence(root,mnvalue);
    cout<<"Minimum node value of the tree other way is:"<<mnvalue<<endl;
    cout<<"Maximum node value of the tree is: "<<maxValue(root)<<endl;
    */
    cout<<"Number of Leaf Nodes= "<<countLeafNodes(root)<<endl;
    vector<int> v;
    if(getPath(root,8,v))
    {
        for(int i=0;i<v.size();i++)
            cout<<"->"<<v[i];
    }
    delete root;
}
