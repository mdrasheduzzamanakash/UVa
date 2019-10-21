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
#define        maxN                100000000  //required limit may goes on
//prime cheaking function
// bool is_prime(long long n){
// 	for(int i = 2,sq = sqrt(n);i <= sq;i++){
// 		if(n%i == 0)
// 			return false;
// 	}
// 	return true;
// }

bitset<maxN>bs;
vector<ll>primes;//primes are here
void Sieve() {
    bs.set();
    bs[0] = bs[1] = false;
    for (ll i=4; i<maxN; i+=2) bs[i] = false;
    for (ll i=3; i*i<maxN; i+=2)
        if (bs[i]) for (ll j=i*i; j<maxN; j+=i+i)
            bs[j] = false;
    primes.push_back(2);
    for (ll i=3; i<maxN; i+=2)
        if (bs[i]) primes.push_back(i);
}

bool isPrime(ll n){
    ll x = sqrt(n);
    for(ll i = 0;i < primes.size(),primes[i] <= x;i++){
        if(n%primes[i] == 0){return false;}
    }
    return true;
}

//main code........................
int main(){
    Sieve();
    ll N,M;
    vector<ll>store;
    while(scanf("%lld %lld",&N,&M) == 2){
        store.clear();
        int cnt = 0;int ind = 1;
        pair<ll,ll>close,dist;
        ll mx = -1,mn = maxN+1;
        if(N <= maxN && M <= maxN){


        ll i = lower_bound(all(primes),N) - primes.begin();
        ll j = upper_bound(all(primes),M) - primes.begin();
        i++;
        for(;i < j;i++){
            ind++;
            if(mx < primes[i]-primes[i-1]){
                mx = primes[i]-primes[i-1];
                dist.first = primes[i-1];dist.second = primes[i];
            }
            if(mn > primes[i]-primes[i-1]){
                mn = primes[i]-primes[i-1];
                close.first = primes[i-1];close.second = primes[i];
            }
        }
        }
        else {
            cnt = 0;
            for(ll i = N;i <= M;i++){
                if(isPrime(i)){store.push_back(i);cnt++;}
            }
            for(ll i = 1;i < store.size();i++){
                if(mx < store[i]-store[i-1]){
                mx = store[i]-store[i-1];
                dist.first = store[i-1];dist.second = store[i];
                }
                if(mn > store[i]-store[i-1]){
                mn = store[i]-store[i-1];
                close.first = store[i-1];close.second = store[i];
                }
            }
        }
        if(ind >=2 || cnt >= 2)
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",close.first,close.second,dist.first,dist.second);
        else
        {
            printf("There are no adjacent primes.\n");
        }
        
    }
}
