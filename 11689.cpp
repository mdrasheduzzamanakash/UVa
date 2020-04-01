#include <bits/stdc++.h>
using namespace std;




int main() {
    int T;
    cin >> T;
    while(T--){
        int n,b,r;
        cin >> n >> b >> r;
        int cnt = 0,tot = n + b;
        while(tot / r){
            cnt += tot / r;
            int rem = tot % r;
            tot = tot / r + rem;
        }
        cout << cnt << endl;
    }
}
