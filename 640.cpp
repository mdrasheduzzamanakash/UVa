#include <bits/stdc++.h>
using namespace std;





int main() {
    // freopen("i.txt","w",stdout);
    bool a[2000001];
    memset(a,true,sizeof a);
    for(int i=1;i<=1000000;i++){
        int sum=0;
        int j=i;
        while(j){
            sum+=j%10;j/=10;
        }
        a[i+sum]=false;
    }
    for(int i = 1;i<=1000000;i++){
        if(a[i])cout << i << endl;
    }
}