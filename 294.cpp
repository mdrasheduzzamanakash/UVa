#include <bits/stdc++.h>
using namespace std;

bool bs[40000] = {false};
int prime[40000];
int ind = 0;

void sieve(){
    prime[ind++] = 2;
    for(int i = 3;i < 40000;i += 2){
        if(!bs[i]){
            prime[ind++] = i;
            for(int j = 3;i*j <= 40000;j += 2){
                bs[i*j] = true;
            }
        }
    }
}

int main(){
    sieve();
    long long int l,u,t;
    cin >> t;
    while(t--){
        long long int mx = -1,mxNUM;
        cin >> l >> u;
        for(long long int i = l;i <= u;i++){
            long long int temp = i;
            long long int cnt,com = 1;
            for(int i = 0;i < ind && prime[i] <= temp;i++){
                cnt = 0;
                if(temp % prime[i] == 0){
                    while(temp % prime[i] == 0){
                        temp /= prime[i];cnt++;
                    }

                }
                com *= (cnt+1);
            }
            if(temp != 1)com *= 2;

            if(com > mx)mx = com,mxNUM = i;
        }

        cout << "Between " << l << " and " << u << ", " << mxNUM << " has a maximum of " << mx << " divisors." << endl;
    }
}