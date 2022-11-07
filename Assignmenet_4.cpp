#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *left = NULL, *right = NULL, *up = NULL;
    char data;
};

bool isope(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

node *createtree(string s)
{
    stack<node *> nd;
    int l = s.length();
    node *root = new node;
    for (int i = 0; i < l; i++)
    {
        if (!(isope(s[i])))
        {
            node *tr = new node;
            tr->data = s[i];
            nd.push(tr);
        }
        else
        {
            node *tr = new node;
            tr->data = s[i];
            tr->left = nd.top();
            nd.pop();
            tr->right = nd.top();
            nd.pop();
            root = tr;
            nd.push(root);
        }
    }
    return nd.top();
}

void recpre(node *root){
    if(!root){
        return;
    }else{
        cout<<root->data<<" ";
    }
    node *temp = new node;
    temp = root;
    recpre(temp->left);
    recpre(temp->right);
}

void recpos(node *root){
    if(!root){
        return;
    }
    recpos(root->left);
    recpos(root->right);
    cout<<root->data<<" ";

}

void recinor(node* root){
    recinor(root->left);
    cout<<root->data<<" ";
    recinor(root->right);
}

int main()
{
    string exp;
    exp = "abc*+";
    if ((isope(exp[0])))
    {
        reverse(exp.begin(), exp.end());
    }
    node *temp = new node;
    node *rut = new node;
    rut = createtree(exp);
    
    return 0;
}
