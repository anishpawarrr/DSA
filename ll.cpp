#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
class ll
{
public:
    node *head = new node;
    ll(int i)
    {
        head->data = i;
        head->next = NULL;
    }
    void append(int a)
    {
        node *temp = new node;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *app = new node;
        app->data = a;
        app->next = NULL;
        temp->next = app;
    }
    void insertfront(int i)
    {
        node *temp = new node;
        temp = head;
        node *in = new node;
        in->data = i;
        in->next = temp;
        head = in;
    }
    void insertinside(int i, int n)
    {
        node *temp = new node;
        temp = head;
        bool ele = false;
        while (temp != NULL)
        {
            if (temp->data == i)
            {
                ele = true;
                break;
            }
            temp = temp->next;
        }
        if (ele)
        {
            node *insert=new node;
            insert->data = n;
            insert->next = temp->next;
            temp->next = insert;
        }
    }
    void display()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void rdisplay(node *h){
        if(h==NULL){
            cout<<endl;
        }
        else{
            cout<<h->data<<" ";
            rdisplay(h->next);
        }
    }
    void revdis(node *h){
        if(h==NULL){
            return;
        }else{
            revdis(h->next);
            cout<<h->data<<" ";
        }
    }
    void del(int i){
        node *temp,*pre = new node;
        temp=head;
        pre = head;
        bool f=false;
        bool t=false;
        if(temp->data==1){
            head = temp->next;
            return;
        }
        while(temp->data != i && temp != NULL){
            temp = temp->next;
            if(t){
                pre=pre->next;
            }else{
                t=true;
            }
            if(temp->data==i){
                f=true;
                break;
            }
        }
        pre->next=temp->next;



        
    }
};
int main()
{
    ll l(1);
    l.append(2);
    l.append(3);
    l.append(4);
    // l.display();
    // l.rdisplay(l.head);
    // l.revdis(l.head);
    l.del(1);
    l.display();


    
    return 0;
}
