#include<bits/stdc++.h>
using namespace std;


int main() {
    vector<int> ans;
    for(int i=1;i<100010;i++){
        int d=sqrt(i); if(d*d==i)ans.push_back(i);
    }
    int l,e;
    while(cin >> l >> e && (l||e)){
        int len=(upper_bound(ans.begin(),ans.end(),e)-ans.begin())-
                (lower_bound(ans.begin(),ans.end(),l)-ans.begin());
        cout << len << endl;
    }
}