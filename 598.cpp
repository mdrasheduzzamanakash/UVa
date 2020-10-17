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
#define INP() freopen("i.txt","r",stdin)
#define OUT() freopen("o.txt","w",stdout)
using namespace std;
string paper[20],line;
int n,a,b;

void backTrack(int size, int ind = 0,int start = 0, string ans = ""){
    if(ind == size){
        for(int i = start;i < n;i++) cout << ans << paper[i] << endl;
        return;
    }
    for(int i = start;i < n;i++){
        backTrack(size, ind+1, i+1 ,ans + paper[i] + ", ");
    }
}
int main() {
    int t; scanf("%d\n\n",&t);
    while(t--) {
        getline(cin, line);
        if(line != "*") {
            if(sscanf(line.c_str(), "%d %d\n", &a, &b) == 1)
                b = a;
        } else a = 0, b = 0;
 
        for(int i = 0;; i++) {
            n = i;
            getline(cin, line);
            if(line.length() == 0) break;
            paper[i] = line;
        }
     
        if(a == 0 && b == 0) a = 1, b = n;
        if(a != 0 && b == 0) b = a;
        for(int i = a-1;i < b;i++) {
            cout << "Size " << i+1 << endl;
            backTrack(i);
            cout << endl;
        }
        if(t) cout << endl;
    }
}