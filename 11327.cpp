#include <bits/stdc++.h>
using namespace std;


bool bs[200010];
long long primes[200010];
long long ind = 0;
void sieve(){
	memset(bs,true,sizeof(bs));
	for(long long i = 4;i < 200010;i += 2)bs[i] = false;
	for(long long i = 3;i*i <= 200010;i += 2){
		for(long long j = i*i;j < 200010;j += i+i){
			bs[j] = false;
		}
	}
	primes[ind++] = 2;
	for(long long i = 3;i < 200010;i += 2)if(bs[i] == true)primes[ind++] = i;
}



long long phi(long long n){
	long long ind = 0,ans = n;
	while(primes[ind]*primes[ind] <= n){
		if(n % primes[ind] == 0){
			ans -= ans / primes[ind];
			while(n % primes[ind] == 0)n /= primes[ind];
		}
		ind++;
	}
	if(n != 1) ans -= ans / n;
	return ans;
}




long long phiArray[200010];


int main(){
	sieve();
	phiArray[0] = 0;
	phiArray[1] = 1;
	phiArray[2] = 2;

	for(int i = 2;i < 200010;i++){
		phiArray[i+1] = phiArray[i] + phi(i);
	}

	// for(long long i = 0;i <= 10;i++)cout << primes[i] << " ";
	// cout << endl;
	// for(long long i = 0;i <= 10;i++)cout << phiArray[i] << " ";
	// cout << endl;

	long long n;
	while(cin >> n && n){
		if(n == 1){
			cout << "0/1" << endl;
			continue;
		}
		long long den = ((lower_bound(phiArray,phiArray+200010,n) - 1) - phiArray);
		long long k = n - phiArray[den];
		
		// cout << den <<endl;
		// cout << k << endl;


		long long i = 1;
		while(k){
			if(__gcd(i,den) == 1) k--;
			i++;
		}	
		cout << i-1 << "/" << den << endl;
	}
}