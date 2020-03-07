#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v[201];
        //
        for(int i = 1;i <= n;i++){
            int p,x; cin >> p;
            while(p--){
                cin >> x;
                if(x > n)continue;
                v[x].push_back(i),v[i].push_back(x);
            }
        }
        int ans = 0;
        int color[201] = {0};
        for(int i = 1;i <= n;i++){
            if(color[i] == 0){
                bool ok = false;
                color[i] = 1;
                int tom = 1;
                int tom_jerry = 0;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    tom_jerry++;
                    int x = q.front();
                    q.pop();
                    for(int u : v[x]){
                        if(color[x] == color[u]) ok = true;
                        else if(color[u] == 0){
                            if(color[x] == 1)color[u] = 2;
                            else color[u] = 1,tom++;
                            q.push(u);
                        }
                    }
                }
                tom = max(tom,tom_jerry - tom);
                if(ok)tom = 0;
                ans+= tom;
            }
        }
        printf("%d\n",ans);
    }

}