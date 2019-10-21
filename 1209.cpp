#include <bits/stdc++.h>
using namespace std;

int fun(string s){
    int d = 2e9;
    for(int i = 0;i < s.size()-1;i++){
        d = min(d,abs(s[i]-s[i+1]));
    }
    return d;
}

struct sss
{
    int dif; string s;
};

bool comp(sss a,sss b){
    return a.s < b.s;
}


int main(){
    string ss;
    while(cin >> ss){
        deque<sss>v;
        sss t;t.dif = fun(ss);t.s = ss;v.push_back(t);
        //now prev permutations
        string ts = ss;
        int mx = -1;
        for(int i = 1;i < 11;i++){
            if(prev_permutation(ts.begin(),ts.end())){
                t.dif = fun(ts);
                t.s = ts;
                v.push_front(t);
                mx = max(mx,t.dif);
            }
        }
        ts = ss;
        for(int i = 1;i < 11;i++){
            if(next_permutation(ts.begin(),ts.end())){
                t.dif = fun(ts);
                t.s = ts;
                v.push_back(t);
                mx = max(mx,t.dif);
            }
        }

        sort(v.begin(),v.end(),comp);

        for(int i = 0;i < v.size();i++){
            if(v[i].dif == mx){
                cout << v[i].s << v[i].dif << endl;
                break;
            }
            // cout << v[i].s << v[i].dif << endl;
        }
    }
    return 0;
}