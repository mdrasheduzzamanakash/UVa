#include <bits/stdc++.h>
using namespace std;

const int val = 100010;


bool bs[val];
int primes[val];
int ind = 0;
void sieve(){
	memset(bs,true,sizeof(bs));
	for(int i = 4;i < val;i+= 2) bs[i] = false;
	for(int i = 3;i*i < val;i += 2){
		for(int j = i*i;j < val;j += i+i){
			bs[j] = false;
		}
	}
	primes[ind++] = 2;
	for(int i = 3;i < val;i += 2)if(bs[i] == true)primes[ind++] = i;
}

int numDivisor[val];
int numSummation[val];

void numD(){
	for(int n = 1;n < val;n++){

		int temp = n,ind = 0,p = 0,ans = 1;
		while(primes[ind]*primes[ind] <= temp){
			if(temp % primes[ind] == 0){
				p = 0;
				while(temp % primes[ind] == 0)p++,temp /= primes[ind];
				ans *= (p+1);
			}
			ind++;
		}
		if(temp != 1) ans *= 2;
		numDivisor[n] = ans;
	}
}

void sumD(){
	for(int n = 1;n < val;n++){

		int temp = n,ind = 0,ans = 1,p = 0;
		while(primes[ind]*primes[ind] <= temp){
			if(temp % primes[ind] == 0){
				p = 0;
				while(temp % primes[ind] == 0)p++,temp /= primes[ind];
				ans *= (pow(primes[ind],p+1) - 1) / (primes[ind] - 1);
			}
			ind++;
		}
		if(temp != 1)ans *= (pow(temp,2) - 1) / (temp - 1);
		// if(bs[n] == false)ans += n;
		numSummation[n] = ans;
	}
}


long long gfun(int a,int b,int k){
	long long ans = 0;
	for(int i = a;i <= b;i++)if(i % k == 0)ans += numDivisor[i];
	return ans;
}

long long hfun(int a,int b,int k){
	long long ans = 0;
	for(int i = a;i <= b;i++)if(i % k == 0)ans += numSummation[i];
	return ans;
}


int main(){
	sieve();
	numD();
	sumD();

	// for(int i = 1;i <= 10;i++)cout << numSummation[i] << " ";
	// 	cout << endl;

	int test;
	cin >> test;
	while(test--){
		int a,b,k;
		cin >> a >> b >> k;
		cout << gfun(a,b,k) << " " << hfun(a,b,k) << endl;
	}
	return 0;
}