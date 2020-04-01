#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    while(cin >> n && n){
        int k = sqrt(n);
        if(k*k==n){
            if(n%2==0){
                cout << k << " " << 1 << endl; continue;
            }else{
                cout << 1 << " " << k << endl; continue;
            }
        }
        if(k%2!=0){
            int t=n-(k*k);
            if(t <= k+1){
                cout << t << " " << k+1 << endl; continue;
            }else{
                int sl = t-k-1;
                cout << k+1 << " " << k+1-sl << endl; continue;
            }
        }else{
            int t=n-(k*k);
            if(t <= k+1){
                cout << k+1 << " " << t << endl; continue;
            }else{
                int sl = t-k-1;
                cout << k+1-sl << " " << k+1 << endl; continue;
            }
        }
    }
    return 0;
}