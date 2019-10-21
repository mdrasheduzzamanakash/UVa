#include<bits/stdc++.h>
using namespace std;

void solve(int a,int b,int c);
int main(){
    int test;
    cin >> test;
    while(test--){
        int a,b,c;
        cin >> a >> b >> c;
        solve(a,b,c);
    }
    
}


void solve(int a,int b,int c){
    for(int x = -100;x <= 100;x++){
        for(int y = -100;y <= 100;y++){
            for(int z = -100;z <= 100;z++){
                if(x==y || y==z || z==x || (x+y+z) != a || (x*y*z) != b || (x*x + y*y + z*z) != c)
                    continue;
                else{
                        cout << x << " " << y << " " << z << endl;
                        return;
                    }
            }
        }
    }
    cout << "No solution.\n";
    return;
}
