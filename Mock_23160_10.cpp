#include <bits/stdc++.h>
using namespace std;

class airline{
    public:
    string name;
    int ticketno;
    vector<int> ticlis;
    //taking input
    void input(vector<airline> a){
        cout<<"Enter name of passenger -> ";
        cin>>name;
        cout<<"Enter ticket number of passenger -> ";
        cin>>ticketno;
        //validation
        while(ticketno<1 || count(ticlis.begin(),ticlis.end(),ticketno) >0 ){
            cout<<"Enter valid ticket number -> ";
            cin>>ticketno;
        }
        ticlis.push_back(ticketno);
    }
    //tabular template
    void display(airline a){
        cout<<a.name<<"                         "<<a.ticketno<<"\n";
        
    }
    //print list function
    void displist(vector<airline> a){
        cout<<"Name of passenger        Ticket number of passenger \n";
        int i,n=a.size();
        for(i=0;i<n;i++){
            display(a[i]);
        }
    }
    //sorting uing bubble sort
    void bubble(vector<airline> &a){
        int i,j,n=a.size();
        for(i=0;i<n-1;i++){
            for(j=0;j<n-1-i;j++){
                if(a[j].ticketno>a[j+1].ticketno){
                    swap(a[j],a[j+1]);
                }
            }
        }
    }
    //searching usng binary search
    int bisearch(vector<airline> a,int t){
        bubble(a);
        int l,h,m,f=0;
        l=0;
        h=a.size();
        while(l<=h){
            m=(l+h)/2;
            if(a[m].ticketno==t){
                cout<<a[m].ticketno<<" is the ticket of passenger -> "<<a[m].name<<"\n";
                f=1;
                return a[m].ticketno;
                break;
            }
            if(a[m].ticketno<t){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        if(f==0){
            cout<<"Entered ticket number has not been sold yet\n";
            return -1;
        }
        return -1;
    } 
};
int main(){
    vector<airline> a;
    airline temp;
    int q,w,e,d=1;
    cout<<"-----------------------------------\n";
    cout<<"Welcome to zap airlines\n";
    //user interaction
    while(d==1){
        cout<<"Enter\n1 to add pasenger\n2 to display list of passengers\n3 to display list of passengers with respect to ticket number\n4 to search whether desired seat is available of not\n";
        cin>>q;
        while(q<=0 || q>4){
            cout<<"Enter valid number\n";
            cin>>q;
        }
        if(q==1){
            cout<<"------input------\n";
            temp.input(a);
            a.push_back(temp);
            cout<<"------------------------\n";
        }else if(q==2){
            cout<<endl;
            cout<<"---Displaying list of passengers---\n\n";
            temp.displist(a);
            cout<<endl;
        }else if(q==3){
            cout<<"---Sorting using bibble sort---\n";
            temp.bubble(a);
            temp.displist(a);
            cout<<"------------------------------\n";
        }else{
            cout<<"----searching using binary search----\n";
            cout<<"Enter desired ticket number ->";
            cin>>e;
            while(e<=0 || e>99999){
                cout<<"Enter valid seat number -> ";
                cin>>e;
            }
            w=temp.bisearch(a,e);
        }
        cout<<"Enter 1 to continue or enter any number to exit\n";
        cin>>d;
        cout<<"-----------------\n\n";

    }
    return 0;
}