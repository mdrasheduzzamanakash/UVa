#include <bits/stdc++.h>
using namespace std;



int Euclid(int a,int b,int &x,int &y){
	if(a == 0){
		x = 0,y = 1;
		return b;
	}
	int x1,y1;
	int d = Euclid(b % a, a, x1,y1);
	x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


int main(){
	int test;
	cin >> test;
	while(test--){
		int n,k,x,y;
		cin >> n >> k;
		int d = Euclid((n / k),( n / k + 1), x, y);
		int p = n * x;
		int q = n * y;
		cout << p << " " << q << endl;
	}
}