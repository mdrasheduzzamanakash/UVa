#include <iostream>
using namespace std;

int main(){
    int test_case;
    cin >> test_case;

    for(int i = 0;i < test_case;i++){
        int G,L;
        cin >> G >> L;
        if(L % G != 0){
            cout << "-1\n";
        }
        else
        cout << G << " " << L << endl;
    }
    return 0;
}