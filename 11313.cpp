#include <bits/stdc++.h>
using namespace std;




int main() {
    int T;
    cin >> T;
    while(T--){
        int a,b,cnt = 0;
        cin >> a >> b;
        while(a/b){
            cnt += a / b;
            int r = a % b;
            a = r + (a/b);
        }
        if(a == 1 && cnt != 0){
            cout << cnt << endl;
        }else {
            cout << "cannot do this" << endl;
        }
    }
    return 0;
}