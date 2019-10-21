#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>
using namespace std;
int main(){
    set<string> ignore;
    string s;
    while (cin >> s && s != "::")   ignore.insert(s);

    //now taking the titles and handling them individually
    multimap<string,string>m;   // so that we can handle duplicate
    while(getline(cin,s)){
        int i,j,k;
        for(i = 0;i < s.size();i++)    s[i] = tolower(s[i]); //converting to the lower case

        // now taking each word and finding it in ignore list and 
        // then taking appropriate action
        for(i = 0;i < s.size();i++){
            if(!isalpha(s[i]))  continue;

            //binding a word from the title
            string sin_wrd;
            for(j = i;j < s.size() && isalpha(s[j]);j++){
                sin_wrd += s[j];
            }

            // now searching this sin_wrd in ignore set
            while(!ignore.count(sin_wrd)){
                //making it uppercase
                for(k = 0;k < sin_wrd.size();k++)   sin_wrd[k] = toupper(sin_wrd[k]);

                //now inserting all possible combination of title
                string t(s);
                t.replace(i,sin_wrd.size(),sin_wrd);
                m.insert(make_pair(sin_wrd,t));
            }
            i = j;
        }
    }

    for(map<string,string>::iterator it = m.begin();it != m.end();it++)
        cout << it->second << endl;

    return 0;
}