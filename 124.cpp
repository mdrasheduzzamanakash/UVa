#include <bits/stdc++.h>
using namespace std;
bool graph[26][26];
bool nodes[26];
bool used[26];
char top[26];

void TOP(int idx, int n){
    if(idx == n){
        top[idx] = '\0';
        puts(top);
        return;
    }
    for(int i = 0;i < 26;i++){
        if(nodes[i] == true && used[i] == false){
            for(int j = 0;j < 26;j++){
                if(graph[i][j] == true && used[j] == true)
                    return;
            }
            used[i] = true;
            top[idx] = i+'a';
            TOP(idx+1,n);
            used[i] = false;
        }
    }
}

int main(){
    stringstream ss;
    string s;
    bool f = false;
    while(getline(cin, s)){
        if(f) cout << endl ;
        f = true;
        memset(used,false,sizeof used);
        memset(nodes,false,sizeof nodes);
        memset(graph,false,sizeof graph);//clean done

        ss.clear();
        ss << s;
        char c,d;
        while(ss >> c){
            nodes[c-'a'] = true;
        }
        ss.clear();
        getline(cin,s);
        ss << s;
        while(ss >> c >> d){
            graph[c-'a'][d-'a'] = true;
        }// inp fin

        int n = 0;
        for(int i = 0;i < 26;i++)
            if(nodes[i]) n++;
        TOP(0,n);
        
    }
    return 0;
}