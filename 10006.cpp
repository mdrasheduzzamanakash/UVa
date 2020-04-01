#include <bits/stdc++.h>
using namespace std;

bool primes[100000]={false};
void sieve(){
    primes[0]=primes[1]=true;
    int i,j;
    for(int i=2;i<100000;i++){
        if(primes[i]==false){
            for(int j=2;i*j<100000;j++)
                primes[i*j]=true;
        }
    }
}

long long Mod(long long x,long long y,long long mod){
    int res=1;x%=mod;if(x==0)return 0;
    while(y>0){
        if(y&1)res=(res*x)%mod;y>>=1;
        x=(x*x)%mod;
    }
    return res;
}


bool check(int n){
    for(int i=2;i<n;i++){
        if(Mod(i,n,n)!=i) return false;
    }
    return true;
}


int main() {
    sieve();
    int n;
    while(cin >> n && n){
        if(primes[n]==true&&check(n)){
            printf("The number %d is a Carmichael number.\n", n);
        }else{
            printf("%d is normal.\n", n);
        }
    }
}