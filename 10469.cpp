#include <bits/stdc++.h>
using namespace std;

int main() {
    //      freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    string f,s,ans;
    long long a,b;
    while(cin >> a >> b){
        s = f = ans = "";
        while(a){
            long long t = a%2;
            a /= 2;
            f += (t+'0');
        }
        while(b){
            long long t = b%2;
            b /= 2;
            s += (t+'0');
        }
        reverse(f.begin(),f.end()); reverse(s.begin(),s.end());
        // cout << f << " " << s << endl;
        long long  lf =100 - f.size();
        long long  ls =100 - s.size();
        while(lf--){
            f = "0"+f;
        }
        while(ls--){
            s = "0"+s;
        }
        // cout << f << " " << s << endl;
        for(long long i = 0;i < 100;i++){
            if(f[i] != s[i]){
                ans += "1";
            }else {
                ans += "0";
            }
        }
        // cout << ans << endl;
        reverse(ans.begin(),ans.end());
        long long v = 0;
        for(long long i = 0;i < 100;i++){
            v += (ans[i]-'0')*pow(2,i);
        }
        cout << v << endl;
    }
}