#include <bits/stdc++.h>
using namespace std;

int main(){
    //            freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int T;
    cin >>T;
    while(T--){
        int a,b,dolar;
        cin >> a >> b >> dolar;
        int ans = dolar * (2*a - b)/(a+b);
        if(ans < 0)ans = 0;
        cout << ans << endl;
    }
}