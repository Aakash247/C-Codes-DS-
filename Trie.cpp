#include<bits/stdc++.h>
using namespace std;

class trie
{
public:
    bool terminal;
    trie *child[26];

    trie()
    {
        terminal=false;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
};


void add(string word,trie *node)
{
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        if(node->child[word[i]-'A']==NULL)
        {
            node->child[word[i]-'A']=new trie();
        }
        node=node->child[word[i]-'A'];
    }
    node->terminal=true;
}

bool search(string word,trie *node)
{
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        if(node->child[word[i]-'A']!=NULL)
        {
            node=node->child[word[i]-'A'];
        }
        else
        {
            return false;
        }
    }
    if(node->terminal==true)
        return true;
    else
        return false;
}

int main()
{
    vector<string> dict;
    dict.push_back("ARE");
    dict.push_back("AS");
    dict.push_back("DO");
    dict.push_back("DOT");
    dict.push_back("NEW");
    dict.push_back("NEWS");
    dict.push_back("NO");
    dict.push_back("NOT");

    trie *dir=new trie();

    for(int i=0;i<dict.size();i++)
    {
        add(dict[i],dir);
    }

    cout<<search("DOT",dir)<<endl;

    return 0;
}
