#include <bits/stdc++.h>
using namespace std;
#define mx 1000000

struct node
{
    int x,y,w;
    bool operator < (node const &o){
        return !(this->w < o.w);
    }
};

int Parent[mx],Rank[mx];
void Make(int n){
    for(int i = 0;i < n;i++){
        Parent[i] = i;
        Rank[i] = 0;
    }
}
int FindParent(int v){
    return v == Parent[v] ? Parent[v] : FindParent(Parent[v]);
}
int Union(int x, int y){
    x = FindParent(x);
    y = FindParent(y);
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

int main(){
    //     freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int n,m,kse = 0,w;
    while(cin >> n >> m && (n || m)){
        map<int,string> name;
        map<string,int> no;
        node list[mx];
        int id = 0;
        for(int i = 0;i < m;i++){
            string s,ss;
            cin >> s >> ss >> w;
            if(no.find(s) == no.end()){
                no[s] = id;
                name[id] = s;
                id++;
            }
            if(no.find(ss) == no.end()){
                no[ss] = id;
                name[id] = ss;
                id++;
            }
            list[i].x = no[s];
            list[i].y = no[ss];
            list[i].w = w;
        }
        string src,dest;
        cin >> src >> dest;
        sort(list,list+m);
        int ans;
        Make(n);
        for(int i = 0;i < m;i++){
            if(FindParent(no[src]) == FindParent(no[dest])) break;
            if(Union(list[i].x, list[i].y)){
                ans = list[i].w;
            }
        }
        printf("Scenario #%d\n%d tons\n\n",++kse,ans);
    }
}