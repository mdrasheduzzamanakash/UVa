#include <bits/stdc++.h>
using namespace std;




int t,n,p[100010],q[100010];

int main(){
    ios::sync_with_stdio(false);
    cin >> t;

    for(int tc = 1;tc <= t;tc++){
        cin >> n;
        for(int i = 0;i < n;i++)
            cin >> p[i];
        for(int i = 0;i < n;i++)
            cin >> q[i];
        

        long long sum = 0,mn = INT32_MAX,st_point = 0;

        for(int i = 0;i < n;i++){
            sum += p[i] - q[i];
            mn = min(mn,sum);
        }

        while(mn < 0 && st_point < n){
            mn = mn - (p[st_point] - q[st_point]);
            st_point++;
        }

        cout << "Case " << tc << ": ";
        if(st_point == n || sum < 0)
            cout << "Not possible\n";
        else
            cout << "Possible from station " <<  st_point + 1 << "\n";
    }
}