#include <bits/stdc++.h>
using namespace std;
#define maxVal 100000000
#define maxN 1000

int n,m;
char a[maxN+5][maxN+5];
int fire[maxN+5][maxN+5];
int visit[maxN+5][maxN+5];
queue<pair<int,int> > q;

int r[]={0,0,1,-1};
int c[]={1,-1,0,0};

void setFire()
{
    int k,ui,uj,vi,vj;
    while(!q.empty())
    {
        ui=(q.front()).first;
        uj=(q.front()).second;
        q.pop();
        for(k=0;k<4;k++)
        {
            vi=ui+r[k];
            vj=uj+c[k];
            if(vi>=0&&vi<n&&vj>=0&&vj<m&&a[vi][vj]!='#'&&
                fire[vi][vj]==maxVal)
            {
                fire[vi][vj]=fire[ui][uj]+1;
                q.push(make_pair(vi,vj));
            }
        }
    }
}

void bfs(int ui,int uj)
{
    int k,vi,vj;
    q.push(make_pair(ui,uj));
    visit[ui][uj]=0;
    while(!q.empty())
    {
        ui=(q.front()).first;
        uj=(q.front()).second;
        q.pop();
        for(k=0;k<4;k++)
        {
            vi=ui+r[k];
            vj=uj+c[k];
            if(vi>=0&&vi<n&&vj>=0&&vj<m&&a[vi][vj]!='#'&&
                visit[vi][vj]==maxVal)
            {
                visit[vi][vj]=visit[ui][uj]+1;
                q.push(make_pair(vi,vj));
            }
        }
    }
}
int main() {
    int T;
    cin >> T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            for(int j=0;j<m;j++)
                fire[i][j]=maxVal,visit[i][j]=maxVal;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='F')
                {
                    q.push(make_pair(i,j));
                    fire[i][j]=0;
                }
            }
        setFire();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]=='J')
                    bfs(i,j);

        int z=maxVal;
        for(int i=0;i<n;i++)
        {
            if(visit[i][0]<fire[i][0])
                z=min(z,visit[i][0]);
            if(visit[i][m-1]<fire[i][m-1])
                z=min(z,visit[i][m-1]);
        }
        for(int j=0;j<m;j++)
        {
            if(visit[0][j]<fire[0][j])
                z=min(z,visit[0][j]);
            if(visit[n-1][j]<fire[n-1][j])
                z=min(z,visit[n-1][j]);
        }
        if(z!=maxVal)
            printf("%d\n",z+1);
        else
            printf("IMPOSSIBLE\n");
    }
}