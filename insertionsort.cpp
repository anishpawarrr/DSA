#include <bits/stdc++.h>
using namespace std;

int main(){

    long a[]={3478,65643,345676,5645332,56785432435};
    long x,i,j,n = sizeof(a)/sizeof(a[0]);
    for(i=1;i<n;i++){
        x = a[i];
        j = i-1;
        while(j>=0 && a[j]>x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;



    return 0;
}
