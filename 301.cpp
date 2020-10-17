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
#define db cout << "debug";
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define pf push_front
#define maxN 100010
#define INP() freopen("i.txt","r",stdin)
#define OUT() freopen("o.txt","w",stdout)
using namespace std;
int px[] = {0,-1,-1,-1,0,1,1,1};
int py[] = {1,1,0,-1,-1,-1,0,1};

int cap, stations, N,ans;
struct ticket {
    int s, e;
    int mass;
};
ticket orders[30];
int condition[10];
void solve(int pos,int earnings) {
    if(pos == N){
        ans = max(ans, earnings);
        return;
    } 
    solve(pos+1,earnings);
    bool flag = true;
    for(int i = orders[pos].s;i < orders[pos].e;i++) {
        if(condition[i]+orders[pos].mass > cap){
            flag = false;
            break;
        }
    }
    if(flag) {
        for(int i = orders[pos].s;i < orders[pos].e;i++)
            condition[i] += orders[pos].mass;
        solve(pos+1,earnings+orders[pos].mass*(orders[pos].e-orders[pos].s));
        for(int i = orders[pos].s;i < orders[pos].e;i++)
            condition[i] -= orders[pos].mass;
    }
}
int main() {
    // INP();OUT();
    while(cin >> cap >> stations >> N && (cap || stations || N)) {
        for(int i = 0;i < 10;i++) condition[i] = 0;
        ans = 0;
        for(int i = 0;i < N;i++) cin >> orders[i].s >> orders[i].e >> orders[i].mass;
        solve(0,0);
        cout << ans << endl;
    }
}