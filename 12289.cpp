#include <bits/stdc++.h>

using namespace std;





int main(){
    int n;
        cin >> n;
    while (n--)
    {
        int one = 0,two = 0;
        string s;   cin >> s;
        if(s.size() == 5)cout << 3 << endl;
        else{
            if((s[0] == 'o' && s[1] == 'n')||
                (s[0] == 'o' && s[2] == 'e')||
                (s[1] == 'n' && s[0] == 'o')||
                (s[1] == 'n' && s[2] == 'e')||
                (s[2] == 'e' && s[1] == 'n')||
                (s[2] == 'e' && s[0] == 'o')
                )
            cout << 1 << endl;
            else cout << 2 << endl;
        }   
    }
    return 0;
    
}