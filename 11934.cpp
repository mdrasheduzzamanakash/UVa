#include <bits/stdc++.h>
using namespace std;



int main() {
    int a,b,c,d,l;
    while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&l) == 5){
        if(!(a || b || c || d || l))break;
        int cnt  = 0;
        for(int x = 0;x <= l;x++){
            int fx = a*x*x + b*x + c;
            if(fx % d == 0) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}