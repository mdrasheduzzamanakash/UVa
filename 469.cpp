#include <bits/stdc++.h>
using namespace std;
char graph[150][150];
bool visited[150][150];
int ans,ln;


void dfs(int i, int j){
    // base condition
    if(i < 0 || i >= ln || j < 0 || j >= ln || graph[i][j] != 'W' || visited[i][j] == true) return;
    visited[i][j] = true;
    ans++;
    for(int p = -1;p <= 1;p++){
        for(int q = -1;q <= 1;q++){
            dfs(i+p,j+q);
        }
    }
}


int main(){

    int T;
    char line[110];
    cin >> T;
    cin >> ws;

    while(T--){
        memset(graph,'0',sizeof graph);
        ln = 0;
        while(gets(line) && line[0] != '\0'){
            if(line[0] == 'W' || line[0] == 'L'){
                sscanf(line, "%s", graph[ln]),ln++;
            }
            else {
                memset(visited,false,sizeof visited);
                int i,j;
                sscanf(line, "%d %d", &i, &j);
                ans = 0;
                dfs(i-1,j-1);
                cout << ans << endl;
            }
        }
        if(T)   cout << endl;
    }
    return 0;
}
