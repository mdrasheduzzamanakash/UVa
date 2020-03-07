#include <bits/stdc++.h>
using namespace std;
int g[30][30];
int v[30][30];

int px[] = {0,0,1,-1,1,-1,1,-1};
int py[] = {1,-1,0,0,1,-1,-1,1};


void dfs(int i,int j){
    if(v[i][j] == 1 || g[i][j] == 0) return;
    
    v[i][j] = 1;
    for(int p = 0;p < 8;p++){
        int x = i + px[p];
        int y = j + py[p];
        dfs(x,y);
    }
}

int main(){
    int t;
    int c = 0;
    while(cin >> t){
        c++;
        memset(g,0,sizeof g);
        memset(v,0,sizeof v);
        for(int i = 0;i < t;i++){
            string s;
            cin >> s;
            for(int j = 0 ;j < t;j++){
                g[i][j] = s[j]-'0';
            }
        }


        int cnt = 0;
        for(int i = 0;i < t;i++){
            for(int j = 0;j < t;j++){
                if(g[i][j] == 1 && v[i][j] == 0){
                    cnt++;
                    // cout << "hello" << endl;
                    dfs(i,j);
                    // cout << "hello" << endl;
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n",c,cnt);
    }
}