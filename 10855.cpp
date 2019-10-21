#include <bits/stdc++.h>
using namespace std;

char large[1000][1000],small[10000][1000];



void rotate(int n){
    int j,k;
            char temp[n][n];
            for(j = 0;j < n;j++){
                for(k = 0;k < n;k++){
                    temp[j][k] = small[n-k-1][j];
                }
            }

            for(j = 0;j < n;j++){
                for(k = 0;k < n;k++){
                    small[j][k] = temp[j][k];
                }
            }
}

int search(int N,int n){
    int ans = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            

            if(i+n <= N && j+n <= N){

                int cnt = 0;
                for(int k = 0;k < n;k++)
                    for(int l = 0;l < n;l++)
                        if(small[k][l] == large[i+k][j+l])
                            cnt++;

                if(cnt == n*n)
                    ans++;
            }
        }
    }
    return ans;
}

int main(){
    int N,n;
    while((cin >> N >> n)){
        if(!N || !n)return 0;
        int i,j,k,l;
        for(i = 0;i < N;i++)    cin >> large[i];
        for(i = 0;i < n;i++)    cin >> small[i];

        for(i = 0;i < 4;i++){
            if(i != 0)  putchar(' ');
            int match = search(N,n);
            cout << match;
            rotate(n);
        }
        cout << endl;
    }
}