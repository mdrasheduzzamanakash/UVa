#include <bits/stdc++.h>
using namespace std;








int main() {
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);

    int T;
    cin >> T;
    while(T--){
        int n,sum = 0;
        cin >>n;
        double a[n];
        for(int i = 0;i < n;i++){
            cin >> a[i];
            sum += a[i];
        }
        double avg = sum / n;
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(a[i] > avg)cnt++;
        }
        // cout << cnt << endl;
        double ans = (double)(cnt*100) / n;
        cout << fixed << setprecision(3) << ans << "%" << endl;
    }
}