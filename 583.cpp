#include <bits/stdc++.h>
#define maxN 100001
using namespace std;


bitset<maxN>bs;
vector<long long>primes;
void Sieve() {
    bs.set();
    bs[0] = bs[1] = false;
    for (int i=4; i<maxN; i+=2) bs[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (bs[i]) for (int j=i*i; j<maxN; j+=i+i)
            bs[j] = false;
    primes.push_back(2);
    for (int i=3; i<maxN; i+=2)
        if (bs[i]) primes.push_back(i);
}


// bool is_prime(long long n){
//     int i = 0;
//     while(primes[i]*primes[i] <= n){
//         if(n % primes[i] == 0)return false;
//         i++;
//     }
//     return true;
// }



int main(){
    Sieve();
    long long n;
    while(cin >> n && n){
        long long t = n;
        bool flag = false;
        if(n < 0){
            flag = true;
            n = n*(-1);
        }
        int ind = 0;
        vector <int>v;
        while(primes[ind]*primes[ind] <= n){
            while(n % primes[ind] == 0){
                n = n/primes[ind];v.push_back(primes[ind]);
            }
            ind++;
        }
        if(n != 1)v.push_back(n);

        if(flag)printf("%lld = ",t);
        else printf("%lld = ",t);

        if(flag)cout << "-1 x ";

        for(int i = 0;i < v.size()-1;i++){
            cout << v[i] << " x ";
        }
        cout << v[v.size() - 1] << "\n";
    }
}