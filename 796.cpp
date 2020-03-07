#include <bits/stdc++.h>
using namespace std;

int graph[100][100];
int visit[100];
int depth[100];
int cutBridge[100][100];
int n;

int findBridge(int node, int d, int parent){
    depth[node] = d;
    int back = 1000;
    for(int i = 0;i < n;i++){
        if(graph[node][i] == 1){
            if(visit[i] == 0){
                visit[i] = 1;
                int temp = findBridge(i, d+1, node);
                if(temp > d){
                    cutBridge[node][i] = 1;
                    cutBridge[i][node] = 1;
                }
                back = min(back, temp);
            } else{
                if(parent != i){
                    back = min(back, depth[i]);
                }
            }
        }
    }
    return back;
}

int main(){
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    while(cin >> n){
        memset(graph,0,sizeof(graph));
        memset(visit,0,sizeof visit);
        memset(depth,0,sizeof depth);
        memset(cutBridge,0,sizeof cutBridge);

        int i,x,y,m;
        for(i = 0; i < n; i++) {
			scanf("%d ", &x);
			scanf("(%d)", &m);
			while(m--) {
				scanf("%d", &y);
				graph[x][y] = 1;
				graph[y][x] = 1;
			}
		}

        for(int i = 0;i < n;i++){
            if(visit[i] == 0){
                visit[i] = 1;
                findBridge(i,1,-1);
            }
        }

        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(cutBridge[i][j] == 1)
                    ans++;
            }
        }
        printf("%d critical links\n", ans);
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(cutBridge[i][j] == 1)
                    printf("%d - %d\n", i, j);
            }
        }
        cout << endl;
    }
    return 0;
}