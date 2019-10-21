#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;   int g;
    while (cin >> g && g)
    {
        cin >> s;
        int l = s.length();
        for(int i = 0;i < l ;i += (l/g)){
            string ts;
            ts = s.substr(i,l/g);
            reverse(ts.begin(),ts.end());
            cout << ts;
        }
        cout << endl;
    }
    
}