#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r){
    int i=l-1;
    int pivot = arr[r];
    for(int j=l;j<r;j++){
        if(arr[j] > pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(pivot,arr[i+1]);

    return i+1;

}
void quicksort(int arr[], int l, int r){
    if(l<r){
        int m = partition(arr, l, r);
        quicksort(arr, l, m-1);
        quicksort(arr, m+1, r);
    }
}


int main()
{
    int a[] = {435634,2654,236,246};
    int i,j,n=sizeof(a)/4;
    
    quicksort(a, 0, n);

    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
