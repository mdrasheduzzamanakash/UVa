#include <bits/stdc++.h>
using namespace std;


int main(){
    int test,n,x; 
    cin >> test;
    for(int t = 1;t <= test;t++){
        cin >> n;
        int start=0,end,temp=1,sum=0,ans = 0;


        for(int i = 2;i <= n;i++){
            cin >> x;
            sum += x;
            if(sum < 0) temp = i,sum = 0;
            if(sum >= ans){
                if( sum > ans || (sum == ans && (i-temp > end - start))){
                    start = temp;
                    end = i;
                }
                ans = sum;
            }
        }
        if (ans > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", t, start, end);
        else
            printf("Route %d has no nice parts\n", t);
    }
    return 0;
}


