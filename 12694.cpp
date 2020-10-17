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
#define pf push_front
#define ff first
#define ss second
#define maxN 100010
using namespace std;
int n;
pair<int, int> evnt[25];
bool used[25];
int ans = 0;
void backTrack(int i, int cnt,int last){
    if(i == n) return;
    if(evnt[i].ff >= evnt[last].ss){
        ans = max(ans, cnt+1);
        backTrack(i+1, cnt+1, i);
    }
    backTrack(i+1, cnt, last);
}

int main() {
    int kse;
    cin >> kse;
    while(kse--) {
        ans = 0;
        evnt[0].ff = evnt[n].ss = 0;
        n = 1 ;
        while(cin >> evnt[n].ff >> evnt[n].ss) {
            if(evnt[n].ff == evnt[n].ss && evnt[n].ff == 0)break;
            n++;
        }
        sort(evnt, evnt+n);
        for(int i = 0;i < n;i++) used[i] = false;
        backTrack(1,0,0);
        cout << ans << endl;
    }
}