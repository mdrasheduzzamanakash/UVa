#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    while(cin >> n && n){
        int cnt = 0;
        while(n / 3){
            cnt += n / 3;
            int rem = n % 3;
            n = rem + n/3;
        }
        if(n == 2)cnt++;
        cout << cnt << endl;
    }
}