#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N;  cin >> N;
    int p;  cin >> p;

    bitset<4000>bit;
    bit.set();

    for(int i = 0;i < p; i++){
        int t;  cin >> t;
        for(int b = t; b <= N; b += t){
            bit[b] = 0;
        }
    }

    int cnt = 0;
    for(int i = 1;i <= N;i++){
        if(bit[i] == 0 && i%7 != 0 && i%7 != 6){
            cnt++;
        } 
    }

    cout << cnt << endl;
}


int main(){
    int test;   cin >> test;
    for(int i = 0; i < test; i++){
        solve();
    }
}