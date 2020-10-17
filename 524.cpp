#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <sstream>
#include <cstring>
#define db cout << "debug";
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define maxN 100010
#define INP freopen("i.txt","r",stdin)
#define OUT freopen("o.txt","w",stdout)
using namespace std;
bool primes[50];
int order[20],n;
bool used[20];
bool isValid(int idx, int val) {
    if(idx == n)
    return (primes[val+order[idx-1]] && primes[val+1]);
    else return primes[val+order[idx-1]];
}
void bktk(int idx) {
    if(idx == n+1) {
        cout << 1;
        for(int i= 2;i < idx;i++) {
            cout << " " << order[i];
        }
        cout << endl;
    }else {
        for(int i = 2;i <= n;i++) {
            if(used[i] == false && isValid(idx, i)) {
                order[idx] = i;
                used[i] = true;
                bktk(idx+1);
                used[i] = false;
            }
        }
    }
}
int main() {
    // INP;OUT;
    int kse = 1;
    order[1] = 1;
    memset(primes, false, sizeof primes);
    primes[2]=primes[5]=primes[11]=primes[17]=primes[23]=primes[31]=primes[41]=primes[47] = true;
    primes[3]=primes[7]=primes[13]=primes[19]=primes[29]=primes[37]=primes[43] = true;
    while(cin >> n) {
        if(kse != 1)cout << endl;
        memset(used, false, sizeof used);
        cout << "Case " << kse++ << ":" << endl;
        bktk(2);
    }
}