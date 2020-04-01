#include <bits/stdc++.h>
using namespace std;




int main() {
    int n;
    while(cin >> n && n){
        int prev = log2(n);
        int cnt = n - pow(2,prev);
        if(n == pow(2,prev))
            cout << n << endl;
        else if(n == 1)
            cout << n << endl;
        else
            cout << cnt * 2 << endl;
    }
}