#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--){
        long long int sum = 0,n;
        cin >> n;
        n = abs(n);
        for(int i = 1;;i++){
            sum += i;
            if(sum >= n && (sum - n) % 2 == 0){
                cout << i << endl;
                break;
            }
        }
        if(T) cout << endl;
    }
}