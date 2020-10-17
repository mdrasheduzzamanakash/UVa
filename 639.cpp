#include <bits/stdc++.h>
using namespace std;

char board[5][5];
int n;

bool check(int r, int c) {
    bool flag = true;
    for(int i = r;i >= 0 && flag;i--) {
        if(board[i][c] == 'X')break;
        else if(board[i][c] == 'O') flag = false;
    }
    for(int i = r;i < n && flag;i++) {
        if(board[i][c] == 'X') break;
        else if(board[i][c] == 'O') flag = false;
    }
    for(int i = c;i >= 0 && flag ;i--) {
        if(board[r][i] == 'X') break;
        else if(board[r][i] == 'O') flag = false;
    }
    for(int i = c;i < n && flag;i++) {
        if(board[r][i] == 'X') break;
        else if(board[r][i] == 'O') flag = false;
    }
    return flag;
}

int func(int t) {
    int r = t;
    for(int i = 0 ; i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(board[i][j] == '.') {
                if(check(i, j)){
                    board[i][j] = 'O';
                    int num = func(t+1);
                    if(num > r) r = num;
                    board[i][j] = '.';
                }
            }
        }
    }
    return r;
}


int main() {
    while(cin >> n && n) {
        for(int i = 0;i < n;i++) cin >> board[i];
        int ans = func(0);
        cout << ans << endl;
    }
}