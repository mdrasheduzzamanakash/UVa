#include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned long long n;
	while(cin >> n && n){
		bool flag = false;
		unsigned long long ans = (10 * n) / 9;
		if(ans % 10 == 0){
			flag = true;
		}
		
		if(flag){
			cout << ans - 1 << " " << ans << endl;
		}
		else cout << ans << endl;
	}
	return 0;
}