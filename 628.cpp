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
#define ff first
#define ss second
#define maxN 100010
#define INP freopen("i.txt","r",stdin)
#define OUT freopen("o.txt","w",stdout)
using namespace std;
int n,rz;
string words[101];
static string pass[256];
static int ind[256];
void dfs(int pos) {
    if(pos == rz){
        for(int i = 0;i < rz;i++) cout << pass[i];cout << endl;return;
    }else if(ind[pos] == 0){ // words
        for(int i = 0;i < n;i++) {
            pass[pos] = words[i];
            dfs(pos+1);
        }
    }else if(ind[pos] == 1){ // digit
        for(int i = 0;i <= 9;i++) { // digit
            pass[pos] = to_string(i);
            dfs(pos+1);
        }
    }
}
void solve(string rule) {
    rz = rule.size();
    for(int i = 0;i < rz;i++){
        if(rule[i] == '#') ind[i] = 0; // words
        else if( rule[i] == '0') ind[i] = 1; //digit
    }
    dfs(0);
}
int main() {
    // INP;OUT;
    while(cin >> n) {
        for(int i = 0;i < n;i++)cin >> words[i];
        int r; cin >> r; string rules[r]; for(int i = 0;i < r;i++) cin >> rules[i];
        cout << "--" << endl;
        for(int i = 0;i < r;i++) solve(rules[i]);
    }
}