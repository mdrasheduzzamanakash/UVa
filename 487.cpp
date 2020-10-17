
#include <cstdio>
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
#define INP() freopen("i.txt","r",stdin)
#define OUT() freopen("o.txt","w",stdout)
using namespace std;
int n;
char m[21][21];
bool used[21][21];
set<string> ans;
char save[500];
int px[] = {0,-1,-1,-1,0,1,1,1};
int py[] = {1,1,0,-1,-1,-1,0,1};
bool cmp(string a, string b) {
    return a.size() < b.size();
}
bool isValid(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    else return true;
}
void dfs(int x, int y,int d = 0) {
    if(d >= 3){
        save[d] = '\0';
        ans.insert(save);
    }
    if(isValid(x, y) == false) return;
    if(d > 0 && m[x][y] <= save[d-1]) return;
    if(used[x][y]) return;
    save[d] = m[x][y];
    used[x][y] = true;
    for(int i = 0;i < 8;i++) 
        dfs(x+px[i], y+py[i],d+1);
    used[x][y] = false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) cin >> m[i][j];
        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) used[i][j] = false;
        ans.clear();
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                dfs(i, j);
            }
        }
        vector<string> v;
        for(auto i : ans) v.push_back(i);
        stable_sort(all(v),cmp);
        for(auto i : v) cout << i << endl;
        if(t) cout << endl;
    }
    return 0;
}