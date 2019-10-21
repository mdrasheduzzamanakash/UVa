#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    int n,m,tot = 0;  cin >> n;

    while (n--)
    {
        cin >> s;
        if(s[0] == 'd'){
            cin >> m;
            tot += m;
        }
        else cout << tot << endl;
    }
    return 0;
    
}