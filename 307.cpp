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

int N, a[100], used[100];
bool cmp(int a, int b) {
    return a > b ? true : false;
}
bool dfs(int len, int m, int cnt, int cur) {
    if(len == m) {
        len = 0;
        --cnt;
        cur = 0;
    }
    if(cnt == 0) return true;
    for(int i = cur;i < N;i++) {
        if(used[i] == 1)continue; // purning 1
        if(i && (a[i] == a[i-1] && used[i-1] == 0))continue; // purning 2
        if(a[i]+len > m) continue; // purning 3
        used[i] = 1;
        if(dfs(len + a[i], m, cnt, i+1)){
            return true;
        }
        used[i] = 0;
        if(len == 0) return false; // purning 4
    }
    return false;
}
int main() {
    // INP();OUT();
    int kse = 0;
    while(cin >> N && N) {
        // if(kse != 0)cout << endl;
        // kse++;
        int sum = 0;
        for(int i = 0;i < N;i++) {
            cin >> a[i];
            sum += a[i];
            used[i] = 0;
        }
        sort(a, a+N, cmp);
        bool flag = true;
        for(int m = a[0];m <= sum / 2;m++) {
            if(sum % m != 0) continue;
            int cnt = sum / m;
            if(dfs(0, m, cnt, 0)){
                cout << m << endl;
                flag = false;
                break;
            }
        }
        if(flag) cout << sum << endl;
    }
}