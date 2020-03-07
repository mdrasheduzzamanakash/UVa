#include <bits/stdc++.h>
using namespace std;
int r,c;
char g[100][100];
bool visit[100][100];
int cnt[26];
int temp_to_sort[26];

void dfs(int x, int y, char sample){
    if(x < 0 || y < 0 || x >= r || y >= c || visit[x][y] == true || 
    g[x][y] != sample) return;
    // base con
    visit[x][y] = true;
    dfs(x,y-1,sample);
    dfs(x,y+1,sample);
    dfs(x-1,y,sample);
    dfs(x+1,y,sample);
}

bool cmp(int x, int y){
    if(x > y)return true;
    else return false;
}

int main(){

    // testing 
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int world;
    cin >> world;
    for(int w = 1;w <= world;w++){
        memset(cnt, 0, sizeof cnt);
        memset(temp_to_sort,0,sizeof temp_to_sort);
        memset(visit, false, sizeof visit);
        cin >> r >> c;
        for(int i = 0;i < r;i++)    cin >> g[i];
        // inp fin
        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++){
                if(visit[i][j] == false){
                    dfs(i,j,g[i][j]);
                    cnt[g[i][j]-'a']++;
                    temp_to_sort[g[i][j]-'a']++;
                }
            }
        sort(temp_to_sort,temp_to_sort+26,cmp);
        printf("World #%d\n",w);
        for(int i = 0;i < 26;i++){
            if(temp_to_sort[i] != 0){
                int v = temp_to_sort[i];
                for(int j = 0;j < 26;j++){
                    if(v == cnt[j]){
                        printf("%c: %d\n",('a'+j),v);
                        cnt[j] = 0;
                    }
                }
            }
        }
    }
}