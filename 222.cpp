#include <bits/stdc++.h>
using namespace std;
double tot, cap, mg, cost_o, N,chaBiscuit = 2.0;
double dist[100], price[100],mn;

void dfs(double cur, double cost, double left, int i) {
    if(i == N) {
        double rem = tot-cur;
        if(rem > left*mg) return;
        mn = min(cost,mn); return;
    }
    double rem = dist[i] - cur;
    if(rem > left*mg) return;
    left = left - (rem / mg);
    double add = 2 + round((cap-left)*price[i]) / 100;
    if(left <= cap/2) dfs(dist[i], cost+add,cap,i+1);
    dfs(dist[i],cost, left, i+1);
}


int main() {
    int kse = 1;
    while(cin >> tot && tot > 0) {
        mn = numeric_limits<double> :: max();
        cin >> cap >> mg >> cost_o >> N;
        for(int i = 0;i < N;i++) {
            cin >> dist[i] >> price[i] ;
        }
        dfs(0, cost_o, cap, 0);
        printf("Data Set #%d\n",kse++);
        printf("minimum cost = $%.2f\n",mn);
    }
}