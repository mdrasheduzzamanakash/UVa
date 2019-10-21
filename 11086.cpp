#include <bits/stdc++.h>
using namespace std;

bool isPrime[1111111];
int primes[1111111];
int ind = 0;
void sieve(){
	memset(isPrime,true,sizeof(isPrime));
	for(int i = 4;i < 1111110;i += 2)isPrime[i] = false;
	for(int i = 3;i*i < 1111110;i += 2){
		for(int j = i*i;j < 1111110;j += i+i){
			isPrime[j] = false;
		}
	}
	primes[ind++] = 2;
	for(int i = 3;i < 1111110;i++)if(isPrime[i] == true) primes[ind++] = i;
}




bool isComposite[1111111];
void precal(){

	memset(isComposite,false,sizeof(isComposite));
	for(int i = 4;i < 1111111;i++){
		int ind = 0;
		int n = i;
		while(primes[ind] * primes[ind] <= n){
			if(n % primes[ind] == 0){
				if(isPrime[n / primes[ind]] == true){
					isComposite[i] = true;
					break;
				}
			}
			ind++;
		}
	}
}


int main(){
	sieve();
	precal();
	int n;
	while(cin >> n){
		int ans = 0;
		while(n--){
			int x; cin >> x;
			isComposite[x] == true ? ans++ : ans = ans;
		}
		cout << ans << endl;
	}
}