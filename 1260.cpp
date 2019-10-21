#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;  cin >> t;
    int a[10000];
    while(t--){
        int n;  cin >> n;
        for(int i = 0;i < n;i++)
            cin >> a[i];
        
        int tot = 0;
        for(int i = 1;i < n;i++){
            for(int j = 0;j < i;j++){
                if(a[j] <= a[i])
                    tot ++;
            }
        }
        cout << tot << endl;
    }
}