#include <bits/stdc++.h>
using namespace std;


map <char,int> m;
map <char,int> fre;
map <char,int>:: iterator it;

int main(){
    int t,v;  cin >> t;
    char c;
    while(t--){
        m.clear();
        fre.clear();

        int k,tot = 0;  cin >> k;
        while(k--){
            cin >> c >> v;
            m[c] = v;
        }
        int sen;    cin >> sen;
        string line;



        for(int j = 0;j < sen;j++){
            cin >> ws;  getline(cin,line);

            for(int i = 0;i < line.size();i++){
                fre[line[i]] += 1;
            }

        }

        //now calculating part
        for(it = fre.begin();it != fre.end();it++){
            auto it2 = m.find(it->first);
            if(it2 != m.end())
                tot += ((it2->second)*(it->second));
        }

        int dolar = tot/100;
        tot = tot%100;

        if(tot >= 10)
        cout << dolar << "." << tot << "$\n";
        else cout << dolar << ".0" << tot << "$\n";
    }
    return 0;
};