#include <bits/stdc++.h>
using namespace std;
int px[100010],py[100010];
void com(){
    px[1]=py[1]=0;
    int idx=2;
    for(int i=1;idx<100010;i++){
        px[idx] = px[idx-1], py[idx] = py[idx-1]+1;
        idx++;
        for(int j = 1; j < i && idx < 100010; j++, idx++)
            px[idx] = px[idx-1]-1, py[idx] = py[idx-1]+1;

        px[idx] = px[idx-1]-1, py[idx] = py[idx-1];
        idx++;
        for(int j = 1; j < i && idx < 100010; j++, idx++)
            px[idx] = px[idx-1]-1, py[idx] = py[idx-1];

        px[idx] = px[idx-1], py[idx] = py[idx-1]-1;
        idx++;
        for(int j = 1; j < i && idx < 100010; j++, idx++)
            px[idx] = px[idx-1], py[idx] = py[idx-1]-1;

        px[idx] = px[idx-1]+1, py[idx] = py[idx-1]-1;
        idx++;
        for(int j = 1; j < i && idx < 100010; j++, idx++)
            px[idx] = px[idx-1]+1, py[idx] = py[idx-1]-1;

        px[idx] = px[idx-1]+1, py[idx] = py[idx-1];
        idx++;
        for(int j = 1; j < i && idx < 100010; j++, idx++)
            px[idx] = px[idx-1]+1, py[idx] = py[idx-1];

        px[idx] = px[idx-1], py[idx] = py[idx-1]+1;
        idx++;
        for(int j = 1; j < i && idx < 100010; j++, idx++)
            px[idx] = px[idx-1], py[idx] = py[idx-1]+1;

    }
}


int main() {
    com();
    int n;
    while(scanf("%d",&n)==1){
        cout << px[n] << " " << py[n] << endl;
    }
}