#include <bits/stdc++.h>
using namespace std;




int main(){
//     freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    string s;
    while(cin >> s && s!="0"){
        int len  = s.length();
        int num = s[0]-'0';
        if(len == 1){
            int ans = sqrt(num);
            cout << ans << endl;
            continue;
        }
        if(len%2 == 0){
            len = len/2 - 1;
            num = num*10 + (s[1]-'0');
            cout << (int)sqrt(num);
            for(int i = 0;i < len;i++) cout << "0";
            cout << endl;
        }else{
            len = (len/2);
            cout << (int)sqrt(num);
            for(int i = 0;i < len;i++) cout << "0";
            cout << endl;
        }
    }
}