#include <bits/stdc++.h>
using namespace std;





int main() {
    int l,f;
    while(cin >> l >> f && (l || f)){
        double v=sqrt(2*l*f);
        cout << fixed << setprecision(8) << v << " " << 
        fixed << setprecision(8) << (3600*v)/(l+v*v/2/f) << endl;
    }
}