#include <bits/stdc++.h>
using namespace std;




int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        string s;
        int mx = -1;


        vector <string> v;
        for(int i = 0;i < n;i++){
            cin >> s;
            int d = s.size();
            if(d > mx)mx = d;
            v.push_back(s);
        }
        
        sort(v.begin(),v.end());
        printf("------------------------------------------------------------\n");
        int c = 62 / (mx+2);
        int r = (int)ceil((float(n)/(float)c));

        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                int idx = j*r + i;
                if(idx < n)
                j == c-1?cout << left << setw(mx) << v[idx]:cout << left << setw(mx+2) << v[idx];
            }
            cout << endl;
        }
    }
    return 0;
}