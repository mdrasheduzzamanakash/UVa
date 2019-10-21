#include<algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <queue>

#define debug cout << "#" << endl;
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



struct ii{
    int f,l;
};

int main(){
    sieve();
    int l,u;
    while(cin >> l >> u && (l || u)){
        if(l > u)swap(l,u);
        int lo = int(lower_bound(all(primes),l) - primes.begin());
        int up = int(upper_bound(all(primes),u) - primes.begin());


        int cnt = 0,last,i,temp,dis;
        // for(int i = lo;i < up;i++){
        //     cout << primes[i] <<" ";
        // }
        vector<ii> st;
        dis = primes[lo+1]-primes[lo];
        last = lo;
        cnt++;
        for(i = lo+1; i < up-1;i++){
            temp = primes[i+1] - primes[i];
            if(temp == dis){
                cnt++;
                // cout << cnt << endl;
            }
            else if(temp != dis && cnt < 2){    
                last = i;
                dis = temp;
                cnt = 1;
                // debug;
                // cout << dis << endl;
            }
            else if(temp != dis && cnt >= 2){
                cnt = 1;
                ii a;
                a.f = last;
                a.l = i;
                st.push_back(a);
                last = i;
                dis = temp;
            }
        }
        // cout << primes[i] << endl;
        if(cnt >= 2){
            ii a;
            a.f = last;
            a.l = i;
            st.push_back(a);
        }

        for(int stt = 0;stt < st.size();stt++){
            cout << primes[st[stt].f];
            for(int l = st[stt].f+1;l <= st[stt].l;l++){
                cout << " " << primes[l];
            }
            cout << "\n";
        }
    }
}