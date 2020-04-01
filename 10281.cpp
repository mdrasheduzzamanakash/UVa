#include <bits/stdc++.h>
using namespace std;












int main() {
    //             freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    long long int h = 0,m = 0,s = 0,hh = 0,mm = 0,ss = 0,pres,prev;
    double dis = 0,velocity,prevVelocity = 0;
    string str;
    while(getline(cin , str)){
        int len = str.length();
        if(len > 8){
            stringstream sss(str);
            sss >> str >> velocity;
            velocity = (velocity*1000) / 3600;
            // cout << str << velocity << endl;
            h = (str[0]-'0')*10 + (str[1]-'0');
            m = (str[3]-'0')*10 + (str[4]-'0');
            s = (str[6]-'0')*10 + (str[7]-'0');

            pres = h*3600 + m*60 + s;
            prev = hh*3600 + mm*60 + ss;
            dis += abs(prevVelocity * (pres - prev));
        }else {
            hh = (str[0]-'0')*10 + (str[1]-'0');
            mm = (str[3]-'0')*10 + (str[4]-'0');
            ss = (str[6]-'0')*10 + (str[7]-'0');

            prev = h*3600 + m*60 + s;
            pres = hh*3600 + mm*60 + ss;

            // cout << pres-prev <<endl;
            prevVelocity = velocity;
            dis += abs(velocity * (pres - prev));
            h = hh; m = mm; s = ss;
            cout << str << " " << fixed << setprecision(2) << 
                (dis/1000) << " " << "km" << endl;
        }
    }
}