#include <bits/stdc++.h>
using namespace std;



int main(){
    string s;
    vector<int>v;
    while(getline(cin,s)){
        // int i,j;
        // for(i = 0;i < s.size();i++){
        //     if(s[i] != ' ')
        //         break;
        // }
        // for(int j = i;j < s.size();j++){
        //     if(s[i] == ' ')
        //         break;
        // }
        // s = s.substr(i,j-i);
        stringstream geek(s);
        long long n,d,sum;
        geek >> n;
        v.push_back(n);
        sort(v.begin(),v.end());

        if(v.size()%2 == 1){
            d = v.size()/2;
            cout << v[d] << endl;
        }else{
            d = v.size()/2;d--;
            sum = v[d]+v[d+1];
            cout << sum/2 << endl;
        }
    }
}
