#include <bits/stdc++.h>
using namespace std;

int main(){
    int fs,rs;
    while(cin >> fs && fs){
        cin >> rs;
        int ft[1000],rt[1000];
        double drive_ratio[1000];

        for(int i = 0;i < fs;i++)   cin >> ft[i];
        for(int i = 0;i < rs;i++)   cin >> rt[i];

        int idx = 0;
        for(int i = 0;i < rs;i++){
            for(int j = 0;j < fs;j++){
                // double t = (double)(rt[i]/ft[j]);
                drive_ratio[idx] = (double)rt[i]/(double)ft[j];
                idx++;
            }
        }


        sort(drive_ratio,drive_ratio+idx);

        double mx = -1;
        for(int i = 0;i < idx-1;i++){
            mx = max(mx,drive_ratio[i+1]/drive_ratio[i]);
        }

        printf("%.2lf\n",mx);
    }
    return 0;
}