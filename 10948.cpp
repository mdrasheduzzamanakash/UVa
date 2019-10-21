#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <bitset>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define E_FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOR(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define ll64 unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define all_u(ar,val) ar.begin(), ar.end(),val
#define get_ind_lo(ar,val) int(lower_bound(all_u(ar,val)) - ar.begin());
#define get_ind_up(ar,val) int(upper_bound(all_u(ar,val)) - ar.begin());
#define pb push_back
#define pf push_front
#define INF 500000000
#define maxN 1000001
using namespace std;

//sieve

bool bs[maxN];
vector<int>primes;
void sieve(){
    Fill(bs,true);
    bs[0] = bs[1] = false;
    for(int i = 4;i < maxN; i += 2) bs[i] = false;
    for(int i = 3;i*i < maxN;i += 2){
        if(bs[i])
            for(int j = i*i;j < maxN;j += i+i)  bs[j] = false;
    }
    primes.pb(2);
    for(int i = 3;i < maxN;i += 2) if(bs[i])    primes.pb(i);
}



int main(){
    int n,flag = 0;
    sieve();
    int sz = primes.size();
    while(cin >> n && n){
        flag = 0;
        for(int i = 0;i < sz && primes[i] <= n;i++){
            int a = n - primes[i];
            if(bs[a]){
                printf("%d:\n",n);
                printf("%d+%d\n",primes[i],a);
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("%d:\n",n);
            cout << "NO WAY!\n";
        }

    }
    return 0;
}