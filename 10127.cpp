#include <bits/stdc++.h>
using namespace std;



int main(){
	unsigned long long x,n,p,rem = 1;
	while(cin >> n){
		p = 0;
		rem = 1;
		while(rem != 0){
			if(rem < n) rem = rem * 10 + 1, p++;
			else rem = rem % n;
		}
		cout << p+1 << endl;
	}
}