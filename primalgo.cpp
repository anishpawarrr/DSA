#include <bits/stdc++.h>
using namespace std;

class graphmat{
    public:
    vector<vector<int>> mat;
    graphmat(int s){
        vector <int> temp(s,0);
        // vector<vector<int>> mat[s][s];
        for(int i=0;i<s;i++){
            mat.push_back(temp);
        }
    }
    void connect(int i, int j, int w){
        mat[i][j]=mat[j][i]=w;
    }
    void disconnect(int i, int j){
        mat[i][j]=mat[j][i]=0;
    }
    // int getnode(){
    //     int i=0, j=0;
    //     int s = mat[0].size();
    //     for(i=0;i<s;i++){
    //         for(j=0;j<s;j++){
    //             if(mat[i][j] != 0){
    //                 return i;
    //             }
    //         }
    //     }
    //     return -1;
    // }
    // vector<int> minnode(int x){
    //     int n,i ,mw=0;
    //     int r = getnode();
    //     for(int i=0;i<mat[0].size();i++){
    //         if(mat[r][i]>0){
    //             mw = mat[r][i];
    //         }
    //     }
    //     if(mw==0){
    //         return -1;
    //     }
    //     for(i=0;i<mat[0].size();i++){
    //         if(mat[x][i] != 0){
    //             if(mat[x][i]<mw){
    //                 mw = mat[x][i];
    //             }
    //         }
    //     }
    //     for(i=0;i<mat[0].size();i++){
    //         if(mw == mat[x][i])
    //         return i;
    //     }
    //     return -1;
    //     vector<int> order = mat[x];
    //     sort(order.begin(), order.end());
    //     return order;
    // }

    // int getnodeindex(int i, int w){
    //     for(int j=0;j<mat[i].size();j++){
    //         if(mat[i][j] == w){
    //             return j;
    //         }
    //     }
    //     return -1;
    // }
    vector<vector<int>> spantr(){
        vector<int> temp(mat.size(), 0);
        vector<vector<int>> tr(mat.size(), temp);
        vector<bool> visited(mat.size(), false);
        int edgeno = 0;
        visited[0] = true;
        while(edgeno < mat.size() - 1){
            int min = 9999999;
            int x = 0, y = 0;
            for(int i=0;i<mat.size();i++){
                if(visited[i]){
                    for(int j=0;j<mat.size();j++){
                        if(!visited[j] && mat[i][j]){
                            if(min>mat[i][j]){
                                min  = mat[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            tr[x][y] = 1;
            tr[y][x] = 1;
            visited[y] = true;
            edgeno++;
        }
        return tr;

    }
    void display(vector<vector<int>> matr){
        for(int i=0;i<matr.size();i++){
            for(int j=0;j<matr.size();j++){
                cout<<matr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    graphmat g(5);
    g.connect(0,1,3);
    g.connect(0,2,2);
    g.connect(3,1,2);
    g.connect(3,2,3);
    g.connect(3,4,1);
    g.display(g.mat);
    cout<<endl;
    g.display(g.spantr());
    cout<<g.mat.size();
    return 0;
}