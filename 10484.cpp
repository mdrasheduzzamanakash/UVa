#include <bits/stdc++.h>
using namespace std;



int main(){

    long long N,D;
    while(cin >> N >> D && (N || D)){
        D = abs(D);
        long long a[110] = {0};
        for(long long i = 2;i <= N;i++){
            
            long long n = i;
            for(long long j = 2;j <= n;j++){

                while(n % j == 0){
                    a[j]++;
                    n /= j;
                }
            }

        }

        bool flag = true;
        for(long long i = 2;i <= 100 && flag;i++){
            while(D % i == 0){
                if(a[i] == 0){
                    // cout << 0 << endl;
                    flag = false;
                    break;
                }

                a[i]--;
                D /= i;
                // cout << "#";
            }
        }

        if(D != 1 && (D > 100 || a[D] == 0))flag = false;
        else if(D != 1){
            a[D]--;
        }


        long long ans = 1;
        for(long long i = 2;i <= N;i++)
            ans *= (a[i]+1);

        if(flag)cout << ans << endl;
        else    cout << 0 << endl;        
    }
    return 0;
}