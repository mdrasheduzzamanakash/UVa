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
#include <deque>
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
int ans[14];
void cal(int k) {
    for(int k = 1;k <= 14;k++) {
        int tempAns;
        
        for(int m = 1;;m++) {
            int pos = 0;
            bool flag = false;
            for(int i = 0;i < k;i++) {
                pos = (pos+m-1) % ((2*k)-i);
                if(pos < k)flag = true;
            }
            if(!flag) {
                tempAns = m;
                break;
            }
        }
        ans[k-1] = tempAns;
    }
}

int main() {
    // INP;
    // OUT;
    int k;
    cal(k);
    while(cin >> k && k ) {
        cout << ans[k-1] << endl;
    }
}