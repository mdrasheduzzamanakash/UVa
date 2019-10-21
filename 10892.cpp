/*
        BISMILLAHIR RAHMANIR RAHIM
        MD Rasheduzzaman (CUET)
		mdrasheduzzamanakash@gmail.com
*/

#include<bits/stdc++.h>
using namespace std;


#define        PI                  acos(-1)
#define        debug               printf("#\n")
#define        MOD                 1
#define        ll                  long long
#define        ull                 unsigned long long
#define        dbl                 double
#define        mp                  make_pair
#define        pb                  push_back
#define        makefast            ios_base::sync_with_stdio(false);
#define        ff                  first
#define        ss                  second
#define        vl                  vector < ll,ll >
#define        vpl                 vector < pair < ll,ll > >
#define        vpi                 vector < pair < int,int> >
#define        vps                 vector < pair < string,string > >
#define        all(v)              v.begin(),v.end()
#define        maxN                100000001  //required limit may goes on

//lcm
ll lcm(ll c,ll d){
    return ((c * d) / __gcd(c,d));
}


//factorizing a number
ll factors[maxN],c;
void factor(ll n){
    ll v=0;c = 0;
    for(ll i=1;i <= sqrt(n);i++){
        if(n%i==0){
            factors[v++] = i,c++;
            ll k = n/i;
            if(k != i)factors[v++] = k,c++;
        }
    }
}
//main code........................
int main(){
	ll n;
    while(scanf("%lld",&n) && n){
        factor(n);
        ll cnt = 0;
        for(ll i = 0;i < c;i++){
            for(ll j = i;j < c;j++)
                    if(lcm(factors[i],factors[j]) == n)cnt++;
        }
        printf("%lld %lld\n",n,cnt);
    }
    return 0;
}