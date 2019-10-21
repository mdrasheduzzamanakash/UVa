#include <bits/stdc++.h>
using namespace std;



int main(){
    int test;
    cin >> test;
    for(int i = 1;i <= test;i++){
        int t1,t2,f,att,ct[3];
        cin >> t1 >> t2 >> f >> att >> ct[0] >> ct[1] >> ct[2];
        int sum = t1 + t2 + f + att;
        sort(ct,ct+3);
        int d = (ct[1]+ct[2])/2;
        sum += d;
        //now grading system
        if(sum >= 90)                    printf("Case %d: A\n",i);
        else if(sum < 90 && sum >= 80)   printf("Case %d: B\n",i);
        else if(sum < 80 && sum >= 70)   printf("Case %d: C\n",i);
        else if(sum < 70 && sum >= 60)   printf("Case %d: D\n",i);
        else if(sum < 60)                printf("Case %d: F\n",i);
    }
    return 0;
}