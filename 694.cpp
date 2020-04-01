#include <bits/stdc++.h>
using namespace std;




int main() {
    long long int a,b,kse=1;
    while(cin >> a >> b && (a+b)>=0){
        long long int cnt=0;
        long long int aa=a,bb=b;
        while(1){
            cnt++;
            if(a%2==0)a/=2;
            else a=a*3+1;
            if(a==1){
                cnt++;break;
            }
            if(a>b)break;
        }
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",kse++,aa,bb,cnt);
    }
}