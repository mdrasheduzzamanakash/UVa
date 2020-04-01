#include <bits/stdc++.h>
using namespace std;

bool cheack(int n){
    while(n){
        int d = n % 10;
        if(d == 7){
            return true;
        }
        n /= 10;
    }
    return false;
}

int main() {
    int n,m,k;
    while(cin >> n >> m >> k && (n || m || k)){
        int kk = 0;
        int cnt = 0xfffffff;
        int progress = 0,x,y;
        bool f = false;
        while(cnt--){
            x = progress + m;
            y = progress + n + (n-m);
            if(x % 7 == 0 || cheack(x)){
                kk++;
                if(kk == k){
                    f = true;
                    printf("%d\n",x);
                    break;
                }
            }
            if(m != 1 && m != n && (y % 7 == 0 || cheack(y))){
                kk++;
                if(kk == k){
                    f = true;
                    printf("%d\n",y);
                    break;
                }
            }
            progress += 2*n - 2;
        }
        if(!f) printf("-1\n");
    }
    return 0;
}