#include <bits/stdc++.h>
using namespace std;




int main(){
    int t,cse=1;
    cin >> t;



    while(t--){
        int n;
        cin >> n;
        int a[n];
        long long M = 0,N = 0,temp = 1;
        for(int i =0 ;i < n;i++){
            cin >> a[i];
            temp *= a[i];
        }
        
        M = temp*n;
        for(int i = 0;i < n;i++){
            N += temp/a[i];
        }

        long long g = __gcd(M,N);

        M = M/g;
        N = N/g;

        printf("Case %d: %lld/%lld\n", cse++, M, N);
    }
    return 0;
}