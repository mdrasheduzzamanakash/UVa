#include <bits/stdc++.h>
using namespace std;



int main() {
    int a,b,c;
    while(cin >> a >> b >> c && (a+b+c > 0)){
        if(c == 0){
            int ans = (a-7)*(b-7)/2;
            cout << ans << endl;
        }else if(c == 1){
            int d = (a-7)*(b-7);
            if(d%2==0){
                cout << d/2 << endl;
            }else {
                cout << d/2 + 1 << endl;
            }
        }
    }
}