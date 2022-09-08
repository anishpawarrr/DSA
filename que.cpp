#include <bits/stdc++.h>
using namespace std;

bool emptyy=false;
int totele;

bool Isempty(){
    if(totele == 0){
        return true;
    }else{
        return false;
    }
        


}
void Deque(int arr[],int length){
    if(totele!=0){
        for(int i=0;i<length-1;i++){
            arr[i] = arr[i+1];
        }
        arr[length-1] = NULL;
        emptyy = true;
        totele--;
    }else{
        cout<<"Que is empty"<<endl;
    }
}

void Enque(int arr[], int inserted, int lenght){
    if(emptyy){
        int i=lenght-1;
        while(arr[i] == 0 && i>=0){
            i--;
        }
        i++;
        arr[i]=inserted;
        if(i==lenght-1){
            emptyy = false;
        }
        totele++;

    }
}

int main(){
    int que[]={1,2,3,4,5,6}; 
    int del,ins,n=sizeof(que)/sizeof(que[0]);
    totele=n;
    for(int i=0;i<n;i++){
        cout<<que[i]<<" ";
    }
    cout<<endl;
    

    Deque(que, n);
    Deque(que, n);

    for(int i=0;i<n;i++){
        cout<<que[i]<<" ";
    }
    cout<<endl;

    Enque(que, 314, n);
    Enque(que, 271, n);
    Enque(que, 1010, n);

    for(int i=0;i<n;i++){
        cout<<que[i]<<" ";
    }
    cout<<endl;

    Deque(que, n);
    Deque(que, n);
    Deque(que, n);
    Deque(que, n);
    Deque(que, n);
    Deque(que, n);

    for(int i=0;i<n;i++){
        cout<<que[i]<<" ";
    }
    cout<<endl;

    Deque(que, n);

    for(int i=0;i<n;i++){
        cout<<que[i]<<" ";
    }
    cout<<endl;

    return 0;
}
