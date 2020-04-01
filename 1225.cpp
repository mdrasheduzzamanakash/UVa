#include<bits/stdc++.h>
using namespace std;

int main() {

    //  freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int a[10] = {0};
        for(int i = 1;i <= n;i++){
            int temp = i;
            while(temp){
                a[temp%10]++;
                temp /= 10;
            }
        }
        cout << a[0];
        for(int i = 1;i < 10;i++){
            cout << " " << a[i];
        }
        cout << endl;
    }
}