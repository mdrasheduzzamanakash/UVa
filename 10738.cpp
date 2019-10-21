#include <bits/stdc++.h>
using namespace std;



bool bs[1000010];
int primes[1000010];
int ind = 0;
void sieve(){
	memset(bs,true,sizeof(bs));
	for(int i = 4;i < 1000010;i += 2)bs[i] = false;
	for(int i = 3;i*i < 1000010;i += 2){
		for(int j = i * i;j < 1000010;j += i + i){
			bs[j] = false;
		}
	}
	primes[ind++] = 2;
	for(int i = 3;i < 1000010; i += 2)if(bs[i] == true)primes[ind++] = i;
}


int ans[1000010];
int Mu[1000010];
void mu(){
	ans[1] = 1;
	for(int i = 2;i < 1000010;i++){

		int uF = 0,uFpro = 1,n = i,ind = 0;
		while(primes[ind]*primes[ind] <= n){
			if(n % primes[ind] == 0){
				uF++;
				uFpro *= primes[ind];
				while(n % primes[ind] == 0) n /= primes[ind];
			}
			ind++;
		}
		if(n != 1)uF++,uFpro *= n;


		if(uFpro != i){
			ans[i] = 0;
			Mu[i] = 0;
		}
		else if(uFpro == i && (uF % 2 == 0)){
			ans[i] = Mu[i] = 1;
		}
		else ans[i] = Mu[i] = -1;
	}
}


int main(){
	sieve();
	mu();
	Mu[1] = 1;
	for(int i = 2;i < 1000010;i++){
		Mu[i] = Mu[i] + Mu[i-1];
	}
	// for(int i = 0;i <= 20;i++)cout << Mu[i] << " ";
	int n;
	while(cin >> n && n){
		printf("%8d%8d%8d\n",n,ans[n],Mu[n]);
	}
	return 0;
}