#include <bits/stdc++.h>
using namespace std;

int r,c;
char g[110][110];
bool v[110][110];

int px[] = {0,0,1,-1,1,-1,1,-1};
int py[] = {1,-1,0,0,1,-1,-1,1};



void dfs(int i,int j){
    if(i < 0 || i >= r || j < 0 || j >= c || v[i][j] == true || g[i][j] == '*') return;
    
    v[i][j] = true;
    for(int p = 0;p < 8;p++){
        int x = i + px[p];
        int y = j + py[p];
        dfs(x,y);
    }
}

int main(){

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    
    while(cin >> r >> c && r){
        memset(g,'*', sizeof g);
        memset(v, false, sizeof v);


        for(int i = 0;i < r;i++){
            string s;
            cin >> s;
            for(int j = 0;j < c;j++){
                g[i][j] = s[j];
            }
        }

        int cnt = 0;
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(g[i][j] == '@' && v[i][j] == false){
                    cnt++;
                    dfs(i,j);
                }
            }
        }

        cout << cnt << endl;
    }
}