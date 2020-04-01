#include <bits/stdc++.h>
using namespace std;




int main() {
    //          freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int T;
    cin >> T;
    for(int kse = 1;kse <= T;kse++){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        int ans = a[n/2];
        printf("Case %d: %d\n",kse,ans);
    }
}