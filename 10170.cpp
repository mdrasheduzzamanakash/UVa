#include <bits/stdc++.h>
using namespace std;

int main() {
//     freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    long long int s,d,n;
    while(scanf("%lld%lld",&s,&d) == 2){
       int n = ceil((-1+sqrt(1-4*(s-(s*s)-2*d)))/2);
       cout << n << endl;
    }
}