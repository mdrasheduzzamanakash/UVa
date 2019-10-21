#include <bits/stdc++.h>
using namespace std;


int main(){
    int ts = 1;
    char s[11];
    int j;

    while(cin >> j && j != -1){
        cin >> s;
        int n = static_cast <int> (strtol(s+2,NULL,10));
        
        int k = strlen(s+2) - j;
        int num,den;
        if(j){
            num = n - int(n/pow(10,j));
            den = pow(10,j+k) - pow(10,k);
        }
        else{
            num = n;
            den = pow(10,k+j);
        }
        // cout << num <<" " << den;
        int g = __gcd(num,den);
        printf("Case %d: %d/%d\n",ts++,num/g,den/g);
    }
    return 0;
}