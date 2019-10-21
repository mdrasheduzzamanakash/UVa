#include <bits/stdc++.h>
using namespace std;

/* very efficient sieve algorithm */
int bs[1000000] = {0};
int prime[100000];
int ind=0;

void sieve(){
    int i,j;
    prime[ind++] = 2;
    for(int i = 3;i < 1000000; i+=2){
        if(bs[i] == 0){
            prime[ind++] = i;
            for(j = 3; i*j <= 1000000;j += 2){
                bs[i*j] = 1;
            }
        }
    }
}

int main(){
    sieve();
    int n,m,t;
    cin >> t;
    for(int cc = 1;cc <= t;cc++){
        cin >> m >> n;
        int mn = 0xfffffff;
        bool flag = true;
        for(int i = 0;prime[i] <= m;i++){
            if(m%prime[i] == 0){
                int cntm = 0;
                while(m%prime[i] == 0){
                    cntm++;
                    m /= prime[i];
                }

                int temp = prime[i];
                int cntn = 0;
                while(temp <= n){
                    cntn += floor((double)n / (double)temp);
                    temp *= prime[i];
                }

                if(cntn < cntm){
                    flag = false;
                    break;
                }
                mn = min(mn, (cntn/cntm));
            }
        }
        if(mn == 0)flag == false;

        cout << "Case " << cc << ":\n";
        if(!flag){
            cout << "Impossible to divide\n";
        }
        else{
            cout << mn << endl;
        }

    }
    return 0;
}
