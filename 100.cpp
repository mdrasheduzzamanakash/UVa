#include <bits/stdc++.h>
using namespace std;

int main() {
    //            freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    long long int a,b;
    while(scanf("%lld %lld",&a,&b) == 2){
        cout << a << " " << b << " ";
        if(a > b) swap(a,b);
        long long int mx = -1;
        for(long long int i = a,temp,cnt;i <= b;i++){
            temp = i;
            cnt = 1;
            while(temp != 1){
                cnt++;
                if(temp % 2 != 0) temp = 3*temp + 1;
                else temp /= 2;
            }
            mx = max(mx,cnt);
        }
        cout << mx << endl;
    }
}