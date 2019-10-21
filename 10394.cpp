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
#define        maxN                30000000  //required limit may goes on
//prime cheaking function
bool is_prime(long long n){
	for(int i = 2,sq = sqrt(n);i <= sq;i++){
		if(n%i == 0)
			return false;
	}
	return true;
}

bitset<maxN>bs;
vector<int>primes;

void Sieve() {
    bs.set();
    bs[0] = bs[1] = false;
    for (int i=4; i<maxN; i+=2) bs[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (bs[i]) for (int j=i*i; j<maxN; j+=i+i)
            bs[j] = false;
    primes.push_back(2);
    for (int i=3; i<maxN; i+=2)
        if (bs[i]) primes.push_back(i);
}


//main code........................
int main(){
    Sieve();
    vpl v;
    ll N;
    for(ll i = 1;i < primes.size();i++){
        if(primes[i]-primes[i-1]==2){
            pair<ll,ll>p;
            p.first = primes[i-1];p.second = primes[i];
            v.push_back(p);
        }
    }

    while(scanf("%lld",&N) != EOF){
        printf("(%lld, %lld)\n",v[N-1].first,v[N-1].second);
    }
    return 0;
}
