/*
        BISMILLAHIR RAHMANIR RAHIM
        MD Rasheduzzaman (CUET)
		mdrasheduzzamanakash@gmail.com
*/
#include <bits/stdc++.h>
#define PI 3.1415926535897932385
#define ll64 unsigned long long
#define ll long long
#define INF 500000000
#define maxN 1000001
using namespace std;


//arrays of my tools
ll primes[maxN];
ll factors[maxN];


//sieve
bool bs[maxN];
int size_primes;
void sieve(){
    memset(bs,true,sizeof(bs));
    bs[0] = bs[1] = false;
    for(ll i = 4;i < maxN; i += 2) bs[i] = false;
    for(ll i = 3;i*i < maxN;i += 2){
        if(bs[i])
            for(ll j = i*i;j < maxN;j += i+i)  bs[j] = false;
    }
    primes[size_primes++] = 2;
    for(ll i = 3;i < maxN;i += 2) if(bs[i])    primes[size_primes++] = i;
}


ll size_fac = 0;
void primeFactors(ll n){
	ll ind = 0;
	ll temp = primes[ind++];
	while(temp*temp <= n){
		while(n % temp == 0){
			n /= temp;
			factors[size_fac++] = temp;
		}
		temp = primes[ind++];
	}
	if(n != 1){
		factors[size_fac++] = temp;
	}
}


ll numDiffPF(ll n){
	ll ind = 0, temp = primes[ind],ans = 0;
	while(temp*temp <= n){
		if(n % temp == 0) ans++;
		while(n % temp == 0) n /= temp;
		temp = primes[++ind];
	}
	if(n != 1)ans++;
	return ans;
}


ll numDiv(ll n){
	ll ind = 0,temp = primes[ind],ans = 1;
	while(temp*temp <= n){
		ll p = 0;
		while(n % temp == 0){
			n /= temp;
			p++;
		}
		ans *= (p + 1);
		temp = primes[++ind];
	}
	if(n != 1) ans *= 2;
	return ans;
}


int main()
{
	sieve();
	ll test;
	cin >> test;
	while(test--){
		bool f1 = false;
		ll l,h;
		cin >> l >> h;
		if(l > h)swap(l,h);
		for(ll i = l;i <= h;i++){
			if(!f1 && bs[numDiv(i)] == true){
				cout << i;
				f1 = true;
			}
			else if(bs[numDiv(i)] == true) cout << " " << i;
		}
		if(!f1)cout << "-1" << endl;
		else cout << endl;
	}
	
}