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
	int test;
	cin >> test;
	while(test--){
		long long b,p;
		cin >> b >> p;

		//first digits
		double a = p * log10(b);
		double aa = pow(10, a - floor(a) + 2);
		cout << (int)aa << "...";

		long long ans = bigmod(b,p,1000);
		if(ans < 10)cout << "00" << ans << endl;
		else if(ans < 100)cout << "0" << ans << endl;
		else cout << ans << endl;
	}
}