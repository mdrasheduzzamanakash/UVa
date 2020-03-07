#include <bits/stdc++.h>
using namespace std;
int h,w;
char pic[150][150];
int record[150];
int mvx[] = {0,0,1,-1};
int mvy[] = {1,-1,0,0};

bool dfs_dot(int x,int y){
    if(x < 0 || x >= h || y < 0 || y >= w || pic[x][y] != 'X'){
        return false;
    } // base con
    pic[x][y] = '*';
    for(int i = 0;i < 4;i++)
        dfs_dot(x+mvx[i] , y+mvy[i]);
    return true;
}

int dfs_dice(int x, int y){
    if(x < 0 || x >= h || y < 0 || y >= w || pic[x][y] == '.'){
        return 0;
    } // base con
    int rv = 0;
    if(dfs_dot(x,y))
        rv++;
    else 
        pic[x][y] = '.';
    for(int i = 0;i < 4;i++)
        rv += dfs_dice(x+mvx[i] , y+mvy[i]);
    return rv;
}

int main(){
    int kase = 0;
    while(cin >> w >> h && w && h){
        kase++;
        for(int i = 0;i < h;i++) 
            cin >> pic[i];
        // inp fin
        
        int ind = 0;
        for(int i = 0;i < h;i++)
            for(int j = 0;j < w;j++)
                if(pic[i][j] != '.')
                    if(int cnt = dfs_dice(i,j))
                        record[ind++] = cnt;
        sort(record,record+ind);
        cout << "Throw " << kase << endl;
        cout << record[0];
        for(int i = 1;i < ind;i++)
            cout << " " << record[i];
        cout << endl << endl;
    }    
}