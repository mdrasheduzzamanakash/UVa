#include <bits/stdc++.h>
using namespace std;


long long bigmod(long long b,long long p,long long m){
	if(p == 0)return 1;
	if(p & 1) return ((b % m) * bigmod(b,p-1,m)) % m;
	else{
		long long t = bigmod(b,p/2,m);
		return (t * t) % m;
	}
}




int main(){
	long long b,p,m;

	while(cin >> b >> p >> m){
		cout << bigmod(b,p,m) << endl;
	}
}