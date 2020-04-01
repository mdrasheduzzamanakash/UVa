#include <bits/stdc++.h>
using namespace std;



int main() {
//         freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    long long int n,a,sn,i,f;
    while(cin >> sn && sn >= 0){
        n = sqrt(2*sn);
        for(;n >= 1;n--){
            a = ((n+2*sn) - (n*n));
            if(a % (2*n) == 0){
                a /= 2*n;
                cout << sn << " = "<< a << " + ... + "<< a + (n - 1) * 1 <<endl;
                break;
            }
        }
    }
}