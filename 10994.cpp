#include <bits/stdc++.h>
using namespace std;

long long int f(long long int n){
    if(n <= 0)return 0;
    long long int ans = 0;
    while(n!=0){
        ans += (n/10)*45;
        for(int i = (n/10)*10+1;i <= n;i++){
            ans += i % 10;
        }
        n/=10;
    }
    return ans ;
}

int main() {
    long long int p,q;
    while(cin >> p >> q){
        if(p<0 || q<0){
            break;
        }
        cout << f(q)-f(p-1) << endl;
    }
}