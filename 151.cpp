#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <list>
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
#define db pop_back
#define df pop_front
#define ff first
#define ss second
#define maxN 100010
#define INP freopen("i.txt","r",stdin)
#define OUT freopen("o.txt","w",stdout)
using namespace std;


int J(int n, int k) {
    queue<int> q;
    int res;
    for(int i = 1;i <= n;i++) q.push(i);
    while(!q.empty()) {
        res = q.front();
        q.pop();
        for(int i =0;i < k-1;i++) {
            q.push(q.front());
            q.pop();
        }
    }
    return res == 13;
}


int main() {
    int n;
    while(cin >> n && n) {
        for(int k = 1;;k++){
            if(J(n, k) == true) {
                cout << k << endl;
                break;
            }
        }
    }
}