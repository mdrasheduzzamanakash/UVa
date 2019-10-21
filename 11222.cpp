#include <bits/stdc++.h>
using namespace std;



int main(){
    int t;  cin >> t;
    for(int tc = 1;tc <= t;tc++){



        int v[3],problem[3][1010],mark[10010] = {0};
        for(int i = 0;i < 3;i++){
            cin >> v[i];
            for(int j = 0;j < v[i];j++){
                cin >> problem[i][j];
                mark[problem[i][j]]++;
            }
            sort(problem[i],problem[i] + v[i]);
        }

        int s[3];
        int mx = 0;
        for(int i = 0;i < 3;i++){
            int tmp = 0;
            for(int j = 0;j < v[i];j++){
                if(mark[problem[i][j]] == 1){
                    tmp++;
                }
            }
            if(tmp > mx)mx = tmp;
            s[i] = tmp;

        }
        printf("Case #%d:\n", tc);
        for(int i = 0;i < 3;i++){
            if(s[i] == mx){
                printf("%d %d",i+1,s[i]);
                for(int j = 0;j < v[i];j++){
                    if(mark[problem[i][j]] == 1)
                        printf(" %d",problem[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}