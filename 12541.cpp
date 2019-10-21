#include <bits/stdc++.h>
using namespace std;



struct per{
    string name;
    int y,m,d;
};


bool comp(per a,per b){
    if(a.y < b.y)return false;
    if(a.y > b.y)return true;
    if(a.y == b.y){
        if(a.m < b.m)return false;
        if(a.m > b.m)return true;
        if(a.m == b.m){
            return a.d > b.d;
        }
    }
}

int main(){
    int t;  cin >> t;
    vector<per>rec(t);
    for(int i = 0;i < t;i++){
        cin >> rec[i].name >> rec[i].d >> rec[i].m >> rec[i].y;
    }
    sort(rec.begin(),rec.end(),comp);
    // for(int i = 0;i < rec.size();i++){
    //     cout << rec[i].name << " " << rec[i].d << " " << rec[i].m << " " << rec[i].y << endl;
    // }
    cout << rec[0].name << endl;//<< " " << rec[0].d << " " << rec[0].m << " " << rec[0].y << endl;
    cout << rec[t-1].name << endl;//<< " " << rec[t-1].d << " " << rec[t-1].m << " " << rec[t-1].y << endl;
    
}