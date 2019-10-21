#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    while(cin >> n && n){
        int a[n];
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }

        int max_sofar = 0,tem_max = 0;
        for(int i = 0;i < n;i++){
            tem_max += a[i];
            if(tem_max > max_sofar)max_sofar = tem_max;
            if(tem_max < 0)tem_max = 0;
        }

        if(max_sofar != 0)
            printf("The maximum winning streak is %d.\n", max_sofar);
        else
            cout << "Losing streak.\n";
    }
}