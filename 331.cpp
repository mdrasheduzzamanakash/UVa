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

int N;
int cnt[30];
bool isSorted(int a[]) {
    for(int i = 0;i < N-1;i++) {
        if(a[i] > a[i+1]) return false;
    }
    return true;
}
void dfs(int a[], int step) {
    if(isSorted(a)) {
        cnt[step]++;
    }
    for(int i = 0;i < N-1;i++) {
        if(a[i] <= a[i+1]) continue;
        int temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
        dfs(a, step+1);
        a[i+1] = a[i];
        a[i] = temp;
    }
}
int main(){
    // INP();OUT();
    int kse = 0;
    while(cin >> N && N) {
        for(int i = 0;i < 30;i++) cnt[i] = 0;
        int a[N];
        for(int i = 0;i < N;i++) cin >> a[i];
        dfs(a, 0);
        int i;
        for(i = 1;i < 30;i++) 
            if(cnt[i] != 0) {
                cout << "There are " << cnt[i] << " swap maps for input data set " << ++kse << "." << endl;
                break;
            }
        if(i == 30)  cout << "There are " << 0 << " swap maps for input data set " << ++kse << "." << endl;
    }
}