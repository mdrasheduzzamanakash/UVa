#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    while(cin >> n && n){
        long long ttt = n;
        if(n < 0) n*=-1;
        
        // long long mx = 0;
        long long sq = sqrt(n),p = 1;;
        for(long long i = 2;i <= sq+1;i++){
        
            long long ti = i;
            if(n % ti == 0){
                while(n % ti == 0){
                    if(n / ti == 1)break;
                    ti *= i;
                }
            }

            if(n % ti == 0 && n / ti == 1){
                p = log((double)ti) / log((double)i);
                if(ttt < 0 && p%2==0){
                    p = 1;
                    continue;
                }
                break;
            }

        }
        
        cout << p << endl;
    }
}