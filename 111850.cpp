#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        int a[n+1];
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        bool f = true;
        for(int i = 0;i < n-1;i++){
            if(abs(a[i]-a[i+1]) > 200){
                f = false;
                break;
            }
        }
        if(!f)
            cout << "IMPOSSIBLE\n";
        else
            cout << "POSSIBLE\n";
    }
    return 0;
}