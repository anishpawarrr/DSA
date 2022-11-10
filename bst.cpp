#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;
    node(){
        data = -1;
        left = right = NULL;
    }
    node(int d){
        data = d;
        left = right = NULL;
    }
};

class tree{
    public:
    node *root = NULL;
    int showdepth(){
        node *temp = new node;
        temp = root;
        int i=1;
        while(temp){
            temp = temp->left;
            i++;
        }
        int j=1;
        temp = root;
        while(temp){
            temp = temp->right;
            j++;
        }
        return max(i,j);
    }
    void insert(int i, node *root){
        if(!root){
            node *temp = new node(i);
            this->root = temp;
            return;
        }
        if(i>root->data){
            if(root->right == NULL){
                node *t = new node(i);
                root->right = t;
                return;
            }
            insert(i,root->right);
        }
        if(i<root->data){
            if(root->left == NULL){
                node *t = new node(i);
                root->left = t;
                return;
            }

            insert(i,root->left);
        }
    }
    bool search(int i, node*rut, node *add = 0X0){
        if(!rut){
            return false;
        }
        if(i == rut->data){
            add = rut;
            return true;
        }
        if(i>rut->data){
            return search(i, rut->right,add);
        }else{
            return search(i, rut->left, add);
        }
    }
    void del(int i){
        node *add = new node;
        if(search(i, root, add)){
            if(root->right){
                add->data = (add->right)->data;
                while((add->right)->right){
                    (add->right)->data = ((add->right)->right)->data;

                }
            }
        }
    }
    void preorder(node *rut){
        if(!rut){
            return;
        }
        cout<<rut->data<<" ";
        preorder(rut->left);
        preorder(rut->right);
    }
    void inorder(node* root){
    if(!root){return;}
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
    void postorder(node *rut){
        if(!rut){
            return;
        }
        postorder(rut->left);
        postorder(rut->right);
        cout<<rut->data<<" ";
    }
    void tp(){
        node *temp = new node;
        temp = root;
    }
    
};

int main(){
    tree t;
    t.insert(5,t.root);
    t.insert(4,t.root);
    t.insert(6, t.root);
    t.insert(2,t.root);
    t.insert(3,t.root);
    t.insert(5,t.root);
    t.inorder(t.root);
    // cout<<t.search(3,t.root);
    // t.tp();
    // t.inorder(t.root);
    

    return 0;
}
