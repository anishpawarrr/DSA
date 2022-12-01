#include <bits/stdc++.h>
using namespace std;

class graphmat{
    vector<vector<int>> mat;
    graphmat(int s){
        vector <int> temp(s,0);
        // vector<vector<int>> mat[s][s];
        for(int i=0;i<s;i++){
            mat.push_back(temp);
        }
    }
    public:
    void connect(int i, int j, int w){
        mat[i][j]=mat[j][i]=w;
    }
    void disconnect(int i, int j){
        mat[i][j]=mat[j][i]=0;
    }
    int getnode(){
        int i=0, j=0;
        int s = mat[0].size();
        for(i=0;i<s;i++){
            for(j=0;j<s;j++){
                if(mat[i][j] != 0){
                    return i;
                }
            }
        }
        return -1;
    }
    vector<int> minnode(int x){
        // int n,i ,mw=0;
        // int r = getnode();
        // for(int i=0;i<mat[0].size();i++){
        //     if(mat[r][i]>0){
        //         mw = mat[r][i];
        //     }
        // }
        // if(mw==0){
        //     return -1;
        // }
        // for(i=0;i<mat[0].size();i++){
        //     if(mat[x][i] != 0){
        //         if(mat[x][i]<mw){
        //             mw = mat[x][i];
        //         }
        //     }
        // }
        // for(i=0;i<mat[0].size();i++){
        //     if(mw == mat[x][i])
        //     return i;
        // }
        // return -1;
        vector<int> order = mat[x];
        sort(order.begin(), order.end());
        return order;
    }

    int getnodeindex(int i, int w){
        for(int j=0;j<mat[i].size();j++){
            if(mat[i][j] == w){
                return j;
            }
        }
        return -1;
    }
    vector<vector<int>> spantr(){
        int next;
        int size = mat.size();
        vector<int> temp(size, 0);
        vector<vector<int>> tr(size, temp);
        vector<int> visited;
        int r = getnode();
        visited.push_back(r);
        int j=0;
        while(j<mat.size()){
            
        }
        if(count(visited.begin(), visited.end(), next) < 0){

        }


    }

};

int main(){

    return 0;
}