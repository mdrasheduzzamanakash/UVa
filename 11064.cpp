#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPrime[100000];
ll primes[100000];
int ind = 0;
void sieve(){
	memset(isPrime,true,sizeof(isPrime));
	for(ll i = 4;i < 100000;i += 2) isPrime[i] = false;
	for(ll i = 3;i*i < 100000;i += 2){
		for(ll j = i*i;j < 100000;j += i+i){
			isPrime[j] = false;
		}
	}
	primes[ind++] = 2;
	for(int i = 3;i < 100000;i++) if(isPrime[i] == true) primes[ind++] = i;
}


ll phi(ll n){
	ll ans = n;
	ll ind = 0;
	while(primes[ind]*primes[ind] <= n){
		if(n % primes[ind] == 0)
			ans -= ans / primes[ind];

		while(n % primes[ind] == 0) n /= primes[ind];
		ind++;
	}
	if(n != 1)ans -= ans / n;
	return ans;
}


ll numDiv(ll n){
	ll ind = 0;
	ll ans = 1;
	while(primes[ind]*primes[ind] <= n){
		ll power = 0;
		while(n % primes[ind] == 0){
			n /= primes[ind];
			power++;
		}
		ans *= (power + 1);
		ind++;
	}
	if(n != 1)ans *= 2;
	return ans;
}

int main(){
	sieve();
	ll n;
	// for(int i = 0;i < 10;i++)cout << primes[i] << endl;
	while(cin >> n){
		cout << n - phi(n) - numDiv(n) + 1<< endl;
	}
}