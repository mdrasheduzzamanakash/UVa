#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    string s;
    while(cin >> n && n){
        cin >> ws;
        if(n == 1){
            getline(cin,s);
            cout << 0 << "\n";
            continue;
        }

        int d[10000],cnt = 0,mn = INT_MAX;

        for(int i = 0;i < n;i++){
            getline(cin,s);
            int k = 0;
            for(int j = 0;j < s.size();j++){
                if(s[j] == ' '){cnt++;k++;}
                else if(k != 0 && s[j] == 'X')
                    break;
            }
            if(mn > k)mn = k;
        }

        cout << cnt - (mn*n) << endl;

    }
}
