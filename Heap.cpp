#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> h, int d){
    if(h.empty()){
        h.push_back(d);
        return;
    }
    int i=0;
    while(d>h[i] && i<h.size()){
        i++;
    }
    h.insert(h.begin() + i, d);
}
vector<int> makeheap(vector<int> h){
    vector<int> heap;
    int i=0;
    while(i<h.size()){
        
    }
}

int main(){
    vector<int> heap;
    heap.push_back(1);
    heap.push_back(3);
    heap.insert(heap.begin()+2, 2);
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }


    return 0;
}