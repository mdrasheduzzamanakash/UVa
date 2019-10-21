#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,cs = 1;
    while(cin >> n && n){
        
        int a[1010];
        for(int i = 0;i < n;i++)
            cin >> a[i];
        sort(a,a+n);

        int q;  cin >> q;
        printf("Case %d:\n",cs++);
        while(q--){
            int t,sum = 0,bf = INT_MAX;
            cin >> t;
            for(int i = 0;i < n-1;i++){
                for(int j = i+1;j < n;j++){
                    if((abs(a[i]+a[j]-t)) < bf){
                        bf = abs(a[i]+a[j]-t);
                        sum = a[i]+a[j];
                    }
                }
            }
            printf("Closest sum to %d is %d.\n",t,sum);
        }
    }
}