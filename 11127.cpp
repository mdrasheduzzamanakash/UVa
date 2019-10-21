#include <bits/stdc++.h>
using namespace std;





int main(){
    int t,v[3];
    cin >> t;
    for(int c = 1;c <= t;c++)
    {
        for(int i = 0;i < 3;i++)
            cin >> v[i];
        sort(v,v+3);
        printf("Case %d: %d\n",c,v[1]);
    }
    return 0;
    
}