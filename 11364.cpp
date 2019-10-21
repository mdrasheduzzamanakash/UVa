#include <bits/stdc++.h>
using namespace std;





int main(){
    int test;   cin >> test;

    while (test--)
    {
        int mx = 0,mn = 200,n;
        cin >> n;
        while(n--){
            int t;  cin >> t;
            if(t > mx)mx = t;
            if(t < mn)mn = t;
        }
        cout << 2 *(mx-mn) << endl;
    }
    return 0;
    
}