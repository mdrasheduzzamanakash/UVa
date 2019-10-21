#include <bits/stdc++.h>
using namespace std;



int main(){
    int test;
    cin >> test;
    while(test--){



        vector<long long>v;
        long long  t,sum = 0;
        while(cin >> t && t){
            v.push_back(t);
        }
        sort(v.rbegin(),v.rend());
        
        for(int i = 0;i < v.size();i++){
            sum += 2*pow(v[i],i+1);
        }

        if(sum <= 5000000)
            cout << sum << endl;
        else
            cout << "Too expensive\n";
    }
}