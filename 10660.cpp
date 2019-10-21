#include<bits/stdc++.h>
using namespace std;
int area[5][5];
int output[5];
int temp_off[5];
int ans = INT32_MAX;

int backtrack(int pos,int b){
    if(b >= 5){
        int sum = 0,mn = 120000;
        for(int r = 0;r < 5;r++){
            for(int c = 0;c < 5;c++){
                int temp;
                for(int i = 0;i < 5;i++){
                    temp = area[r][c]*(abs(temp_off[i]/5-r)+abs(temp_off[i]%5-c));
                    if(temp < mn)
                        mn = temp;
                }
                sum += mn;
            }
        }
        if(ans > sum){
            ans = sum;
            for(int i = 0;i < 5;i++)
                output[i]=temp_off[i];
        }
        return(0);

    }
    for(int i = pos;i < 25;i++){
        temp_off[pos] = i;
        backtrack(pos+1,b+1);
    }
    return(0);
}



int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        for(int i = 0;i < 5;i++)
            for(int j = 0;j < 5;j++)
                area[i][j]=0;
        
        int n,a,b,c;    cin >> n;
        for(int i = 0;i < n;i++){
            scanf("%d%d%d",&a,&b,&c);
            area[a][b]=c;
        }
        ans = INT32_MAX;
        backtrack(0,0);
        printf("%d",output[0]);
        for(int i = 1;i < 5;i++)
            printf(" %d",output[i]);
        printf("\n");
        return(0);
    }
}