#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iterator>

#define ll long long
using namespace std;

/* this is sieve algorithm to generate primes in "vector<int>primes" */
bitset<10000100>bs;
vector<ll>primes;
void sieve(ll up){
    bs.set();   bs[0] = bs[1] = 0;
    primes.push_back(1);

    for(ll i = 2;i <= up;++i){
        if(bs[i]){
            for(long long j = i*i; j <= up+1;j += i){
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

int main(){
    ll n,m;
    while(scanf("%lld %lld",&n,&m) == 2){
        primes.clear();
        sieve(n);
        printf("%lld %lld:",n,m);

        if((2*m >= primes.size() || (2*m - 1) >= primes.size())){
            for(auto i : primes){
                cout << " " << i;
            }
            cout << "\n\n";
            continue;
        }
        else if(primes.size()%2 != 0){
            ll mid = primes.size()/2;
            ll s_mid = (2*m - 1)/2;
            vector<ll> :: iterator lo,up;
            lo = primes.begin()+(mid-s_mid);
            up = lo + (2*m-1);

            while(lo != up){
                cout << " " << *lo;
                lo++;
            }
        }
        else if(primes.size()%2 == 0){
            ll mid = primes.size()/2;
            ll s_mid = (2*m)/2;
            vector<ll> :: iterator lo,up;
            lo = primes.begin()+(mid-s_mid);
            up = lo + (2*m);

            while(lo != up){
                cout << " " << *lo;
                lo++;
            }
        }
        cout << "\n\n";

    }
}