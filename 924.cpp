#include <bits/stdc++.h>
using namespace std;

vector<int> g[2500];
bool visit[2500];
int fBoom,bestBoom;
int dis[2500];
int num[2500];


void bfs(int s){
    queue<int> q;
    q.push(s);
    visit[s] = true;
    dis[s] = 0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i = 0;i < g[top].size();i++){
            if(visit[g[top][i]] == false){
                visit[g[top][i]] = true;
                q.push(g[top][i]);
                dis[g[top][i]] = dis[top] + 1;
                num[dis[g[top][i]]]++;
            }
        }
    }
}

bool cmp(int x,int y){
    if(x > y) return true;
    else      return false;
}


int main() {
    int emp;
    cin >> emp;
    for(int i = 0;i < emp;i++){
        int a,b;
        cin >> a;
        while(a--){
            cin >> b;
            g[i].push_back(b);
        }
    }
    int T;
    cin >> T;
    while(T--){
        fBoom = 0;
        bestBoom = 0;
        memset(visit,false,sizeof visit);
        memset(dis,0,sizeof dis);
        memset(num,0,sizeof num);
        int c;
        cin >> c;
        bfs(c);
        for(int i = 0;i < 2500;i++){
            if(num[i] > bestBoom) 
                bestBoom = num[i],fBoom = i;
        }
        if(fBoom)
            cout << bestBoom << " " << fBoom << endl;
        else 
            cout << 0 << endl;
    }
}