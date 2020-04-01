#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    while(cin >>n && n){
        if(n%2 != 0 || n < 4){
            cout << "Impossible" << endl;
            continue;
        }
        int edges=(n*3)/2;
        cout << edges << endl;
        for(int i = 1;i <= n;i++){
            if(i != n){
                cout << i << " " << i+1 << endl;
            }else{
                cout << n << " " << 1 << endl;
            }
        }
        int mid = n/2+1;
        for(int i=1;i <= n/2;i++){
            cout << i << " " << mid << endl;
            mid++;
        }
    }
}