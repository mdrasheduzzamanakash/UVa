#include <bits/stdc++.h>
using namespace std;
int n;
char a[250][250];
bool blk;

void inp(){
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        for(int j = 0;j < n;j++){
            a[i][j] = s[j];
        }
    }
}

void dfs(int i,int j){
    if(!blk && i >= 0 && i < n && j >= 0 && j < n && a[i][j] == 'b'){
        if(i == n-1)    blk = true;
        a[i][j] = 'g';
        dfs(i-1,j-1);
        dfs(i-1,j);
        dfs(i,j-1);
        dfs(i,j+1);
        dfs(i+1,j);
        dfs(i+1,j+1);
    }
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int kse = 0;
    while(cin >> n && n){
        blk = false;
        kse++;
        inp();
        // for black join row 1,n
        for(int i = 0;i < n;i++){
            if(a[0][i] == 'b')
                dfs(0,i);
        }
        cout << kse << " ";
        blk ? cout << "B\n" : cout << "W\n";   
    }
    return 0;
}