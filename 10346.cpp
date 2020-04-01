#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);

    int n,k;
    while(scanf("%d%d",&n,&k) == 2){
        int cnt = n;
        int but = n;
        while(but / k){
            cnt += but / k;
            int temp = but % k;
            but = (but / k) + temp;
        }
        cout << cnt << endl;
    }
}