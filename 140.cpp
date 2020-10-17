#include <bits/stdc++.h>
using namespace std;
static bool used[8];
static int order[8];
bool Matrix[26][26];
int allNodes[26];
int n,ans[8];
int minAns = 1e9;
void DFS(int pos);
int main()
{
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    string s;
    while (cin >> s && s != "#")
    {
        n = 0;
        minAns = 1e9;
        bool alreadyIn[26];
        memset(alreadyIn, false, sizeof alreadyIn);
        memset(Matrix, false, sizeof Matrix);
        memset(allNodes, -1, sizeof allNodes);
        for (int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'A';
            if (alreadyIn[u] == false)
            {
                alreadyIn[u] = true;
                allNodes[n++] = u;
            }
            int j;
            for (j = i + 2; s[j] != ';' && s[j] != '\0'; j++)
            {
                int v = s[j] - 'A';
                if (alreadyIn[v] == false)
                {
                    alreadyIn[v] = true;
                    allNodes[n++] = v;
                }
                Matrix[u][v] = true;
            }
            i = j;
        }
        sort(allNodes, allNodes + n);
        DFS(0);
        for (int i = 0; i < n; i++)
        {
            cout << char(allNodes[ans[i]]+'A') << " ";
        }
        cout << "-> " << minAns << endl;
    }
}
void DFS(int pos)
{
    if (pos == 0)
        memset(used, false, sizeof used);
    if (pos == n)
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (Matrix[allNodes[order[i]]][allNodes[order[j]]] == true && abs(i - j) > temp)
                {
                    temp = abs(i - j);
                }
            }
        }
        if (temp < minAns)
        {
            minAns = temp;
            for (int i = 0; i < n; i++)
            {
                ans[i] = order[i];
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (used[i] == false)
            {
                used[i] = true;
                order[pos] = i;
                DFS(pos + 1);
                used[i] = false;
            }
        }
    }
}