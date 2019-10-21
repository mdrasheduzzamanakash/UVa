//colin and ryan


#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;  cin >> t;
    for(int i = 1;i <= t;i++){
        long long c,r;
        cin >> c >> r;
        int eaten = c - r;

        set<long long >val;
        cout << "Case #" << i << ":";
        if(eaten == 0){
            cout << " 0\n";
            continue;
        }
        for(int p = 1;p*p <= eaten;p++){
            if(eaten%p == 0){
                val.insert(eaten/p);
                val.insert(p);
            }
        }
        for(set<long long>::iterator it=val.begin();it != val.end();it++){
            if(*it > r)cout << " " << *it;
        }
        cout << endl;
    }
}