#include <bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin >> t;

    for(int cc = 1;cc <= t;cc++){

        int a[1010] = {0};
        char s[100];
        scanf("%s",s);
        int n,m=0;
        sscanf(s,"%d",&n);
        for(int i = 0;s[i];i++)if(s[i] == '!')m++;

        //ok
        for(int i = n;i >= 0;i -= m){

            int temp = i;
            for(int j = 2;j <= i;j++){
                if(temp % j == 0){
                    while(temp % j == 0){
                        a[j]++;
                        temp /= j;
                    }
                }
            }

        }
        //ok

        long long ans = 1;
        double sum = 0;
        for(int i = 0;i <= n;i++){
            if(a[i] != 0){
                ans *= a[i]+1;
                sum += log10(a[i]+1);
            }
        }

        if(ceil(sum) > 18){
            printf("Case %d: Infinity\n",cc);
        }
        else {
            printf("Case %d: %lld\n",cc,ans);
        }
    }
}