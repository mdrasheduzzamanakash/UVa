#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    while(scanf("%lld",&n)==1){
        n=n/2+1;
        n=n*n;
        n=1+2*(n-1);
        cout << 3*n-6 << endl;
    }
}