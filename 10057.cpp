#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    while(cin >> n){
        int a[n];
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        sort(a,a+n);

        int mid,fre = 0,val;
        if(n%2 == 0){
            mid = n/2 - 1;
            for(int j = 0;j < n;j++){
                if(a[j] == a[mid] || a[j] == a[mid+1])
                    fre++;
            }
            val = a[mid+1] - a[mid] + 1;
        }
        else {
            mid = n/2;
            for(int j = 0;j < n;j++){
                if(a[j] == a[mid]){
                    fre++;
                }
            }
            val = 1;
        }
        cout << a[mid] << " " << fre << " " << val << endl;
    }
    return 0;
}