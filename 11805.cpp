#include <bits/stdc++.h>
using namespace std;




int main() {
    int T;
    cin >> T;
    for(int kse = 1;kse <= T;kse++){
        int n,k,p;
        cin >> n >> k >> p;
        int ans = ((p%n)+k) % n;
        if(ans == 0) ans = n;
        printf("Case %d: %d\n",kse,ans);
    }
}