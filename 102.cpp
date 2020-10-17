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
int ans = 0xfffffff;
string ansS;
int main() {
    int a[9];
    while(scanf("%d%d%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8]) == 9){
        string s = "BCG";
        ans = 0xfffffff;
        do {
            int cnt = 0;
            for(int i = 0;i < s.size();i++){
                if(s[i] == 'B'){
                    cnt += a[0] + a[3] + a[6];
                    cnt -= a[i*3];
                }else if(s[i] == 'C'){
                    cnt += a[2] + a[5] + a[8];
                    cnt -= a[(i+1)*3 - 1];
                }else if(s[i] == 'G'){
                    cnt += a[1] + a[4] + a[7];
                    cnt -= a[(i+1)*3 - 2];
                }
            }
            if(cnt < ans){
                ansS = s;
                ans = cnt;
            }
        }while(next_permutation(s.begin(), s.end()));
        cout << ansS << " " << ans << endl;
    }
}