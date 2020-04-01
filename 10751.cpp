#include <bits/stdc++.h>
using namespace std;





int main() {
//     freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int d = (n-2)*(n-2);
        int s = (n*n)-d;
        double tot = d*sqrt(2) + s;
        if(n == 1)tot = 0.000;
        else if(n == 2) tot = 4.000;
        cout << fixed << setprecision(3) << tot << endl;
        if(T)cout << endl;
    }
}