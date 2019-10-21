#include <bits/stdc++.h>
using namespace std;


int main(){
    int test;   cin >> test;
    while(test--){
        int n;  cin >> n;
        int v[n];
        int ans = -1e9, mx,t;
        for(int i = 0;i < n;i++){
            if(i == 0){
                cin >> mx;continue;
            }
            cin >> t;
            ans = ans < (mx-t)?mx-t:ans;
            mx = mx > t?mx : t;
        }
        cout << ans <<  endl;
    }
    return 0;
}