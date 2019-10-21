#include <bits/stdc++.h>
using namespace std;

int a[100];
void fibo(){
	memset(a,0,sizeof(a));
	a[0] = 0;
	a[1] =1;
	a[2] = 1;
	for(int i = 3;i <= 60;i++){
		a[i] = a[i-1] + a[i-2];
	}
}

int main(){
	fibo();
	int n;
	while(cin >> n && n){
		cout << a[n+1] << endl;
	}
}