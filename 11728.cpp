#include <bits/stdc++.h> 
using namespace std; 
 
bool bs[1000000];
int primes[1000000];
int ind = 0;

void sieve(){
	memset(bs,true,sizeof(bs));
	for(int i = 4;i < 1000000;i += 2)bs[i] = false;
	for(int i = 3;i <= sqrt(1000000);i += 2){
		for(int j = i*i;j < 1000000;j += i + i){
			bs[j] = false;
		}
	}
	primes[ind++] = 2;
	for(int i = 3;i < 1000000;i += 2){
		primes[ind++] = i;
	}
}


int sumFactors(int n){
	int ind = 0,ans = 1;
	while(primes[ind]*primes[ind] <= n){
		if(n % primes[ind] == 0){
			int p = 0;
			while(n % primes[ind] == 0)p++,n /= primes[ind];
			ans *= ((pow(primes[ind],p+1) - 1) / (primes[ind] - 1));
		}
		ind++;
	}
	if(n != 1) (ans *= (n*n - 1) / (n - 1));
	return ans;
}

int ans[1100];
void precal(){
	memset(ans,0,sizeof(ans));
	for(int i = 1;i <= 1001;i++){
		int temp = sumFactors(i);
		if(temp <= 1000)ans[temp] = i;
	}
}


int main() { 
	sieve();
	precal();
	int n,cc = 1;
	while(cin >> n && n){
		if(ans[n] != 0)
			printf("Case %d: %d\n",cc++,ans[n]);
		else
			printf("Case %d: -1\n",cc++);
	}
	return 0; 
}