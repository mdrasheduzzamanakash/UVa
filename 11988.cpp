#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    while(cin >> s){
        list<char>beiju_text;
        list<char>::iterator it = beiju_text.begin();
        int l = s.size();
        for(int i = 0;i < l;i++){
            if(s[i] == '[')it = beiju_text.begin();
            else if(s[i] == ']')it = beiju_text.end();
            else beiju_text.insert(it,s[i]);
        }

        //now printing the list
        for(it = beiju_text.begin();it != beiju_text.end();it++){
            cout << *it;
        }
        cout << endl;
    }
}