#include <bits/stdc++.h>
using namespace std;



int main(){
	long long m,n,ans,mod;
	while(scanf("%lld %lld",&m,&n) != EOF){
		ans = 1;
		for(long long i = m;i >= (m-n+1);i--){
			ans *= i;
			while(ans % 10 == 0)ans /= 10;
			ans %= 1000000000;
		}
		cout << ans % 10 << endl;
	}

}