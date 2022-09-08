#include <iostream>
using namespace std;

struct seit
    {
        int roll;
        string name;
        float sgpa;
        bool check = true;

    };


int main(){
    

    int n;
    cout<<"How many students' info do you want to enter ? ";
    cin>>n;

    seit s1[n],x;
    //Taking input
    for(int i=0; i<n;i++){
        cout<<"Entry number "<<i+1<<"."<<endl;
        cout<<"Enter your roll no. -> ";
        cin>>s1[i].roll;
        cout<<"Enter your CGPA -> ";
        cin>>s1[i].sgpa;
        cout<<"Enter your name -> ";
        cin>>s1[i].name;
    }

    //Displaying inputted data
    cout<<endl;
    cout<<"Before sorting -> "<<endl;

    for(int i=0;i<n;i++){
        cout<<"Roll no. -> "<<s1[i].roll<<" Name -> "<<s1[i].name<<" GPA -> "<<s1[i].sgpa<<endl;
    }

    //Sorting w.r.t. rollno.
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(s1[j].roll>s1[j+1].roll){
                x = s1[j];
                s1[j] = s1[j+1];
                s1[j+1] = x;
            }
        }
    }

    //Displaying sorted data
    cout<<endl;
    cout<<"Sorted list with respect to  roll no. is -> "<<endl;

    for(int i=0;i<n;i++){
        cout<<"Roll no. -> "<<s1[i].roll<<" Name -> "<<s1[i].name<<" GPA -> "<<s1[i].sgpa<<endl;
    }

    cout<<endl;
    cout<<"list of students when arranged with same CGPA "<<endl;

    for(int i=0;i<n;i++){
        if(s1[i].check){
            cout<<"Roll no. -> "<<s1[i].roll<<" Name -> "<<s1[i].name<<" GPA -> "<<s1[i].sgpa<<endl;
        }
        for(int j=i+1;j<n;j++){
            
            if(s1[i].sgpa==s1[j].sgpa){
                s1[j].check = false;
                cout<<"Roll no. -> "<<s1[j].roll<<" Name -> "<<s1[j].name<<" GPA -> "<<s1[j].sgpa<<endl;
            }
        }
    }

    //Sorting w.r.t. name
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(s1[j].name > s1[j+1].name){
                x = s1[j];
                s1[j]=s1[j+1];
                s1[j+1]=x;
            }
        }
    }

    cout<<endl;
    cout<<"Sorted list with respect to name is -> "<<endl;

    for(int i=0;i<n;i++){
        cout<<"Roll no. -> "<<s1[i].roll<<" Name -> "<<s1[i].name<<" GPA -> "<<s1[i].sgpa<<endl;
    }

    //Finding element using binary search 
    int l=0,h=n-1,m,po;
    string key;
    cout<<endl;
    cout<<"Enter a name to check wheather it is in the list or not : ";
    cin>>key;
    bool f = false;
    
    while(l<=h){
        m = (l+h)/2;
        if(s1[m].name == key){
            po = m;
            f = true;
            break;
        }else if(s1[m].name > key){
            h = m-1;
        }else if(s1[m].name < key){
            l = m+1;
        }
    }
    cout<<endl;
    if(f){
        cout<<key<<" is present in list and it's roll no. is -> "<<s1[po].roll<<endl;
    }else{
        cout<<key<<" is not present in list "<<endl;
    }

    return 0;

}
