#include <bits/stdc++.h>
using namespace std;

struct team
{
    int wrong[15] = {0};
    bool pb_st[11] ={false};
    int id = -1,solved = 0,penalty = 0;
};

bool comp(team a,team b){
    if(a.solved > b.solved)
        return true;
    else if(a.solved == b.solved){
        if(a.penalty < b.penalty)
            return true;
        else if(a.penalty == b.penalty){
            return a.id < b.id;
        }else
            return false;
    }else return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        team player[110];
        vector<team>v;

        int id,pb,ti;   char st;
        string line;
        cin >> ws;
        while(getline(cin,line) && line.length()){

            stringstream geek(line);
            geek >> id >> pb >> ti >> st;
            if(st == 'C'){
                if(player[id].pb_st[pb])continue;
                player[id].id = id;
                player[id].solved++;
                player[id].penalty += (ti + player[id].wrong[pb]*20);
                player[id].pb_st[pb] = true;
            }
            else if(st == 'I'){
                player[id].id = id;
                player[id].wrong[pb]++;
            }
            else if(st == 'R' || st == 'U' || st == 'E'){
                player[id].id = id;
            }
        }
        for(int i = 0;i < 110;i++){
            if(player[i].id != -1){
                v.push_back(player[i]);
            }
        }

        sort(v.begin(),v.end(),comp);

        for(int i = 0;i < v.size();i++){
            cout << v[i].id << " " << v[i].solved << " " << v[i].penalty << endl;
        }
        if(t)
        cout << endl;
    }
}
