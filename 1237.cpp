#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>


using namespace std;

int main(){
    int test;   cin >> test;
    while(test--){
        int database;   cin >> database;
        string name[database+1];
        int f[database+1],l[database+1];

        string na;
        int fi,la;
        for(int i = 0;i < database;i++){
            cin >> na >> fi >> la;
            name[i] = na;f[i] = fi;l[i] = la;
        }

        int q,price;  cin >> q;
        for(int qr = 0;qr < q;qr++){
            cin >> price;
            int cnt = 0;
            string target;
            for(int i = 0;i < database;i++){
                if(price >= f[i] && price <= l[i]){
                    target = name[i];cnt++;
                }
                if(cnt > 1)break;
            }
            if(cnt == 1){
                cout << target << "\n";
            }
            else
                cout << "UNDETERMINED\n";
        }
        if(test)
        cout << "\n";
    }
}