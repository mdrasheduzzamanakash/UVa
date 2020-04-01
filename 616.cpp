#include <bits/stdc++.h>
using namespace std;
int main() {
//     freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    long long int n,f;
    while(cin >> n && n >= 0){
        f = 1;
        for(long long int person = 20;person >= 2;person--){
            int temp = n;
            int cnt = 0;
            while(temp % person == 1){
                temp = temp - (temp/person) - 1;
                cnt++;
            }
            if(person == cnt && temp % person == 0){
                printf("%lld coconuts, %lld people and 1 monkey\n",n,person);
                f = 0;
                break;
            }
        }
        if(f){
            printf("%lld coconuts, no solution\n",n);
        }
    }
    return 0;
}