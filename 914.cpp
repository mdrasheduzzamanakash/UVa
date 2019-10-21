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
    int cse;
    cin >> cse;
    while(cse--){
        int l,u;    cin >> l >> u;
        int arr[1000];
        Fill(arr,0);

        // int lo = get_ind_lo(primes,l);
        // int up = get_ind_up(primes,u);

        int lo = int(lower_bound(primes.begin(),primes.end(),l) - primes.begin());
        int up = int(upper_bound(primes.begin(),primes.end(),u) - primes.begin());

        int MAX = 0,idx;
        for(int i = lo+1;i < up;i++){
            int temp = primes[i] - primes[i-1];
            if(++arr[temp] > MAX){
                MAX = arr[temp];
                idx = temp;
            }
        }

        int cnt = 0;
        for(int i = 0;i < 1000;i++){
            if(arr[i] == MAX)cnt++;
            if(cnt > 1)break;
        }

        if(cnt > 1 || MAX == 0)puts("No jumping champion");
        else printf("The jumping champion is %d\n", idx);
    }
    return 0;
}