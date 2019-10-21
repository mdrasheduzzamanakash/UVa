#include <bits/stdc++.h>
using namespace std;



int main(){
    char a[] = {'.','B','F','P','V','C','G','J','K','Q','S','X','Z',
    'D','T','L','M','N','R',' '};

    string s;
    while(cin >> s){
        int k = 0,t = 0,d = 0;
        vector <int>v;
        for(int i = 0;i < s.size();i++){
            int j;
            for(j = 1;j <=19;j++){
                if(a[j] == s[i])break;
            }
            if(j >= 1 && j <= 4)
                {
                    if(d != 1)
                    v.push_back(1);

                    d = 1;
                }
            else if(j >= 5 && j <= 12)
                {
                    if(d != 2)
                    v.push_back(2);

                    d = 2;
                }
            else if(j >= 13 && j <= 14)
                {
                    if(d != 3)
                    v.push_back(3);

                    d = 3;
                }
            else if(j == 15)
                {
                    if(d != 4)
                    v.push_back(4);

                    d = 4;
                }
            else if(j >= 16 && j <= 17)
                {
                    if(d != 5)
                    v.push_back(5);

                    d = 5;
                }
            else if(j == 18)
                {
                    if(d != 6)
                    v.push_back(6);

                    d = 6;
                }
            else 
                {d = 0;continue;}
        }

        for(int i = 0;i < v.size();i++){
            cout << v[i];
        }
        cout << "\n";
    }
    return 0;
}