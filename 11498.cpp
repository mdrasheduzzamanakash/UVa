#include <bits/stdc++.h>
using namespace std;




int main(){
    for(;;){
        int t,n,m; cin >> t;
        if(t == 0)break;
        cin >> n >> m;

        for(int i = 0;i < t;i++){
            int x,y;    cin >> x >> y;

            
            if(x == n || y == m)        cout << "divisa\n";
            else if(x > n && y > m)     cout << "NE\n";
            else if(x < n && y > m)     cout << "NO\n";
            else if(x > n && y < m)     cout << "SE\n";
            else                        cout << "SO\n";
        }
    }
    return 0;
}