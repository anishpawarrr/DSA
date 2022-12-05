#include <bits/stdc++.h>
using namespace std;


void heapify(vector<int> &heap, int i){
    int largest = i, l = 2*i+1, r = 2*i+2;
    if(l<heap.size() && heap[l] > heap[largest]){
        largest = l;
    }
    if(r<heap.size() && heap[r] > heap[largest]){
        largest = r;
    }
    if(largest != i){
        swap(heap[i], heap[largest]);
        heapify(heap, largest);
    }
}

void deleten(vector<int> &heap, int d){
    auto s = find(heap.begin(), heap.end(), d);
    if(s==heap.end())return;
    swap(heap[*s], heap[heap.size()-1]);
    heap.pop_back();
    int i = heap.size();
    for(int j=i/2-1;j>=0;j--){
        heapify(heap, j);
    }
}


void insert(vector<int> &heap, int d){
    if(heap.empty()){
        heap.push_back(d);
        return;
    }
    heap.push_back(d);
    int n = heap.size()/2 - 1;
    for(int i=n;i>=0;i--){
        heapify(heap, i);
    }
}
void display(vector<int> heap){
    for(auto i = 0; i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> heap;
    heap.push_back(1);
    heap.push_back(2);
    heap.push_back(3);
    display(heap);
    deleten(heap, 1);
    display(heap);


    return 0;
}
