#include <bits/stdc++.h>
using namespace std;

int kadany(int kd_a[],int n){
    int max_so_far = -1,temp_max = 0;
    for(int i = 0;i < n;i++){
        temp_max += kd_a[i];
        if(temp_max > max_so_far)max_so_far = temp_max;

        if(temp_max < 0)temp_max = 0;
    }

    return max_so_far;
}



int main(){
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> a[i][j];
        }
    }

    //solve

    int sum = INT32_MIN;
    int temp = 0;
    int l = 0,r = 0;

    
    for(l = 0;l < n;l++){
        int kd_a[n] = {0};
        for(r = l;r < n;r++){
            
            for(int ind = 0;ind < n;ind++){
                kd_a[ind] += a[ind][r];
            }

            int rv = kadany(kd_a,n);

            if(rv > sum)sum = rv;
        }
    }

    cout << sum << endl;
}