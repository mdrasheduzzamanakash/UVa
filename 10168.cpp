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
#define maxN 10000010
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
    ll sz = primes.size();
    ll n;
    long long ans[4];
    while(cin >> n){
        bool flag = false;
        if(n <= 7){
            cout << "Impossible." << endl;
            continue;
        }
        else if(n % 2 == 0){
            ans[0] = ans[1] = 2;
            n = n-4;
        }
        else if(n % 2 != 0){
            ans[0] = 2;
            ans[1] = 3;
            n = n-5;
        }
        

        //now applying goldbacks algorithms for n
        for(int i = 0;i < sz;i++){
            int x = primes[i];
            int y = n - primes[i];

            if(bs[y]){
                ans[2] = x;
                ans[3] = y;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "Impossible." << endl;
        }
        else {
            cout << ans[0];
            for(int i = 1;i < 4;i++){
                cout << " " << ans[i];
            }
            cout << endl;
        }
    }
}