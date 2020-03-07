#include<bits/stdc++.h>
using namespace std;

int arr[26];
int main()
{
    int t;
    cin >> t;
    for(int c = 1;c <= t;c++)
    {
        memset(arr,0,sizeof arr);
        string s;
        cin >> s;
        stack <int> st;
        st.push(s[0]-'A');

        for(int i = 1;i < s.length();i++)
        {
            int b = s[i]  - 'A';
            if(st.top() == b)
            {
                st.pop();
                if(!st.empty())
                {
                    arr[b]++;
                arr[st.top()-'A']++;
                }
            }
            else {
                st.push(s[i]-'A');
            }
        }

        sort(s.begin(),s.end());
        cout << "Case " << c << endl;
        for(int i = 0;i < 26;i++)
        {
            if(arr[i] != 0)
            {
                printf("%c = %d\n",65+i,arr[i]);
            }
        }
    }
}