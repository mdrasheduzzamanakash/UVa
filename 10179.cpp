/*
        BISMIlong longAHIR RAHMANIR RAHIM
        MD Rasheduzzaman (CUET)
        mdrasheduzzamanakash@gmail.com
*/
#include <bits/stdc++.h>
#define PI 3.1415926535897932385
#define INF 500000000
#define maxN 1000001
using namespace std;


//arrays of my tools
long long primes[maxN];
long long factors[maxN];


//sieve
bool bs[maxN];
int size_primes = 0;
void sieve(){
    memset(bs,true,sizeof(bs));
    bs[0] = bs[1] = false;
    for(long long i = 4;i < maxN; i += 2) bs[i] = false;
    for(long long i = 3;i*i < maxN;i += 2){
        if(bs[i])
            for(long long j = i*i;j < maxN;j += i+i)  bs[j] = false;
    }
    primes[size_primes++] = 2;
    for(long long i = 3;i < maxN;i += 2) if(bs[i])    primes[size_primes++] = i;
}

long long phi(long long n){
	long long ans = n,ind = 0;
	while(primes[ind]*primes[ind] <= n){
		if(n % primes[ind] == 0)
			ans -= ans / primes[ind];
		while(n % primes[ind] == 0)
			n /= primes[ind];
		ind++;
	}
	if(n != 1)
		ans -= ans / n;
	return ans;
}


int main(){
	sieve();
	long long n;

	while(cin >> n && n){
		cout << phi(n) << endl;
	}
}
