#include <bits/stdc++.h>
using namespace std;

struct friends
{
    int st,av;
};

struct city
{
    int st,av,dis;
};

bool comp(city a,city b){
    if(a.dis < b.dis)
        return true;
    else if(a.dis== b.dis){
        if(a.st < b.st)
            return true;
        else if(a.st == b.st){
            return a.av < b.av;
        }
        else 
            return false;
    }
    else
        return false;
}

int test,s,a,f;
int main(){
    cin >> test;
    while(test--){
        cin >> s >> a >> f;
        vector<friends>friends_cordinate(f);
        vector<city>city_corinate;
        for(int i = 0;i < f;i++){
            cin >> friends_cordinate[i].st >> friends_cordinate[i].av;
        }

        for(int i = 1;i <= s;i++){
            for(int j = 1;j <= a;j++){
                //now for a single cordinate
                //calculating the maximum distance from the group of friends
                int mx = -1;
                for(int k = 0;k < friends_cordinate.size();k++){
                    int x = (i-friends_cordinate[k].st)*(i-friends_cordinate[k].st);
                    int y = (j-friends_cordinate[k].av)*(j-friends_cordinate[k].av);
                    int d = sqrt(x+y);
                    if(mx < d)mx = d;
                }

                //now we are getting max dis for every cordinate in the city
                //let us store them
                
                city temp;  temp.st = i; temp.av = j; temp.dis = mx;
                city_corinate.push_back(temp);


            }
        }


        sort(city_corinate.begin(),city_corinate.end(),comp);
        // cout << endl;
        // // for(int i = 0;i < 49;i++){
        // //     cout << city_corinate[i].st << " " << city_corinate[i].av << " " << city_corinate[i].dis << endl;
        // // }
        // cout << city_corinate[0].st << city_corinate[0].av;

        printf("(Street: %d, Avenue: %d)\n",city_corinate[0].st,city_corinate[0].av);
    }
}