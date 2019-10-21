/*
        BISMILLAHIR RAHMANIR RAHIM
        MD Rasheduzzaman (CUET)
        mdrasheduzzamanakash@gmail.com
*/
#include <bits/stdc++.h>
#define PI 3.1415926535897932385
#define ll64 unsigned long long
#define ll long long
#define INF 500000000
#define maxN 1000001
using namespace std;


//arrays of my tools
ll primes[maxN];
ll factors[maxN];


//sieve
bool bs[maxN];
int size_primes;
void sieve(){
    memset(bs,true,sizeof(bs));
    bs[0] = bs[1] = false;
    for(ll i = 4;i < maxN; i += 2) bs[i] = false;
    for(ll i = 3;i*i < maxN;i += 2){
        if(bs[i])
            for(ll j = i*i;j < maxN;j += i+i)  bs[j] = false;
    }
    primes[size_primes++] = 2;
    for(ll i = 3;i < maxN;i += 2) if(bs[i])    primes[size_primes++] = i;
}


ll size_fac = 0;
void primeFactors(ll n){
    ll ind = 0;
    ll temp = primes[ind++];
    while(temp*temp <= n){
        while(n % temp == 0){
            n /= temp;
            factors[size_fac++] = temp;
        }
        temp = primes[ind++];
    }
    if(n != 1){
        factors[size_fac++] = temp;
    }
}


ll numDiffPF(ll n){
    ll ind = 0, temp = primes[ind],ans = 0;
    while(temp*temp <= n){
        if(n % temp == 0) ans++;
        while(n % temp == 0) n /= temp;
        temp = primes[++ind];
    }
    if(n != 1)ans++;
    return ans;
}


ll numDiv(ll n){
    ll ind = 0,temp = primes[ind],ans = 1;
    while(temp*temp <= n){
        ll p = 0;
        while(n % temp == 0){
            n /= temp;
            p++;
        }
        ans *= (p + 1);
        temp = primes[++ind];
    }
    if(n != 1) ans *= 2;
    return ans;
}


ll EulerPhi(ll N){
    ll PF_idx = 0, PF = primes[PF_idx], ans = N;

    while(PF * PF <= N){
        if(N % PF == 0)
            ans -= ans / PF;

        while(N % PF == 0)
            N /= PF;

        PF = primes[++PF_idx];
    }

    if(N != 1)
        ans -= ans / N;

    return ans;
}

bool isPrime(ll N){
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}


//dividing large number
bool cheak(string s,long long d){
    string ts="";
    long long dif=0,temp,cnt;
    for(long long i = 0;i < s.size();){
        temp = dif,cnt=1;
        while(temp < d && i < s.size()){
            if(cnt >= 2) ts += "0";
            temp = temp*10 + (s[i]-'0');
            // cout << "temp = " << temp << endl;
            cnt++;
            i++;
        }
        long long q = temp/d;
        dif = temp - (q*d);
        string tss="";
        while(q != 0){
            tss += to_string(q%10);
            q /= 10;
        }
        reverse(tss.begin(),tss.end());
        ts += tss;
    }
    if(dif != 0) return false;
    else return true;
}


// here is some of big integer related code
//mod of large exponent
template <class T>
T bigmod(T b,T p,T m){
    if(p == 0)return 1;
    if(p & 1) return ((b % m) * bigmod(b,p-1,m)) % m;
    else{
        T t = bigmod(b,p/2,m);
        return (t * t) % m;
    }
}


template <class T>
T gcd(T a, T b, T & x, T & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    T x1, y1;
    T d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
