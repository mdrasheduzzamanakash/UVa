#include <bits/stdc++.h>
using namespace std;



int main() {
//             freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    double pi = acos(-1);
    double a,b,v,A,t;
    while(cin >> a >> b >> v >> A >> t && (a || b || v || A || t)){
        double L = v*t / 2;
        double h = L*cos(A/180*pi);
        double ver = L*sin(A/180*pi);
        printf("%.0lf %.0lf\n",h/a,ver/b);
    }
    return 0;
}