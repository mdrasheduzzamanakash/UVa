#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x,y;
};

int main() {
    //          freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int T;
    cin >> T;
    for(int kse =1;kse <= T;kse++){
        int n;
        cin >> n;
        point pos[n];
        double g[n][n];
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j)g[i][j] = 0;
                else g[i][j] = 0xfffffff;
            }
        }
        for(int i = 0;i < n;i++)
            cin >> pos[i].x >> pos[i].y;

        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                double x = pos[i].x - pos[j].x;
                double y = pos[i].y - pos[j].y;
                double dis = sqrt(x*x + y*y);
                if(dis <= 10)
                    g[i][j] = g[j][i] = dis;
            }
        }

        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }

        double ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++)
                ans = max(ans , g[i][j]);
        }

        printf("Case #%d:\n", kse);
        if(ans == 0xfffffff){
             cout << "Send Kurdy" << endl;
        }
        else 
            printf("%.4lf\n", ans);

        cout << endl;
    }
}