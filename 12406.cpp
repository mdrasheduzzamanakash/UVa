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
#define INF 33333333333333333
using namespace std;

int p, q;
int64 val, mn = INF, mx = 0;
int digit[20];
int64 getInt(int n, int64 temp = 0)
{
    for (int i = 0; i <= n; i++)
    {
        temp *= 10;
        temp += digit[i];
    }
    return temp;
}
void backTracking(int i)
{
    if (i == p)
    {
        int64 temp = getInt(i-1);
        if (temp % val == 0)
        {
            mx = max(mx, temp);
            mn = min(mn, temp);
        }
        return;
    }
    digit[i] = 1;
    backTracking(i + 1);
    digit[i] = 2;
    backTracking(i + 1);
}
int main()
{
    int kase;
    cin >> kase;
    for (int kse = 1; kse <= kase; kse++)
    {
        cin >> p >> q;
        val = pow(2, q);
        mn = INF, mx = 0;
        backTracking(0);
        cout << "Case " << kse << ":";
        if (mx == 0 && mn == INF)
        {
            cout << " impossible" << endl;
            continue;
        }
        if (mn != INF)
            cout << " " << mn;
        if (mx != 0 && mn != mx)
            cout << " " << mx;
        cout << endl;
    }
}