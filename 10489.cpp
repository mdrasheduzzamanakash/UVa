#include <bits/stdc++.h>
using namespace std;



int main(){
	long long test;
	cin >> test;
	while(test--){
		long long n,b,k,v,ans,f_ans = 0;
		cin >> n >> b;
		while(b--){
			cin >> k;
			ans = 1;
			while(k--){
				cin >> v;
				ans *= v;
				ans %= n;
			}
			f_ans += ans;
		}
		cout << f_ans % n << endl;
	}
}