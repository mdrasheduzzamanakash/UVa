#include <bits/stdc++.h>
using namespace std;

struct edge{
    int x,y;
    double dis;
    bool operator < (edge const &o){
        return this->dis < o.dis;
    }
};
struct pos{
    double x,y;
};

int Rank[100],Parent[100];

void Make_set(int n){
    for(int i = 0;i < n;i++)
        Rank[i] = 0,Parent[i] = i;
}

int FindParent(int x) {
	if(Parent[x] != x)
		Parent[x] = FindParent(Parent[x]);
	return Parent[x];
}

int Union(int x, int y){
    x = FindParent(x);
    y = FindParent(y);
    if(x != y){
        if(Rank[x] < Rank[y])
            swap(x,y);
        Parent[y] = x;
        if(Rank[x] == Rank[y])
            Rank[x]++;
        return 1;
    }
    return 0;
}

int main() {
    //             freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        pos point[n];
        edge list[n*n+1];
        for(int i = 0;i < n;i++){
            cin >> point[i].x >> point[i].y;
        }
        //
        int idx = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j) continue;
                list[idx].x = i,list[idx].y = j;
                double a = point[i].x - point[j].x;
                double b = point[i].y - point[j].y;
                list[idx].dis = sqrt(a*a + b*b);
                idx++;
            }
        }

        sort(list,list+idx);
        // for(int i = 0;i < idx;i++){
        //     cout << list[i].x << " " << list[i].y << " " << list[i].dis << endl;
        // }
        
        double cost = 0;
        Make_set(n);
        for(int i = 0;i < idx;i++){
            cost += Union(list[i].x, list[i].y) * list[i].dis;
        }
        printf("%.2lf\n",cost);
        if(T) cout << endl;
    }
}