// /*
//         BISMILLAHIR RAHMANIR RAHIM
//         MD Rasheduzzaman (CUET)
// 		mdrasheduzzamanakash@gmail.com
// */

// #include<bits/stdc++.h>
// using namespace std;


// #define        PI                  acos(-1)
// #define        debug               printf("#\n")
// #define        MOD                 1
// #define        ll                  long long
// #define        ull                 unsigned long long
// #define        dbl                 double
// #define        mp                  make_pair
// #define        pb                  push_back
// #define        makefast            ios_base::sync_with_stdio(false);
// #define        ff                  first
// #define        ss                  second
// #define        vl                  vector < ll,ll >
// #define        vpl                 vector < pair < ll,ll > >
// #define        vpi                 vector < pair < int,int> >
// #define        vps                 vector < pair < string,string > >
// #define        all(v)              v.begin(),v.end()
// #define        maxN                10000001  //required limit may goes on
// //prime cheaking function
// bool is_prime(long long n){
// 	for(int i = 2,sq = sqrt(n);i <= sq;i++){
// 		if(n%i == 0)
// 			return false;
// 	}
// 	return true;
// }

// bitset<maxN>bs;
// vector<int>primes;
// //generating primes
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
// //finding gcd
// ll gcd(ll a,ll b){
//     while(b){
//         a = a%b;
//         swap(a,b);
//     }
//     return a;
// }
// //main code........................
// ll a[maxN+1];
// int main(){
// 	while(scanf("%lld",a)){
//         if(a[0] == 0)return 0;
        
//         ll i = 1,g = 0;
//         while(1){
//             scanf("%lld",a+i);
//             if(a[i]==0)break;
//             else ++i;
//         }
//         for(ll j = 1;j < i;j++){
//             g = gcd(g , a[j] - a[j-1]);
//         }
//         if(g < 0)g *= -1;
//         printf("%lld\n",g);
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int>v;
    while(cin >> n && n){
        v.clear();
        v.push_back(n);
        while(cin >> n && n){
            v.push_back(n);
        }
        int g = 0;
        for(int i = 1;i < v.size();i++){
            g = __gcd(g, v[i] - v[i-1]);
        }
        if(g < 0)g *= -1;
        cout << g << endl;

    } 
}