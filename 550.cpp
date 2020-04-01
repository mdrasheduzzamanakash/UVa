#include <bits/stdc++.h>
using namespace std;

int main(){
//     freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    long long int base,ld,sf;
    while(scanf("%lld %lld %lld",&base,&ld,&sf) != EOF){
        long long int cnt = 0 ;
        long long int carry = 0,ans;
        do{
            ans = ld * sf + carry;
            carry = ans / base;
            ld = ans % base;
            cnt++;
        }while(ans != ld);
        cout << cnt << endl;
    }
    return 0;
}