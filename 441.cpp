#include <bits/stdc++.h>
using namespace std;
vector<int> a(13);
vector<int> ans;
int n;

void f(int i){
    if(ans.size() == 6){
        cout << ans[0];
        for(int j = 1;j < 6;j++)
        cout << " " << ans[j];

        cout << endl;
        return;
    }
    for(int j = i;j < n;j++){
        ans.push_back(a[j]);
        f(j+1);
        ans.pop_back();
    }
}


int main(){
    int c = 0;
    while(scanf("%d",&n) && n){
        c++;
        if(c > 1)cout << endl;
        for(int i = 0;i < n;i++)    cin >> a[i];
        f(0);
    }
}