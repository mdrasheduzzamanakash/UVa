#include <bits/stdc++.h>
using namespace std;

class team{
    public:
    int team_id,total_time = 0;
    int pb_solved = 0;
    map<char,int>wrong_sub;

    team(){}
    team(int a){team_id = a;}
};
vector<team>record;


int process(string s){
    return ((s[2]-'0')*10 + (s[3]-'0') + (s[0]-'0')*60);
}


void create_team(int id,char pn,string dur,char st){
    team obj;
    obj.team_id = id;
    if(st == 'Y'){
        obj.pb_solved++;
        obj.total_time += process(dur);
        obj.wrong_sub[pn] = 0;
    }
    else if(st == 'N'){
        obj.wrong_sub[pn]++;
        if(!obj.wrong_sub[pn])
            obj.wrong_sub[pn]++;
    }

    record.push_back(obj);
}


void update_team(int id,char pn,string dur,char st){
    for(int i = 0;i < record.size();i++){
        if(record[i].team_id == id){
            if(st == 'Y'){
                record[i].pb_solved++;
                record[i].total_time += process(dur) + (record[i].wrong_sub[pn]*20);
                record[i].wrong_sub[pn] = 0;
            }
            else if(st == 'N'){
                record[i].wrong_sub[pn]++;
            }
        }
    }
}


bool comp(team a,team b){
    if(a.pb_solved < b.pb_solved)
        return true;
    else if(a.pb_solved == b.pb_solved){
        if(a.total_time < b.total_time)
            return true;
        else if(a.total_time == b.total_time){
            return a.team_id > b.team_id;
        }
    }
    else
        return false;
}

void ranking(){
    sort(record.begin(),record.end(),comp);
    reverse(record.begin(),record.end());
    cout << "RANK " << "TEAM " << "PRO/SOLVED " << "TIME\n";
    int cur = 1,gap = 0;
    for(int i = 0;i < record.size();i++){
        if(i == 0){
            if(record[i].pb_solved == 0) cout << cur << " " << record[i].team_id << endl;
            else {cout << cur << " " << record[i].team_id << " " << record[i].pb_solved << " " << record[i].total_time << endl;continue;}
        }
        if(record[i].pb_solved == record[i-1].pb_solved && record[i].total_time == record[i-1].total_time){
            if(record[i].pb_solved == 0) cout << cur << " " << record[i].team_id << endl;
            else cout << cur << " " << record[i].team_id << " " << record[i].pb_solved << " " << record[i].total_time << endl;
            gap++;
        }
        else {
            if(record[i].pb_solved == 0) cout << ++cur+gap << " " << record[i].team_id << endl;
            else cout << ++cur+gap << " " << record[i].team_id << " " << record[i].pb_solved << " " << record[i].total_time << endl;
            gap = 0;
        }
    }
}

int main(){
    int id; char pn; string dur; char st;
    set<int>uniq;
    while(cin >> id >> pn >> dur >> st && id){
        if(uniq.count(id) == 0){
            create_team(id,pn,dur,st);
            uniq.insert(id);
        }
        else{
            update_team(id,pn,dur,st);
        }
    }
    // now ranking part
    ranking();
}