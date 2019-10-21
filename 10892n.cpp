#include <bits/stdc++.h>
using namespace std;


long long lcm(long long a,long long b){
    return((a*b) / __gcd(a,b));
}



int main(){
    long long n;
    while(cin >> n && n){

        vector<long long>fac;
        for(long long i = 1;i <= sqrt(n);i++){
            if(n%i == 0){
                fac.push_back(i);
                long long k = n/i;
                if(k != i)fac.push_back(k);
            }
        }

        long long cnt = 0;
        long long sz = fac.size();

        for(long long i = 0;i < sz;i++){
            for(long long j = i;j < sz;j++){
                if(lcm(fac[i],fac[j]) == n)cnt++;
            }
        }


        printf("%lld %lld\n",n,cnt);
    }
}