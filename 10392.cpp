/*
        BISMILLAHIR RAHMANIR RAHIM
        MD Rasheduzzaman (CUET)
		mdrasheduzzamanakash@gmail.com
*/
#include <bits/stdc++.h>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define E_FOR(i, a, b) for (long long i=a; i<=b; i++)
#define FOR(i, n) for (long long i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define ll64 unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define all_u(ar,val) ar.begin(), ar.end(),val
#define get_ind_lo(ar,val) long long(lower_bound(all_u(ar,val)) - ar.begin());
#define get_ind_up(ar,val) long long(upper_bound(all_u(ar,val)) - ar.begin());
#define pb push_back
#define pf push_front
#define INF 500000000
#define maxN 100000001
using namespace std;

//sieve

bool bs[maxN];
vector<long long>primes;
void sieve(){
    Fill(bs,true);
    bs[0] = bs[1] = false;
    for(long long i = 4;i < maxN; i += 2) bs[i] = false;
    for(long long i = 3;i*i < maxN;i += 2){
        if(bs[i])
            for(long long j = i*i;j < maxN;j += i+i)  bs[j] = false;
    }
    primes.pb(2);
    for(long long i = 3;i < maxN;i += 2) if(bs[i])    primes.pb(i);
}



int main(){
    sieve();
    long long n;
    while(cin >> n && n != -1){
        int sz = primes.size();
        for(int i = 0;i < sz;i++){
            if(n % primes[i] == 0){
                while(n % primes[i] == 0){
                    printf("    %lld\n",primes[i]);
                    n /= primes[i];
                }
            }
        }
        if(n != 1)printf("    %lld\n",n);
        printf("\n");
    }
}