#include <bits/stdc++.h>
using namespace std;

#define INF 500000000
#define maxN 100000
using namespace std;

bool bs[maxN];
vector<int>primes;
void sieve(){
    memset(bs,1,sizeof(bs));
    bs[0] = bs[1] = false;
    for(int i = 4;i < maxN; i += 2) bs[i] = false;
    for(int i = 3;i*i < maxN;i += 2){
        if(bs[i])
            for(int j = i*i;j < maxN;j += i+i)  bs[j] = false;
    }
    primes.push_back(2);
    for(int i = 3;i < maxN;i += 2) if(bs[i])    primes.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(false);cout.tie(false);
    sieve();
    long long n,m;
    while(cin >> n >> m){
        long long mm = m;
        bool flag = true;
        // long long sq = sqrt(m)+1;
        for(int i = 0;primes[i]*primes[i] <= m && flag; i++){
            
            if(m % primes[i] == 0){
                long long cnt = 0;
                while(m % primes[i] == 0) cnt++,m /= primes[i];

                long long temp = primes[i];
                long long cntn = 0;
                while(temp <= n){
                    cntn += n / temp;
                    temp *= primes[i];
                }

                if(cntn < cnt){
                    flag = false;
                }
            }
            // sq = sqrt(m) + 1;
            
        }

        if(m != 1){
            if(n < m)flag = false;
        }

        if(flag)cout<<mm<<" divides "<<n<<"!"<<endl;
        else cout<<mm<<" does not divide "<<n<<"!"<<endl;
    }
    return 0;
}