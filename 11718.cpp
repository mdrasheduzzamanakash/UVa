#include <bits/stdc++.h>
using namespace std;

long long int modpow(long long int n,long long int k,int mod){
    if(k==0)return 1;
    
    if(k%2==0){
        long long int result=modpow(n,k/2,mod)%mod;
        return result*result % mod;
    }
    else {
        long long int result=modpow(n,k-1,mod)%mod;
        return result*n%mod;
    }
}


int main() {
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    long long int T,kse=1;
    cin >> T;
    while(T--){
        long long int n,k,mod;
        cin >> n >> k >> mod;
        long long int sum = 0;
        for(long long int i = 0;i < n;i++){
            long long int temp;   cin >> temp; sum+=temp; sum %= mod;
        }
        long long int ans = sum*modpow(n,k-1,mod)*k;
        printf("Case %lld: %lld\n",kse++,ans%mod);
    }
}