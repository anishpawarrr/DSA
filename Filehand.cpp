#include <bits/stdc++.h>
using namespace std;

class data{
    public:
    string name;
    int rollno;
    string div;
    string add;
    data inp(string nm, int rn, string dv, string ad){
        data t;
        t.add = ad;
        t.name = nm;
        t.rollno = rn;
        t.div = dv;
        return t;
    }
    data usetinp(){
        string nm,ad,dv;
        int rn;
        cout<<"Enter name\n";
        cin>>nm;
        cout<<"Enter roll no.\n";
        cin>>rn;
        cin.ignore(1);
        cout<<"Enter div\n";
        getline(cin, dv);
        cin.ignore(1);
        cout<<"Enter address\n";
        getline(cin, ad);
        return inp(nm,rn,dv,ad);
    }
};

void append(data t){
    fstream db;
    db.open("Database.csv", ios::app);
    db<<t.rollno<<", "<<t.name<<", "<<t.div<<", "<<t.add<<"\n";
    db.close();
}

void display(){
    fstream db;
    db.open("Database.csv", ios::in);
    string s;
    while(getline(db, s)){
        cout<<s<<endl;
    }
    db.close();
}

int search(int rn,vector<data> db){
    bool b = false;
    for(int i=0;i<db.size();i++){
        if(rn == db[i].rollno){
            b = true;
            return i+1;
        }
    }
    return -1;
}

int main()
{
    vector<data> db;
    data d;
    d = d.usetinp();
    db.push_back(d);
    append(d);
    cout<<"hdhthe"<<search(10170,db);
    int dd = 1, u;
    while(dd){
        cout<<"Enter\n1 to display student database\n";
        cout<<"2 to insert new entry\n";
        cout<<"3 to update value\n";
        cout<<"4 to delete a record\n";
        cout<<"5 to search a record\n";
        cin>>u;
        while(u<1 || u>5){
            cout<<"Enter valid number";
            cin>>u;
        }
        if(u==1){
            display();
        }else if(u==2){
            data d;
            d = d.usetinp();
            append(d);
            db.push_back(d);
        }else if(u==3){
            //pass
        }else if(u==4){
            //pass
        }else{
            //pass
        }
        cout<<"Eneter 1 to continue or enter 0 to end\n";
        cin>>dd;
    }

    

    return 0;
}
