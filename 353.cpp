#include <bits/stdc++.h>

using namespace std;

string s,sub,temp;

int main()
{
    int len,v,cnt=0;
    cin >> v;
    cin >> s;
        len = s.size();
        for(int i= 0;i < len;i++)
        {
            for(int j = i;j < len;j++)
            {
                sub = s.substr(i,len-j);
                temp = sub;
                reverse(temp.begin(),temp.end());
                if(temp == sub)
                    {cnt++;}
            }
        }
        if(cnt%2 == 0)
        cout << "Shera" <<endl;
        else
        cout << "Not Shera" <<endl;
       return 0;
}
