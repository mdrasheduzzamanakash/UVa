#include <bits/stdc++.h>
using namespace std;
int p[30],r[30];

void init(int n){
    for(int i = 0;i <= n;i++){
        p[i] = i;
    }
}

int Find(int x){
    return p[x] == x ? x : (p[x] = Find(p[x]));
}

int Union(int x,int y){
    x = Find(x);
    y = Find(y);

    if(x != y){
        if(r[x] > r[y]){
            r[x] += r[y];
            p[y] = x;
        }else {
            r[y] += r[x];
            p[x] = y;
        }
        return 1;
    }
    else
        return 0;
}



int main(){
    cout << "adsfa";
    int t;
    char s[10];
    cin >> t;

    while(t--){
        gets(s);
        init(s[0]-'A');

        int ans = s[0] - 'A' + 1;
        while(gets(s) && strlen(s)){
            ans = ans - Union(s[0]-'A',s[1]-'A');
        }

        cout << ans << endl;
        if(t)
        cout << endl;
    }
}
