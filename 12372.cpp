#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
        cin >> n;
        for(int c = 1;c <= n;c++){
            int a,b,d;  cin >> a >> b >> d;

            if(a > 20 || b > 20 || d > 20){
                printf("Case %d: bad\n",c);
            }
            else printf("Case %d: good\n",c);
        }
    return 0;
}