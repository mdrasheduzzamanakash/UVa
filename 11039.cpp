#include<bits/stdc++.h>
using namespace std;

struct f{
    int size;
    int color;

    bool operator < (const f &a){
        return size > a.size;
    }
};



int main(){
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        vector<f>floors(n);
        for(int i = 0;i < n;i++){
            cin >> floors[i].size;
            floors[i].color = (floors[i].size < 0);
            floors[i].size = abs(floors[i].size);
        }
        sort(floors.begin(),floors.end());

        int mx1 = 0,mx2 = 0;
        int need_col = 0;
        for(int i = 0;i < floors.size();i++){
            if(floors[i].color == need_col){
                mx1++;
                need_col = 1 - need_col;
            }
        }
        need_col = 1;
        for(int i = 0;i < floors.size();i++){
            if(floors[i].color == need_col){
                mx2++;
                need_col = 1 - need_col;
            }
        }


        int maxx = max(mx1,mx2);
        cout << maxx << endl;
    }
    return 0;
}