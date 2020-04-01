#include <bits/stdc++.h>
using namespace std;


int main() {
    int a,b;
    while(scanf("%d%d",&a,&b) == 2){
        int cnt = 0;
        for(int i = a;i <= b;i++){
            int temp = i;
            bool a[10] = {false},f = false;
            while(temp){
                if(a[temp%10] == true)f = true;
                a[temp%10] = true;
                temp /= 10;
            }
            if(!f)cnt++;
        }
        cout << cnt << endl;
    }
}