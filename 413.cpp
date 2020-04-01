#include <bits/stdc++.h>
using namespace std;
set<long long> s;
int prime[]={2,3,5,7};
int main() {
    s.insert(1);
    set<long long> :: iterator i=s.begin();
    long long sz=1;
    while(s.size()<6600){
        for(int j = 0;j < 4;j++)
            s.insert((*i)*(prime[j]));
        i++;
    }
    vector<long long> v(s.begin(),s.end());
    long long n;
    while(cin >> n && n){
        cout << "The " << n;
        if(n%100==11||n%100==12||n%100==13)cout << "th ";
        else if(n%10==1)cout << "st ";
        else if(n%10==2)cout << "nd ";
        else if(n%10==3)cout << "rd ";
        else cout << "th ";

        cout << "humble number is "<< v[n-1] << "." << endl;
    }

}