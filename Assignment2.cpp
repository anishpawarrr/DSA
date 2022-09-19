#include <bits/stdc++.h>
#define size 6
using namespace std;

class que{
    public:
        // void createarr(int n){
        //     int arr[n];
        // }
        int totele(){
        return size-count(arr,arr+size,0);
        }
        int arr[size]={1,2,3,4,0,0};
        int r=size-count(arr,arr+size,0)-1;
        int f=0;
        //int r=r-1;
        void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        }
        void enque(int i){
            if(r<size-1){
                r++;
                arr[r]=i;
            }
        }
        void deque(){
            if(r>=0){
                arr[r]=0;
                r--;
            }
        }
        void destory(){
            for(int i=0;i<size;i++){
                arr[i]=0;
            }
        }
};

int main(){
    que q;
    q.display();
    q.enque(5);
    q.display();
    q.enque(6);
    q.display();
    q.enque(12345);
    q.display();
    q.deque();
    q.deque();
    q.deque();
    q.deque();
    q.deque();
    q.deque();
    q.display();    
    
    return 0;
}
