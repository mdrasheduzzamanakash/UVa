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
#define mp make_pair
#define ff first
#define ss second
#define maxN 100010
using namespace std;

int64 limit = 9876543210LL;
bool isOK(int64 n) {
    int digit[10] = {0};
    while(n) {
        int d = n % 10;
        digit[d]++;
        if(digit[d] == 2) return false;
        n /= 10;
    }
    return true;
}
int main() {
    int kse;
    cin >> kse;
    while(kse--) {
        int64 n;
        cin >> n;
        for(int64 m = 1;m*n <= limit;m++){
            int64 temp = m*n;
            if(isOK(temp) && isOK(m)){
                cout << temp << " / " << m << " = " << n << endl;
            }
        }
        if(kse) cout << endl;
    }
}