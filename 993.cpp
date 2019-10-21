#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    while(n--){
        
        vector<int>v;
        long long x;
        cin >> x;
        if(x <= 9){
            cout << x << endl;
            continue;
        }
        bool f = true;
        while(x > 1 && f){
            for(int i = 9;i >= 2;i--){
                if(x % i == 0){
                    v.push_back(i);
                    x /= i;
                    f = false;
                    break;
                }
            }
            if(!f)f = true;
            else f = false;
        }
        if(x != 1){
            cout << "-1" << endl;
            continue;
        }

        sort(v.begin(),v.end());
        for(int i = 0;i < v.size();i++){
            cout << v[i];
        }
        // cout << endl;
    }
}