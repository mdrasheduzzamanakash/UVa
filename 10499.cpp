#include <bits/stdc++.h>
using namespace std;





int main() {
//     freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    double N;
    while(cin >> N && N >= 0){
        double ans = (N/4)*100;
        if(N == 1) ans = 0;
        cout << (long long int)ans << "%" << endl;
    }
}