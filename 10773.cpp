#include <bits/stdc++.h>
using namespace std;





int main() {
    int T,kse = 0;
    cin >> T;
    while(T--){
        double d,v,u;
        cin >> d >> v >> u;
        double t1,t2;
        t1 = d / u;
        t2 = d / sqrt(u*u - v*v);
        if(v >= u || t1 == t2){
            printf("Case %d: can't determine\n", ++kse);
            continue;
        }else {
            printf("Case %d: %.3lf\n", ++kse,abs(t2-t1));
        }
    }
}