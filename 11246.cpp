#include <bits/stdc++.h>
using namespace std;




int main() {
    long long int n,k,i,sum,T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        i=-1,sum=0;
        while(n){
            i*=-1;
            sum += i*n;
            n/=k;
        }
        cout << sum << endl;
    }
}