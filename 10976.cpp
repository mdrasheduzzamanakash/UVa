#include <bits/stdc++.h>
using namespace std;

struct xy{
    int x,y;
};

bool cmp(xy a,xy b){
    if(a.x < b.x)return false;
    else return true;
}

int main(){
    int k;
    while(scanf("%d",&k) == 1){
        vector<xy>v;
        int cnt = 0;
        for(int i = k+1;i <= 2*k;i++){
            if((i*k)%(i-k)==0){
                cnt++;
                xy t;
                t.x = (i*k)/(i-k);
                t.y = i;
                v.push_back(t);
            }
        }
        sort(v.begin(),v.end(),cmp);
        cout << cnt << "\n";
        for(int i = 0;i < v.size();i++){
            printf("1/%d = 1/%d + 1/%d\n",k,v[i].x,v[i].y);
        }
    }
}