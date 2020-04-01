#include <bits/stdc++.h>
using namespace std;
vector<string> words;
map<string, int> visit;


void bfs(string src,string dest){
    queue<string> q;
    q.push(src);
    visit[src] = 0;

    while(!q.empty() && !visit.count(dest)){
        string top = q.front();
        q.pop();
        for(int i = 0;i < words.size();i++){
            string cur = words[i];
            if(!visit.count(cur) && cur.length() == top.length()){
                int dm = 0;
                for(int j = 0;j < top.size();j++)
                    if(top[j] != cur[j]) dm++;
                if(dm == 1){
                    visit[cur] = visit[top] + 1;
                    q.push(cur);
                }
            }
        }
    }
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    while(T--){
        words.clear();
        string s;
        while(cin >> s && s != "*")
            words.push_back(s);
        cin.ignore();
        string line;
        while(getline(cin, line) && line != ""){
            stringstream ss(line);
            string src,dest;
            ss >> src >> dest;
            visit.clear();
            bfs(src,dest);
            cout << src << " " << dest << " " << visit[dest] << endl;
        }
        if(T)cout << endl;
    }
}