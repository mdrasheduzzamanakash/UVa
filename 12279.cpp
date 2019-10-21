#include <iostream>
using namespace std;




int main(){
    int c = 1,k;
    while(1){
        int n;  cin >> n;
        if(!n)break;

        int a = 0,b = 0;
        while (n--)
        {
            cin >> k;
            if(k)a++;
            else b++;
        }
        printf("Case %d: %d\n",c++,a-b);
        
    }
    return 0;
}