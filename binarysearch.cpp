#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int a[]={45,34,65,124,545};
    int h,l,m,i,j,x,n = sizeof(a)/4;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                x = a[j];
                a[j] = a[j+1];
                a[j+1] = x;
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    int f = 124;
    cout<<endl;
    l = 0;
    h = n-1;
    while(l<h){
        m = (l+h)/2;
        if(f==a[m]){
            cout<<"Search successful "<<m;
            break;
        }
        else if(a[m]>f){
            h = m-1;
            cout<<"f";
        }else if(a[m]<f){
            l = m + 1;
            cout<<"f";
        }
    }
    https://colab.research.google.com/drive/1KCWOf7pBvfZN3TCIBqSXVacY3xCOngW8

    return 0;
}
