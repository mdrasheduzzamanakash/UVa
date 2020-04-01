#include <bits/stdc++.h>
using namespace std;




int main() {
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    double n,a,dx;
    while(cin >> n && n != 0){
        for(int i=1;;i++){
            if(i*i*i > n){
                a=i-1;break;
            }
        }
        dx=(n-(a*a*a))/3/a/a;
        cout << fixed << setprecision(4) << a+dx << endl;
    }
}