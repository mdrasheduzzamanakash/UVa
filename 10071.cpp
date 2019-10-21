#include <bits/stdc++.h>
using namespace std;


int main(){
    float v,t,a;
    while(cin >> v >> t){
        if(t != 0)
        a = v/t;
        else t=0;

        t = 2*t;
        float s = (.5)*a*t*t;
        cout << s << endl;
    }
}