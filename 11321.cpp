#include <bits/stdc++.h>
using namespace std;

struct sortt
{
    int val;
    int mod;
};


bool comp(sortt a,sortt b){
    if(a.mod < b.mod)
        return true;
    if(a.mod > b.mod)
        return false;
    if(abs(a.val)%2 != abs(b.val)%2)
        return (abs(a.val)%2 > abs(b.val)%2);
    if(a.val % 2 == 0)
        return (a.val < b.val);
    return (a.val > b.val);
}


int main(){
    int n,m;
    while(cin >> n >> m){
        if(n==0 && m==0){cout << 0 << " " << 0 << endl;return 0;}
        vector<sortt>v(10050);
        for(int i = 0;i < n;i++){
            cin >> v[i].val;
            v[i].mod = v[i].val%m;
        }

        sort(v.begin(),v.begin()+n,comp);
        cout << n << " " << m << endl;
        for(int i = 0;i < n;i++){
            cout << v[i].val << endl;
        }
    }
    return 0;
}