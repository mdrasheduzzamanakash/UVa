#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    while (cin >> n)
    {
        int cnt=0,acnt = 0;
        int bs[n+1] = {0};
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                int sum = i*i + j*j;
                int z = (int)sqrt(sum);
                if(z > n)break;
                if(z*z == sum && z <= n && i < j && j < z){
                    int g = __gcd(i,j);
                    int h = __gcd(g,z);

                    if(g == 1 && h == 1){
                        cnt++;
                        bs[i] = 1;
                        bs[j] = 1;
                        bs[z] = 1;
                    }
                    else{
                        bs[i] = 1;
                        bs[j] = 1;
                        bs[z] = 1;
                    }
                }
               
            }
        }
        int sum = 0;
        for(int i = 1;i <= n;i++){
            if(!bs[i]){
                sum += 1;
            }
        }
        cout << cnt << " " << sum << endl;
    }
    return 0;
}