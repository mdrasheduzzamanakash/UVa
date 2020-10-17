#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
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
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define maxN 100010
#define INP freopen("i.txt","r",stdin)
#define OUT freopen("o.txt","w",stdout)
using namespace std;
int Shift(int *circle, int pos, int n, int k, int d) {
    while(k--) {
        pos = (pos + d + n) % n;
        while(circle[pos] == 0) {
            pos = (pos+d+n) % n;
        }
    }
    return pos;
}
int main() {
    int n, k, m;
    while(cin >> n >> k >> m  && (n || k || m)){
        int *circle = new int[n];
        for(int i = 0;i < n;i++) {
            circle[i] = i+1;
        }
        int i = -1, j = n, left = n,comma = 0;
        while(left != 0) {
            if(comma > 0) cout << ",";
            i = Shift(circle , i, n, k, 1);
            j = Shift(circle , j, n, m, -1);
            if(i != j) {
                left = left - 2;
                cout << setw(3) << circle[i] << setw(3) << circle[j];
                circle[i] = circle[j] = 0;
            }else {
                left = left - 1;
                cout << setw(3) << circle[i];
                circle[i] = 0;
            }
            comma++;
        }
        cout << endl;
        delete [] circle;
    }
    return 0;
}