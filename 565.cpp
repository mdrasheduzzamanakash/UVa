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
#include <cstring>
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
#define IO freopen("i.txt","r",stdin);freopen("o.txt","w",stdout)
using namespace std;
int px[] = {0,-1,-1,-1,0,1,1,1};
int py[] = {1,1,0,-1,-1,-1,0,1};

char cond[20][50];
int n;
int taken[20];
char ans[20];
int id;
bool flag = false;
bool dfs(int n, int cur, int idx) {
    if(cur == n) {
        id = idx;
        flag = true;
        return true;
    }
    if(flag == true) return true;
    for(int i = 0;i < strlen(cond[cur]);i+=2){
        if(cond[cur][i] == '+'){
            if(taken[cond[cur][i+1] - 'A'] == 1){
                if(dfs(n, cur+1,idx))return true;
            }
            else if(taken[cond[cur][i+1] - 'A'] == 0) {
                taken[cond[cur][i+1] - 'A'] = 1;
                ans[idx] = cond[cur][i+1];
                if(dfs(n, cur+1,idx+1)) return true;
                taken[cond[cur][i+1] - 'A'] = 0;
            }else continue;
        }else if(cond[cur][i] == '-'){
            if(taken[cond[cur][i+1] - 'A'] == -1) {
                if(dfs(n, cur+1,idx)) return true;
            }
            else if(taken[cond[cur][i+1] - 'A'] == 0) {
                taken[cond[cur][i+1] - 'A'] = -1;
                ans[idx] = cond[cur][i+1];
                if(dfs(n, cur+1,idx+1)) return true;
                taken[cond[cur][i+1] - 'A'] = 0;
            }else continue;
        }
    }
    return false;
}
int main() {
    // IO;
    n = 0;
    while(cin >> cond[n++]){
        flag = false;
        if(cond[n-1][0] == '.'){
            n--;
            for(int i = 0;i < 20;i++)
                taken[i] = 0;
            if(dfs(n, 0, 0)){
                cout << "Toppings: ";
                sort(ans, ans+id);
                for(int i = 0;i < id;i++) cout << ans[i];
                cout << endl;
            }else {
                cout << "No pizza can satisfy these requests." << endl;
            }
            n = 0;
        }
    }
}