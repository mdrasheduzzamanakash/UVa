#include <bits/stdc++.h>
using namespace std;

const int val = 2000010;

bool bs[val];
int primes[val];
int ind = 0;
inline void sieve(){
	memset(bs,true,sizeof(bs));
	for(int i = 4;i < val;i += 2)bs[i] = false;
	for(int i = 3;i * i <= val;i += 2)
		for(int j = i * i;j < val;j += i+i) bs[j] = false;
	primes[ind++] = 2;
	for(int i = 3;i < val;i += 2)if(bs[i] == true)primes[ind++] = i;
}

int arrayOfPhi[val];
int final[val];

int phi(int n){
	ind = 0;
	int ans = n;
	while(primes[ind]*primes[ind] <= n){
		if(n % primes[ind] == 0) ans -= ans / primes[ind];
		while(n % primes[ind] == 0) n /= primes[ind];
		ind++;
	}
	if(n != 1)ans -= ans / n;
	return ans;
}

int depth(int n){
	int fre = 0,temp = n;
	while(n != 1){
		// if(temp == 13)cout << " fre " << fre << " " << "n " << endl;
		fre++;
		n = arrayOfPhi[n];
	}
	return fre;
}



void precal(){
	for(int i = 1;i < val;i++){
		 arrayOfPhi[i] = phi(i);
	}
	final[1] = 1;
	for(int i = 2;i < val;i++)
		final[i] = depth(i);
}



int main(){
	sieve();
	precal();
	// for(int i = 0;i < 19;i++)cout << primes[i] << endl;
	// for(int i = 1;i < 15;i++)
	// cout << i << " " << final[i] << endl;
	int test;
	cin >> test;
	int m,n;
	while(test--){
		long long res = 0;
		cin >> m >> n;
		for(int i = m;i <= n;i++) res += final[i];
		cout << res << endl;
	}

}