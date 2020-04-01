#include <bits/stdc++.h>
using namespace std;
map<int, int> dis;
map<int, bool> visit;
vector<int> buttons;


void bfs(int s,int d,int bs){
    for(int i = 0;i < 10000;i++)
        dis[i] = 0, visit[i] = false;
    
    queue<int> q;
    q.push(s);
    visit[s] = true;
    dis[s] = 0;

    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(int i = 0;i < bs;i++){
            int cur = t + buttons[i];
            cur = cur % 10000;
            if(visit[cur] == false){
                visit[cur] = true;
                q.push(cur);
                dis[cur] = dis[t] + 1;
            }
        }
    }
}


int main() {
    int s,d,b,temp,kse = 0;
    while(cin >> s >> d >> b && (s || d || b)){
        dis.clear();
        visit.clear();
        buttons.clear();
        while(b--){
            cin >> temp;
            buttons.push_back(temp);
        }
        bfs(s,d,buttons.size());
        if(visit[d] == false){
            printf("Case %d: Permanently Locked\n",++kse);
        }
        else 
            printf("Case %d: %d\n",++kse,dis[d]);
    }
    return 0;
}