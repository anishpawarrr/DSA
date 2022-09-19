#include <bits/stdc++.h>
#define n 7
using namespace std;

class Stack
{
    public:
    int top=0,bottom=0;
    int arr[n];
    public: 
    
    Stack()
    {
        destroy();
    }
    
    void destroy()
    {
        for(int i=0;i<n;i++)
        {

            arr[i]=0;
        }
        top=0;
    }
    
    void push(int i)
    {
        if(top<n){
            arr[top]=i;
            top++;
        }
    }
    
    void pop()
    {
        if(top>=0)
        {
            top--;
            arr[top]=0;
            
        } 
    }
    
    void display()
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    int getbottom()
    {
        return arr[0];
    }
    
    int getsize()
    {
        return top;
    }
    bool empty()
    {
        bool a;
        top==0?a=true:a=false;
        return a;
    }
    
    bool full()
    {
        bool a;
        arr[n-1]!=0?a=true:a=false;
        return a;
    }
    
};
int main(){
    Stack s;
    for(int j=1;j<=n;j++){
        s.push(j);
    }
    cout<<s.full();
    return 0;
}
