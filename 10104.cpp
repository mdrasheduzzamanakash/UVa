#include <bits/stdc++.h>
using namespace std;


template <class T>
T gcd(T a, T b, T & x, T & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    T x1, y1;
    T d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


int main(){
	long long a,b,x,y,d;
	while(cin >> a >> b){
		// if(b == 0) swap(a,b);
		if(a == 0 && b == 0){cout << "1 0 0\n";continue;}
		d = gcd(a,b,x,y);
		if((a*x + b*y) == d ){
			if(x > y && (a*y + b*x) == d){
				swap(x,y);
			}
		}
		else swap(x,y);

		cout << x << " " << y << " " << d << endl;
	}
}