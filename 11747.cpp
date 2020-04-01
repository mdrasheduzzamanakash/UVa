#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,d;
    bool operator < (node const & o){
        return this->d < o.d;
    }
};


int Rank[1000],Parent[1000];

void make_set(int n){
    for(int i = 0;i < n;i++)
        Rank[i] = 0, Parent[i] = i;
}

int find_set(int n){
    return Parent[n] == n ? Parent[n] : find_set(Parent[n]);
}

int Union(int x,int y){
    x = find_set(x);
    y = find_set(y);

    if(x != y){
        if(Rank[x] < Rank[y])
            swap(x,y);
        Parent[y] = x;
        if(Rank[x] == Rank[y])
            Rank[x]++;
        return 1;
    }
    return 0;
}


int main() {
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int n,m;
    while(cin >> n >> m && (n || m)){
        make_set(n);
        int track[m];
        node list[m];
        for(int i = 0;i < m;i++){
            cin >> list[i].x >> list[i].y >> list[i].d;
            track[i] = 0;
        }
        sort(list,list+m);
        vector<int> ans;
        for(int i = 0;i < m;i++){
            if(!Union(list[i].x, list[i].y)){
                ans.push_back(list[i].d);
            }
        }
        if(ans.size() == 0){
            cout << "forest";
        }else {
            cout << ans[0];
            for(int i = 1;i < ans.size();i++)
                cout << " " << ans[i];
        }
        cout << endl;
    }
}