#include <bits/stdc++.h>
using namespace std;

bool comp(string a,string b){
    string x = a+b;
    string y = b+a;
    return x > y;
}


int main(){
    int n;
    while(cin >> n && n){
        vector<string>v(n);
        for(int i = 0;i < n;i++)
            cin >> v[i];
        sort(v.begin(),v.end(),comp);
        
        //now printing
        for(int i = 0;i < v.size();i++){
            cout << v[i];
        }
        cout << endl;
    }
}