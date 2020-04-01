#include <bits/stdc++.h>
using namespace std;

int main(){

    int kse = 0;
    int n;
    while(cin >> n){
        map<string ,int> no;
        map<int, string> name;
        vector<int> g[1000];
        set<string> ss;
        int idx = 0;
        for(int i = 0;i < n;i++){
            string u,v;
            cin >> u >> v;
            ss.insert(u);
            ss.insert(v);
            if(no.find(u) == no.end()){
                no[u] = idx;
                name[idx] = u;
                idx++;
            }
            if(no.find(v) == no.end()){
                no[v] = idx;
                name[idx] = v;
                idx++;
            }
            g[no[u]].push_back(no[v]);
            g[no[v]].push_back(no[u]);
        }
        string u,v;
        cin >> u >> v;
        int s = no[u];
        int dest = no[v];

        queue<int> q;
        bool visit[idx+1] = {false};
        vector<int> d(idx+1),p(idx+1);

        q.push(s);
        visit[s] = true;
        p[s] = -1;


        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(int i = 0;i < g[t].size();i++){
                if(!visit[g[t][i]]){
                    visit[g[t][i]] = true;
                    q.push(g[t][i]);
                    d[g[t][i]] = d[t] + 1;
                    p[g[t][i]] = t;
                }
            }
        }
        if(kse)cout << "\n\n";
        if(!visit[dest] || ss.find(u) == ss.end() || ss.find(v) == ss.end()){
            cout << "No route";
        }else{
            vector<int> path;
            for(int i = dest;i != -1;i = p[i])
                path.push_back(i);
            reverse(path.begin(),path.end());
            cout << name[path[0]] << " " << name[path[1]];
            for(int i = 1;i < path.size()-1;i++){
                cout << "\n";
                cout << name[path[i]] << " " << name[path[i+1]];
            }
        }
        kse++;
    }
    cout << endl;
}