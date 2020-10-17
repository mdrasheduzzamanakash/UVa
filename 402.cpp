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
#include <sstream>
#include <string>
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

int main() {
    int N, X,kse=1;
    string s;
    while(getline(cin, s)) {
        stringstream sss(s);
        int N,NN,XX;
        sss >> N >> X;
        NN = N;
        XX=N;
        int *line = new int[N];
        for(int i = 0;i < N;i++) line[i] = i+1;

        int k;
        while(sss >> k) {
            int pos = 0,cnt = 0;
            while(XX != X) {
                if(pos >= N)break;
                if(line[pos] != 0)cnt++;
                if(cnt == k){
                    line[pos] = 0;
                    XX--;
                    cnt = 0;
                }
                ++pos;
            }
        }
        printf("Selection #%d\n",kse++);
        bool flag = false;
        for(int i = 0;i < NN;i++){
            if(line[i] != 0){
                if(flag)cout << " ";
                cout << line[i];
                flag = true;
            }
        }
        cout << endl << endl;
    }
}