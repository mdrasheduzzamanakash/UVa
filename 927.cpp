#include<bits/stdc++.h>
using namespace std;


int main(){
  int test; cin >> test;
  while(test--){
    vector<int>v;
    int n;cin >> n;
    for(int i = 0;i <= n; i++){
      int temp;cin >> temp;v.push_back(temp);
    }
    int d,k;  cin >> d >> k;

    int idx = 1;
    int tot = 0;
    while(tot < k){
      tot += idx*d;
      idx++;
    }
    idx--;

    long long ans = 0;
    for(int i = 0;i < v.size();i++)
      ans += v[i]*pow(idx,i);
    
    cout << ans << endl;
  }
}