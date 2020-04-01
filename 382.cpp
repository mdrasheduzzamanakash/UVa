#include <bits/stdc++.h>
using namespace std;



int main() {
    //  freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int a[101];
    string s[60005];
    int n,idx = 0;
    while(cin >> n && n){
        a[idx] = n; idx++;
    }

    printf("PERFECTION OUTPUT\n");
    for(int i = 0;i < idx;i++){
        int temp = a[i];
        long long int sum = 0;
        for(int d = 1;d < temp;d++){
            if(temp % d == 0){
                sum += d;
            }
        }
        if(sum == a[i]){
            printf("%5d  PERFECT\n",a[i]);
        }else if(sum > a[i]){
            printf("%5d  ABUNDANT\n",a[i]);
        }else {
            printf("%5d  DEFICIENT\n",a[i]);
        }
    }
    printf("END OF OUTPUT\n");
}