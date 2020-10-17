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
#include <list>
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
list<int> :: iterator makeAdvance(list<int> :: iterator f, int dist, list<int> &circle) {
    while(dist--) {
        f++;
        if(f == circle.end())f = circle.begin();
    }
    return f;
}
int startFrom(int start, int n, int k , list<int> circle) {
    list<int> :: iterator i,j;
    i = circle.begin();
    i = makeAdvance(i, start-1, circle);
    bool starting = true;
    while(circle.size() > 1) {
        i = makeAdvance(i,(starting?k-1:k), circle);
        starting = false;
        i = circle.erase(i);
        if(i == circle.end()) i = circle.begin();
        j = makeAdvance(i, k-1, circle);
        i = circle.insert(i, *j);
        circle.erase(j);
    }
    return circle.front();
}
int main() {
    int n, k;
    while(cin >> n >> k && (n || k)) {
        list<int> circle;
        for(int i = 1;i <= n;circle.push_back(i++));
        for(int start = 1;start <= n;start++) {
            if(startFrom(start, n, k, circle) == 1) {
                cout << start << endl;
                break;
            }
        }
    }
}