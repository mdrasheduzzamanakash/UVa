#include<iostream>
#include<string>
#include <cstring>
using namespace std;
int main()
{
    char s[1000];
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>s;
        len = strlen(s);
        if(strcmp(s,"1")==0 || strcmp(s,"4")==0 || strcmp(s,"78")==0)
        {
            cout<<"+\n";
            continue;
        }
        else if(s[len-1]=='5' && s[len-2]=='3')
        {
            cout<<"-\n";
            continue;
        }
        else if(s[0]=='9' && s[len-1]=='4')
        {
            cout<<"*\n";
            continue;
        }
        else if(s[0]=='1' && s[1]=='9' && s[2]=='0')
        {
            cout<<"?\n";
            continue;
        }

        cout<<"+\n";
        return 0;

    }
}
