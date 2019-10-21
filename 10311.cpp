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
#define maxN 100000010
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
    sieve();
    int n;
    while(cin >> n){
        if(n < 5){
            printf("%d is not the sum of two primes!\n",n);
        }
        else if(n % 2 != 0 && bs[n-2]){
            printf("%d is the sum of 2 and %d.\n",n,n-2);
        }
        else if(n % 2 == 0){
            int ind = n/2 - 1;
            bool flag = true;
            for(int i = ind; i >= 2; i--){
                if(bs[i] && bs[n-i]){
                    flag = false;
                    printf("%d is the sum of %d and %d.\n",n,i,n-i);
                    break;
                }
            }
            if(flag){
                printf("%d is not the sum of two primes!\n",n);
            }
        }
        else{
            printf("%d is not the sum of two primes!\n",n);
        }
    }
}