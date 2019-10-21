#include <bits/stdc++.h>
using namespace std;



bool bs[50010];
int primes[50010];
int ind = 0;
void sieve(){
	memset(bs,true,sizeof(bs));
	for(int i = 4;i*i <= 50001;i += 2) bs[i] = false;
	for(int i = 3;i * i <= 50001;i += 2){
		for(int j = i*i;j <= 50001;j += i+i){
			bs[j] =false;
		}
	}
	primes[ind++] = 2;
	for(int i = 3;i < 50001;i++)if(bs[i]) primes[ind++] = i;
}



int phi(int n){
	int ans = n;
	int ind = 0;
	while(primes[ind]*primes[ind] <= n){
		if(n % primes[ind] == 0){
			ans -= ans / primes[ind];
			while(n % primes[ind] == 0) n /= primes[ind];
		}
		ind++;
	}
	if(n != 1)ans -= ans / n;
	return ans;
}


int ans[50010];
void precal(){
	ans[1] = 1;
		for(int i = 2;i <= 50000;i++){
		ans[i] = ans[i-1] + 2*phi(i);
	}
}


int main(){
	sieve();
	precal();
	int n;
	while(cin >> n && n){
		cout << ans[n] << endl;
	}
}