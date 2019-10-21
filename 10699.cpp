#include <bits/stdc++.h>
using namespace std;

bool bs[1000000];
int primes[1000000];
int ind = 0;
void sieve(){
	memset(bs,true,sizeof(bs));
	for(int i = 4;i < 1000000;i += 2)bs[i] = false;
	for(int i = 3;i * i < 1000000;i += 2){
		for(int j = i*i;j < 1000000;j += i + i){
			bs[j] = false;
		}
	}
	primes[ind++] = 2;
	for(int i = 3;i < 1000000;i += 2)if(bs[i] == true)primes[ind++] = i;
}

int main(){
	sieve();
	int n,temp,ans;
	while(cin >> n && n){
		temp = n;
		ans = 0;
		if(bs[n] == true){
			cout << n << " : " << 1 << endl;
			continue;
		}
		else {
			ind = 0;
			while(primes[ind]*primes[ind] <= n){
				if(n % primes[ind] == 0){
					ans++;
					while(n % primes[ind] == 0)n /= primes[ind];
				}
				ind++;
			}
			if(n != 1)ans++;
			cout << temp <<	" : " << ans << endl;
		}
	}
	return 0;
}