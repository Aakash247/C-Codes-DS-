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

class Pair
{
public:

    BTNode *head;
    BTNode *tail;
};

class BST
{
    BTNode *root;


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


bool searchData(BTNode *node,int data)
{
    if(node==NULL)
        return false;
    if(node->data==data)
        return true;
    else if(node->data>data)
        return searchData(node->left,data);
    else
        return searchData(node->right,data);
}


BTNode* insertNode(BTNode *node,int data)
{
    if(node==NULL)
    {
        BTNode *node=new BTNode(data);
        return node;
    }

    if(data>node->data)
    {
        node->right=insertNode(node->right,data);
    }
    if(data<node->data)
    {
        node->left=insertNode(node->left,data);
    }
    return node;


}


BTNode* deleteData(BTNode *root,int data)
{
    if(root==NULL)
        return NULL;

    if(data>root->data)
    {
        root->right=deleteData(root->right,data);
    }
    else if(data<root->data)
    {
        root->left=deleteData(root->left,data);
    }
    else
    {
        if(root->right==NULL && root->left==NULL)
        {
            delete root;
            return NULL;
        }

        else if(root->right==NULL)
        {
            BTNode *temp=root->left;
            root->left=NULL;
            delete root;
            return temp;
        }

        else if(root->left==NULL)
        {
            BTNode *temp=root->right;
            root->right=NULL;
            delete root;
            return temp;
        }

        else
        {
            BTNode *minNode=root->right;
            while(minNode->left!=NULL)
            {
                minNode=minNode->left;
            }
            root->data=minNode->data;
            root->right=deleteData(root->right,minNode->data);
        }
    }
}

Pair convertLL(BTNode *root)
{
    if(root->right==NULL and root->left==NULL)
    {
        Pair p;
        p.head=root;
        p.tail=root;
        return p;
    }

    else if(root->left!=NULL && root->right==NULL)
    {
        Pair p=convertLL(root->left);
        p.tail->right=root;
        p.tail=root;
        return p;
    }

    else if(root->left==NULL && root->right!=NULL)
    {
        Pair p=convertLL(root->right);
        root->right=p.head;
        p.head=root;
        return p;
    }

    else
    {
        Pair l=convertLL(root->left);
        Pair r=convertLL(root->right);
        l.tail->right=root;
        root->right=r.head;
        Pair ans;
        ans.head=l.head;
        ans.tail=r.tail;
        return ans;
    }
}




public:
    BST()
    {
        root=NULL;
    }

    ~BST()
    {
        delete root;
    }

    void printBST()
    {
        printLevelWise(root);
    }

    bool hasData(int data)
    {
        return searchData(root,data);
    }

    void insertBST(int data)
    {
        root=insertNode(root,data);
    }

    void deleteBST(int data)
    {
        root=deleteData(root,data);
    }

    BTNode* convertLL()
    {
        Pair p=convertLL(root);
        return p.head;
    }

};

int main()
{
    BST b;
    b.insertBST(10);
    b.insertBST(5);
    b.insertBST(4);
    b.insertBST(3);
    b.insertBST(20);
    b.insertBST(7);
    b.insertBST(9);
    b.insertBST(15);
    b.insertBST(25);
    b.insertBST(24);
    b.insertBST(23);
    b.insertBST(26);


    b.printBST();
    /*
    cout<<"After Deleting"<<endl;
    b.deleteBST(3);
    b.printBST();
    */

    BTNode *temp=b.convertLL();
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->right;
    }

    return 0;
}
