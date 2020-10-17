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
int A, B, target;
bool state[1500][1500],flag;

void bfs() {
    queue<pair<pair<int, int> , vector<string>>> flower;
    flower.push(make_pair(make_pair(0,0), vector<string>(0)));

    while(!flower.empty()) {
        int a = flower.front().ff.ff;
        int b = flower.front().ff.ss;
        if(b == target && flag) {
            flag = false;
            for(string i : flower.front().ss) {
                cout << i << endl;
            }
            cout << "success" << endl;
        }
        if(a != A && flag) {
            if(!state[A][b]) {
                state[A][b] = true;
                flower.front().ss.push_back("fill A");
                flower.push(make_pair(make_pair(A, b), flower.front().ss));
                flower.front().ss.pop_back();
            }
            int ta = (a+b) <= A ? a+b : A;
            int tb = b - ta + a;
            if(!state[ta][tb] && flag) {
                state[ta][tb] = true;
                flower.front().ss.push_back("pour B A");
                flower.push(make_pair(make_pair(ta, tb), flower.front().ss));
                flower.front().ss.pop_back();
            }
        }
        if(b != B && flag) {
            if(!state[B][a] && flag) {
                state[B][a] = true;
                flower.front().ss.push_back("fill B");
                flower.push(make_pair(make_pair(a, B), flower.front().ss));
                flower.front().ss.pop_back();
            }
            int tb = (a+b) <= B ? a+b : B;
            int ta = a - tb + b;
            if(!state[ta][tb] && flag) {
                state[ta][tb] = true;
                flower.front().ss.push_back("pour A B");
                flower.push(make_pair(make_pair(ta, tb), flower.front().ss));
                flower.front().ss.pop_back();
            }
        }
        if(a != 0 && !state[0][b] && flag) {
            state[0][b] = true;
            flower.front().ss.push_back("empty A");
            flower.push(make_pair(make_pair(0, b), flower.front().ss));
            flower.front().ss.pop_back();
        }
        if(b != 0 && !state[a][0] && flag) {
            state[a][0] = true;
            flower.front().ss.push_back("empty B");
            flower.push(make_pair(make_pair(a, 0), flower.front().ss));
            flower.front().ss.pop_back();
        }
        flower.pop();
    }
}
int main() {
    while(cin >> A >> B >> target) {
        flag = true;
        for(int i = 0; i < 1500;i++) for(int j = 0; j < 1500;j++) state[i][j] = false;
        bfs();
    }
}