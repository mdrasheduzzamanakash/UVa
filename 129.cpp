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
int px[] = {0,-1,-1,-1,0,1,1,1};
int py[] = {1,1,0,-1,-1,-1,0,1};

int n, L;
string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int cnt = 0;
char word[100];

bool isValid(int len){
    for(int pLen = 1;pLen <= len/2;pLen++) {
        bool flag = false;
        for(int i = 0;i < pLen;i++) {
            if(word[len-1-i] != word[len-1-pLen-i]){
                flag = true;
                break;
            }
        }
        if(flag == false){
            return false;
        }
    }
    return true;
}


bool dfs(int pos) {
    if(isValid(pos) == false) return false;
    if(cnt == n) {
        word[pos] = 0;
        for(int i = 0;i < pos;i++) {
            if(i && i % 4 == 0){
                putchar(i%64 == 0 ? '\n' : ' ');
            }
            cout << word[i];
        }
        cout << endl;
        cout << pos << endl;
        return true;
    }
    cnt++;
    for(int l = 0;l <  L;l++) {
        word[pos] = letters[l];
        if(dfs(pos+1) == true) return true;
    }
    return false;
}

int main() {
    // INP();OUT();
    while(cin >> n >> L && (n || L)) {
        dfs(0);
        cnt = 0;
    }
}