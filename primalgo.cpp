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
    vector<vector<int>> spantr(){
        int size = mat.size();
        vector<int> temp(size, 0);
        vector<vector<int>> tr(size, temp);
        vector<int> visited;
        int r = getnode();
        
    }

};

int main(){

    return 0;
}