#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
};
class sll{
    
    public:
    node *top = new node;
    sll(int s){
        top->data=s;
        top->next=NULL;
    }
    void push(int p){
        node *temp = new node;
        temp->data=p;
        temp->next=top;
        top=temp;
    }
    void pop(){
        node *temp = new node;
        if(top!=NULL){
            top = top->next;
        }else{
            cout<<"EMpty\n";
        }
    }
    void display(){
        node *temp=new node;
        temp = top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void decide(sll s,int c){
        int w=0;
        while(true){
            cout<<"Enter 1 to create stack \n";
            cout<<"Enter 2 to push element to stack \n";
            cout<<"Enter 3 to pop element from stack \n";
            cout<<"Enter 4 to display stack \n";
            cout<<"Enter 5 to exit stack \n";
            cin>>c;
            if(c<=0 || c>5){
                cout<<"Enter valid number -> ";
                cin>>c;
            }
            if(c==5){
                break;
            }



        }

    }


};
int main(){
    sll s(1);
    s.display();
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    s.display();

    return 0;
}
