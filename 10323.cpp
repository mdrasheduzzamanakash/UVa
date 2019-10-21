#include <iostream>
using namespace std;




int main(){
    int n;
    while(cin >> n){
        if(n < 0){
            if(n%2 == 0){
                cout << "Underflow!\n";
            }
            else cout << "Overflow!\n";
        }
        else if(n >= 0 && n <= 7){
            cout << "Underflow!\n";
        }
        else if(n == 8)cout << 40320 << endl;
        else if(n == 9)cout << 362880 << endl;
        else if(n == 10)cout << 3628800 << endl;
        else if(n == 11)cout << 39916800 << endl;
        else if(n == 12)cout << 479001600 << endl;
        else if(n == 13)cout << 6227020800 << endl;
        else cout << "Overflow!\n";
    }
}