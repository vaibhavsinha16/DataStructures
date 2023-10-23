#include <bits/stdc++.h>
using namespace std;

class Node
{ public:
    unordered_map<char, Node*> child;
    bool isEnd =false;
};


class Trie{
    private:
    Node *root;
    public:
    Trie()
    {
        root=new Node();
    }
    
    void insert(string word)
    {
        Node *node = root;
        for(int i =0;i<word.size();i++)
        {
            if(node->child.find(word[i])==node->child.end())
            {
                node->child[word[i]] = new Node();
            }
            
            //move to reference
            node = node->child[word[i]];
        }
        node->isEnd = true;
    }
    
    bool search(string word)
    {
        Node *node = root;
        for(int i =0;i<word.size();i++)
        {
            if(node->child.find(word[i])==node->child.end())
            return false;
            
            node = node->child[word[i]];
        }
        return node->isEnd;
    }
    
    bool startswith(string prefix)
    {
        Node *node = root;
        for(int i =0;i<prefix.size();i++)
        {
            if(node->child.find(prefix[i]) == node->child.end())
            return false;
            
            node = node->child[prefix[i]];
        }
        return true;
    }
};


int main() {
    
    Trie* obj = new Trie();
    obj->insert("apple");
    obj->insert("fpple");
    obj->insert("app");
    bool k = obj->search("fpple");
    bool p = obj->startswith("app");
	cout<<"ans is "<<k<<endl;
	cout<<"startswith "<<p;
	return 0;
}

