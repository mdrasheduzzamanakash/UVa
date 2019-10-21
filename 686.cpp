#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <iterator>

#define ll long long
using namespace std;

/* this is sieve algorithm to generate primes in "vector<int>primes" */
bitset<10000100>bs;
vector<ll>primes;
void sieve(ll up){
    bs.set();   bs[0] = bs[1] = 0;
    // primes.push_back(1);

    for(ll i = 2;i <= up;++i){
        if(bs[i]){
            for(long long j = i*i; j <= up+1;j += i){
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}


int main(){
    int n;
    while(cin >> n && n){
        primes.clear();
        sieve(n);
        int cnt = 0;
        int sz = primes.size();
        bool flag = true;
        
        for(int i = 0;i < sz;i++){
            int x = primes[i];
            int y = n - primes[i];

            if(x < y && (bs[x] && bs[y])){
                // cout << x << " " << y << endl;
                cnt++;
            }
            else if(x == y && flag){
                // cout << x << " " << y << endl;
                cnt++;
                flag = false;
            }
            else continue;
        }

        cout << cnt << endl;
    }
}