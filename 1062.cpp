#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    int c = 1;
    while(cin >> s && s != "end"){
        int len = s.size();

        // now cheaking for lower value value character before a character
        //because if we go up to this character then we must atleast this amount of 
        //stack.....now time to find out the max value of stack ammount
        int sta[len];
        int mx = -1;
        for(int i = 0;i < len;i++){
            sta[i] = 1;
            for(int j = 0;j < i;j++){
                if(s[j] < s[i])
                sta[i] = max(sta[i],sta[j]+1);
            }
            mx = max(mx,sta[i]);
        }
        printf("Case %d: %d\n",c++,mx);
    }
}


