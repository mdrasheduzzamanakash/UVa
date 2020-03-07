
#include<bits/stdc++.h>

using namespace std;

vector<int>adj[1000000],adj2[10000];
bool visited[1000000]={false},visited2[1000000]={false};
int dis[10000]={0};
int fin[10000]={0},tim=0;
stack<int>st;

void dfs(int s)
{
    visited[s]=true;
    for(int i=0;i<adj[s].size();i++){
        int x=adj[s][i];
        if(!visited[x]){
            visited[x];
            dfs(x);
        }
    }
    st.push(s);
}
void scc_dfs(int s)
{
    visited2[s]=true;
    for(int i=0;i<adj[s].size();i++){
        int x=adj[s][i];
        if(!visited2[x]){
            visited2[x]=true;
            scc_dfs(x);
        }
    }
}


int main()
{
         freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    int t,n,m,i,j,cnt,u,v,w,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(visited,0,sizeof(visited));
        memset(visited2,0,sizeof(visited2));
        memset(dis,0,sizeof(dis));
        memset(fin,0,sizeof(fin));
        tim=0,cnt=0;
        for(i=0;i<=n;i++){
            adj[i].clear();
            adj2[i].clear();
        }
        for(i=0;i<m;i++){
            cin>>v>>w;

               adj[v].push_back(w);
               //adj2[w].push_back(v);
        }
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
               dfs(i);
        }
        while(!st.empty())
        {
            int x=st.top();
            if(!visited2[x]){
                cnt++;
                scc_dfs(x);
            }
            st.pop();
        }
        cout<<cnt<<endl;
    }
}