#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char s[1000005];
    int cnt = 1,len;
    while(scanf("%s",&s)==1)
    {
        if(strcmp(s,"n")==0)break;
        cout<<"aaaa"<<endl;
        int numOfoperation;cin >> numOfoperation;
        printf("Case %d:\n",cnt++);
        while(numOfoperation--)
        {
            int flag = 0;
            int i,j; cin >> i >> j;
            if(i > j){int temp = i;i = j;j = temp;}
            if(i == j){printf("Yes\n");continue;}
            else
            {
                for(int k = i;k < j;k++)
                {
                    if(s[k]==s[k+1]){flag = 0;}
                    else{flag = 1;break;}
                }
            }
            if(flag == 0)printf("Yes\n");
            else printf("No\n");
        }

    }
}