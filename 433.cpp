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
int T,cnt = 0;
bool flip = false;
string digits[10] = {"010101111","000001001","010011110","010011011","000111001","010110011","010110111","010001001","010111111","010111011"};
string ans;
bool check(string temp, int i){
    temp = temp.substr(0,i) + '1' + temp.substr(i+1);
    for(int i = 0;i < 10;i++) 
        if(digits[i] == temp)
            return true;
    return false;
} 

int getDigit(string temp){
    for(int i = 0;i < 10;i++) 
        if(temp == digits[i])
            return i;
    return 0;
}

bool isValid(string inpS[]){
    long long val = 0;
    for(int i = 0;i < 9;i++) {
        int d = getDigit(inpS[8-i]);
        val += d * (i+1);
    }
    return val%11 == 0 ? true : false;
}

void dfs(int pos,string inpS[]) {
    if(isValid(inpS)){
        if(cnt == 0)
            for(int i = 0;i < 9;i++) 
                ans += getDigit(inpS[i])+'0';
        cnt++;
    }
    if(flip) return;
    string temp = inpS[pos];
    for(int i = 0;i < 9;i++) {
        if(inpS[pos][i] == '0'){
            if(check(inpS[pos],i)){ // purning one
                flip = true;
                inpS[pos] = inpS[pos].substr(0,i)+'1'+inpS[pos].substr(i+1);
                dfs(pos+1,inpS);
                flip = false;
                inpS[pos] = temp;
                dfs(pos+1,inpS);
            }
        }
    }
}

int main() {
    // INP();OUT();
    cin >> T;
    cin.ignore();
    for(int kse = 0;kse < T;kse++) {
        cnt = 0;
        ans = "";
        char a[27];
        string inpS[9];
        for(int k = 0;k < 3;k++){
            gets(a);
            for(int i = 0;i < 27;i++) {
                inpS[i/3] += a[i] != ' ' ? "1" : "0";
            }
        }
        dfs(0,inpS);
        if(cnt == 0) cout << "failure" << endl;
        else if(cnt == 1) cout << ans << endl;
        else cout << "ambiguous" << endl;
    }
}
