#include <bits/stdc++.h>
using namespace std;


int main(){
    string ss;
    while(cin >> ss){
        if(ss[0] == '-')break;
        if(ss[1] == '\0'){
            cout << 1 << ss << endl;
            continue;
        }


        int sz=ss.size() - 1,start = 0;
        int s[sz];
        for(int i = 0 ;i <= sz;i++)s[i]=ss[i]-'0';
        vector<int>ans;


        for(int i = 9;i >= 2;i--){
            while(1){
                int mod = 0;
                for(int j = start;j <= sz;j++){
                    mod = mod*10 + s[j];
                    mod = mod % i;
                }


                if(mod == 0){
                    ans.push_back(i);
                    for(int j = start;j <= sz;j++){
                        mod = mod*10 + s[j];
                        s[j] = mod / i;
                        mod %= i;
                    }
                    while(s[start] == 0)start++;
                }
                else break;
            }
        }

        if(start = sz && s[sz] == 1){
            for(int i = ans.size()-1; i >= 0;i--)cout << ans[i];
            cout << endl;
        }else cout << "There is no such number." << endl;

    }
}