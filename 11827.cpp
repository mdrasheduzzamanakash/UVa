/*
        BISMILLAHIR RAHMANIR RAHIM
        MD Rasheduzzaman (CUET)
		mdrasheduzzamanakash@gmail.com
*/

#include<bits/stdc++.h>
using namespace std;


#define        PI                  acos(-1)
#define        debug               printf("#\n")
#define        MOD                 1
#define        ll                  long long
#define        ull                 unsigned long long
#define        dbl                 double
#define        mp                  make_pair
#define        pb                  push_back
#define        makefast            ios_base::sync_with_stdio(false);
#define        ff                  first
#define        ss                  second
#define        vl                  vector < ll,ll >
#define        vpl                 vector < pair < ll,ll > >
#define        vpi                 vector < pair < int,int> >
#define        vps                 vector < pair < string,string > >
#define        all(v)              v.begin(),v.end()
#define        maxN                100000001  //required limit may goes on
// //prime cheaking function
// bool is_prime(long long n){
// 	for(int i = 2,sq = sqrt(n);i <= sq;i++){
// 		if(n%i == 0)
// 			return false;
// 	}
// 	return true;
// }

// //lcm
// ll lcm(ll c,ll d){
//     return ((c * d) / __gcd(c,d));
// }

// //factorizing a number
// vector<int>factors;
// void factor(ll n){
//     factors.clear();
// 	for(int i = 1;i <= sqrt(n);i++){
// 		if(n % i == 0)factors.push_back(i);
// 		if(i != (n / i))factors.push_back(n/i);
// 	}
// }


// //generating primes
// bitset<maxN>bs;
// vector<int>primes;
// void Sieve() {
//     bs.set();
//     bs[0] = bs[1] = false;
//     for (int i=4; i<maxN; i+=2) bs[i] = false;
//     for (int i=3; i*i<maxN; i+=2)
//         if (bs[i]) for (int j=i*i; j<maxN; j+=i+i)
//             bs[j] = false;
//     primes.push_back(2);
//     for (int i=3; i<maxN; i+=2)
//         if (bs[i]) primes.push_back(i);
// }

vector<int>use;
//main code........................
int main(){
	int t;  scanf("%d",&t);
    while(t--){
        int v,mx = -1;
        use.clear();
        while(scanf("%d",&v) != EOF){
            use.push_back(v);
        }
        for(int i = 0;i < use.size();i++)
            for(int j = i+1;j < use.size();j++)
                mx = max(mx , __gcd(use[i],use[j]));
        
        printf("%d\n",mx);
    }
    return 0;
}
