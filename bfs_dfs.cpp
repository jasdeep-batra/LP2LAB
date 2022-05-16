#include<bits/stdc++.h>
using namespace std;
//BFS DFS
class node
{
    public:
    int val;
    node* left;
    node* right;
    node(int d){
        val = d;
        left = nullptr;
        right = nullptr;
    }
};
class BinaryTree
{
    public:
    node* root;
    BinaryTree()
    {
        root=nullptr;
    }
    node* insert(node* n)
    {
        if(root==nullptr)
        {
            root=n;
            return root;
        }
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* temp = q.front();
            q.pop();
            if(temp->left==nullptr)
            {
                temp->left = n;
                return root;
            }
            else if(temp->right==nullptr)
            {
                temp->right = n;
                return root;
            }
            if(temp->left!=nullptr)
            {
                q.push(temp->left);
            }
            if(temp->right!=nullptr)
            {
                q.push(temp->right);
            }
        }
        return root;
    }
    void dfs(node* r)
    {
        if(r==nullptr)
        {
            return;
        }
        dfs(r->left);
        cout<<r->val<<" ";
        dfs(r->right);
    }   

};
int main()
{
    BinaryTree obj;
    int n;
    while(n!=-1)
    {
        cout<<"enter the node value to insert: ";
        cin>>n;
        if(n==-1)break;
        node* nn = new node(n);
        obj.insert(nn);
    }
    obj.dfs(obj.root);
}