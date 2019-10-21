#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,c = 1;
    while(cin >> n){
        if(n < 0)   return(0);

        int pr[12],pre[12];
        for(int i = 0;i < 12;i++)   cin >> pr[i];
        for(int i = 0;i < 12;i++)   cin >> pre[i];

        int tot = n;
        printf("Case %d:\n",c++);
        for(int i = 0;i < 12;i++){
            if(pre[i] <= tot){
                cout << "No problem!" << " :D\n";
                tot -= pre[i];
            }
            else{
                cout << "No problem!" << " :(\n";
            }

            if(i != 0){
                tot += pr[i-1];
            }
        }
    }
    return(0);
}