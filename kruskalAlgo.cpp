// #include <bits/stdc++.h>
// using namespace std;


// struct edge{
//     int u,v,w;
//     bool operator < (edge const& other)const{
//         return this->w < other.w;
//     }
// };

// int main() {
//     int n;
//     vector<edge> edges;
//     int cost = 0;
//     vector<int> parent(n);
//     vector<edge> ans;
//     cin >> n;
//     for(int i = 0;i < n;i++){
//         parent[i] = i;
//     }
//     int m;
//     cin >> m;
//     while(m--){
//         edge temp;
//         cin >> temp.u >> temp.v >> temp.w;
//         edges.push_back(temp);
//     }
//     sort(edges.begin(),edges.end());
//     for(auto e : edges){
//         if(parent[e.u] != parent[e.v]){
//             cout << e.w << endl;
//             cost += e.w;
//             ans.push_back(e);
//             int old_id = parent[e.u];
//             int new_id = parent[e.v];
//             for(int i = 0;i < n;i++){
//                 if(parent[i] == old_id)
//                     parent[i] = new_id;
//             }
//         }
//     }
//     cout << cost << endl;
// }

#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w;
    bool operator < (edge const& other){
        return this->w < other.w;
    }
};

vector<int> Rank,parent;
void make_set(int n){
    for(int i = 0;i < n;i++){
        parent[i] = i;
    }
}

int find_set(int v){
    return v == parent[v] ? v : find_set(parent[v]);
}

void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(Rank[a] < Rank[b])
            swap(a,b);
        parent[b] = a;
        if(Rank[a] == Rank[b])
            Rank[a]++;
    }
}

int main() {
    int n;
    cin >> n;
    parent.resize(n);
    Rank.resize(n);
    for(int i = 0;i < n;i++)
        Rank[i] = 0;
    make_set(n);
    int m;
    cin >> m;
    vector<edge> edges;
    for(int i = 0;i < m;i++){
        edge e; cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }
    sort(edges.begin(),edges.end());

    int cost = 0;
    vector<edge> ans;
    for(auto e : edges){
        if(find_set(e.u) != find_set(e.v)){
            cost += e.w;
            ans.push_back(e);
            union_set(e.u,e.v);
        }
    }
    cout << cost << endl;
}