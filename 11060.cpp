#include <bits/stdc++.h>
using namespace std;
map<string , int> gint;
map<int, string> gstring;
vector<string> ans;
int indegree[200];

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m,kse = 0;
    while (scanf("%d",&n) != EOF)
    {
        //.................
        vector<int> graph[200];
        gint.clear();
        gstring.clear();
        ans.clear();
        memset(indegree,0,sizeof indegree);
        //...cln...........
        string s;
        for(int i = 0;i < n;i++)
        {
            cin >> s;
            gint[s] = i;
            gstring[i] = s;
        }
        cin >> m;
        while(m--)
        {
            string a,b;
            cin >> a >> b;
            graph[gint[a]].push_back(gint[b]);
            indegree[gint[b]]++;
        }
        //inp fin
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0;i < n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int v = q.top();
            q.pop();
            for(int i = 0;i < graph[v].size();i++)
            {
                indegree[graph[v][i]]--;
                if(indegree[graph[v][i]] == 0)
                {
                    q.push(graph[v][i]);
                }
            }
            ans.push_back(gstring[v]);
        }
        kse++;
        printf("Case #%d: Dilbert should drink beverages in this order:",kse);
        for(auto i : ans) cout << " " << i;
                          cout << "." << endl << endl;

    }
    
}