#include <bits/stdc++.h>
using namespace std;
char str[30];
bool used[30];
bool nodes[30];
bool graph[30][30];
bool say;


void TOP(int idx, int n){
    if(idx == n){
        say = true;
        //print
        cout << str[0];
        for(int i = 1;i < n;i++)
            cout << " " << str[i];
        cout << endl;
        return;
    }
    for(int i = 0;i < 30;i++){
        if(nodes[i] == true && used[i] == false){
            for(int j = 0;j < 30;j++){
                if(graph[i][j] == true && used[j] == true)
                    return;
            }
            used[i] = true;
            str[idx] = i + 'A';
            TOP(idx+1,n);
            used[i] = false;
        }
    }
}


int main(){

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    stringstream ss;
    int T;
    cin >> T;
    getchar();
    bool f = false;
    while(T--){

        memset(used,false,sizeof used);
        memset(graph, false, sizeof graph);
        memset(nodes,false, sizeof nodes);

        if(f)cout << endl;
        f = true;
        say = false;

        string line;
        getchar();
        getline(cin,line);
        ss.clear();
        ss << line;
        char c;
        while(ss >> c){
            nodes[c-'A'] = true;
        }
        cin >> ws;
        getline(cin, line);
        // cout << line << endl;
        ss.clear();
        ss << line;
        line.clear();
        while(ss >> line){
            graph[line[0]-'A'][line[2]-'A'] = true;
        }// inp fin


        int n = 0;
        for(int i = 0;i < 30;i++)
            if(nodes[i] == true) n++;
        
        TOP(0,n);
        if(say == false){
            cout << "NO" << endl;
        }
    }
    return 0;
}
