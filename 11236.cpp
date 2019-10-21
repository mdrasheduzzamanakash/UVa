#include<bits/stdc++.h>
using namespace std;
//11236
int main(){
    for(int i = 1;i*4 <= 2000;i++)
        for(int j = i;i+(3*j) <= 2000;j++)
            for(int k = j;i+j+(2*k) <= 2000;k++){
                long long p,s;
                p = (long long)i*j*k;
                s = (long long)(i+j+k);

                if(p <= 1e6)
                    continue;
                if(((s * 1000000) % (p-1000000)))
                    continue;
                
                long long l = (long long)(s * 1e6) / (p - 1000000);
                s += l;

                if(s > 2000 || l < k)
                    continue;
                
                printf("%d.%02d %d.%02d ", i/100, i%100, j/100, j%100);
                printf("%d.%02d %d.%02d\n", k/100, k%100, l/100, l%100);
            }
}