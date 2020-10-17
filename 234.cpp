#include <bits/stdc++.h>
#define inf 0xfffffff
using namespace std;
int main() {
    int n,m,kase = 0;
    while(scanf("%d", &n) && n != 0) {
        int prog[10];
        for(int i = 0;i < n;i++)   cin >> prog[i];
        cin >> m;
        vector<pair<int, int>> align;
        for(int i = 0;i < m;i++) {
            int a, b;
            cin >> a >> b;
            align.push_back(make_pair(a, b));
        }
        sort(prog , prog+n);
        sort(align.begin(), align.end());
        int ansOrder[10];
        int ansLevel[10];
        for(int i = 0;i < 10;i++) ansLevel[i] = inf;
        do {
           int sum[10] = {};
           sum[0] = 0;
           for(int i = 0;i < n;i++) sum[i+1] = prog[i] + sum[i];
           int tempLevel[10] = {};
           int i, j;
           for(i = 0;i < m;i++) {
               for(j = 0;j <= n;j++) {
                   if(sum[j] >= align[i].second) break;
               }
               int dif = abs(sum[j] - align[i].second);
               if(j != 1) dif = min(dif, abs(sum[j-1] - align[i].second));
               tempLevel[align[i].first] += dif;
           }
           int flag = 0;
           for(int i = 0;i < 10;i++) {
               if (ansLevel[i] < tempLevel[i]) {
                   flag = 1;
                   break;
               }else if(ansLevel[i] > tempLevel[i]) {
                   flag = 2;
                   break;
               }
           }
           if(flag == 2) {
               for(int i = 0;i < 10;i++) ansLevel[i] = tempLevel[i];
               for(int i = 0;i < 10;i++) ansOrder[i] = prog[i];
           }
        }while(next_permutation(prog, prog+n));
        printf("Data set %d\n", ++kase);
        printf("Order:");
        for(int i = 0; i < n; i++)
            printf(" %d", ansOrder[i]);
        puts("");
        int err = 0;
        for(int i = 0; i < 10; i++)
            err += ansLevel[i];
        printf("Error: %d\n", err);
    }
}