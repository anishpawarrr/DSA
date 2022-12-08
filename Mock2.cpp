#include<bits/stdc++.h>
using namespace std;

//creating node class to store it in BST
class node{
	public:
	int data;
	node *left, *right;
	node(int i){
		data = i;
		left = right = NULL;	
	}
};

//creating class BST for it's implementation and operations
class BST{
	public:
	node *root = NULL;
	//insert function using recursion
	void insert(int i, node* rut){
		if(rut == NULL){
			node *temp = new node(i);
			root = temp;
			return;
		}
		if(i > rut->data){
			if(rut->right == NULL){
				node *temp = new node(i);
				rut->right = temp;
				return;
			}
			insert(i, rut->right);
		}
		if(i < rut->data){
			if(rut->left == NULL){
				node *temp = new node(i);
				rut->left = temp;
				return;
			}
			insert(i, rut->left);
		}
		return;
	}
	//traversing function(inorder)
	void inorder(node *rut){
		if(rut == NULL){
			return;
		}
		inorder(rut->left);
		cout<<rut->data<<" ";
		inorder(rut->right);
	}
	// search function
	bool search(int i, node *root){
		if(root == NULL){
			return false;
		}
		if(i == root->data){
			return true; // found
		}
		if(i>root->data){
			return search(i, root->right); //moving to right subtree
		}else{
			return search(i, root->left); //moving to left subtree
		}
	}

	void displayparentwithchild(node *rut){
		if(rut == NULL){
			return;
		}
		cout<<"Parent - "<<rut->data<<"\nChild - "; //displaying parent if node exists
		//displaying child nodes
		if(rut->left){
			cout<<(rut->left)->data<<" "; 
		}
		if(rut->right){
			cout<<(rut->right)->data<<" ";
		}
		cout<<endl;
		
		displayparentwithchild(rut->left); //traversing in left subtree
		displayparentwithchild(rut->right); //traversing in right subtree
	}

	int depth(node *rut){
		if(rut==NULL){
			return 0;
		}
		else{
			int ld = depth(rut->left);
			int rd = depth(rut->right);
			if(ld > rd){
				return ld+1;
			}else{
				return rd+1;
			}
		}
		
	}

	void cleartree(){
		this->root = NULL;
	}

	node *mirror(node *rut){
		if(rut == NULL){
			return NULL;
		}
		node *temp = new node(rut->data);
		temp->left = mirror(rut->right);
		temp->right = mirror(rut->left);
		//return temp;
	
	}
};



int main(){
	BST b;
	int d=1,c;
	while(d){
		cout<<"Enter\n";
		cout<<"1 to create new BST\n";
		cout<<"2 to Display tree\n";
		cout<<"3 to Insert new element in BST\n";
		cout<<"4 to Search an element in BST\n";
		cout<<"5 to Display all parent nodes with their child nodes\n";
		cout<<"6 to display Depth of BST\n";
		cout<<"7 to mirror the tree\n";
		cin>>c;
		while(c<1 || c>7){
			cout<<"Enter valid number\n";
			cin>>c;
		}	
		if(c==1){
			b.cleartree();
			cout<<"Successfull created new tree\n";
		}else if(c==3){
			int i;
			cout<<"Enter element to insert in BST\n";
			cin>>i;
			b.insert(i, b.root);
		}else if(c==2){
			cout<<"Inorder traversal of BST is\n";
			b.inorder(b.root);
			cout<<endl;
		}else if(c==4){
			bool s;
			int i;
			cout<<"Enter element which you want to find\n";
			cin>>i;
			s = b.search(i, b.root);
			if(s){
				cout<<"Element is present in BST\n";
			}else{
				cout<<"Element not found\n";
			}
		}else if(c==5){
			cout<<"Parents and their respective child are\n";
			b.displayparentwithchild(b.root);
		}else if(c==6){
			int d = b.depth(b.root);
			cout<<"Depth of BST is "<<d<<endl;
		}else{
			node *mir = b.mirror(b.root);
			cout<<"Mirror of tree is\n";
			b.inorder(mir);
			cout<<endl;
			
		}
		cout<<"Enter 1 to continue or enter 0 to exit\n";
		cin>>d;
	}
	return 0;
}
