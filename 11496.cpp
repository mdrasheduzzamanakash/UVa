#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a[100000];

    
    while(cin >> n && n){
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        bool u,d; 
        u = d = false;
        if(a[0] > a[n-1])   u = true;
        else                d = true;

        a[n] = a[0];
        for(int i = 1;i <= n; i++){
            if(a[i-1] > a[i] && u){
                ans++;
                u = false;
                d = true;
            }
            else if(a[i-1] < a[i] && d){
                ans++;
                d = false;
                u = true;
            }
        }
        cout << ans << endl;
    }
    return 0;
}