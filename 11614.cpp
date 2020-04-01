#include <bits/stdc++.h>
using namespace std;





int main(){
    long long T,n;
    cin >> T;
    while(T--){
        cin >> n;
        long long ans = (-1 + sqrt(8*n + 1)) / 2;
        cout << ans << endl;
    }
}