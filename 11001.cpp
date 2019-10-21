#include <bits/stdc++.h>
using namespace std;


int main(){
    double v_total,v0;
    while(cin >> v_total >> v0 && (v_total || v0)){
        double max_len = 0,max_disc = 0,len = 0,D,V;
        
        for(int disc = 1;;disc++){
            V = (double)v_total/disc;
            if(V <= v0)break;


            D = 0.3*(sqrt(V-v0));
            len = D*disc;

            if(len >= max_len){

                if(fabs(max_len-len) <= 1e-12){
                    max_len = 0;
                    max_disc = 0;
                    break;
                }
                max_len = len;
                max_disc = disc;
            }
        }
        cout << max_disc << "\n";
    }
    return 0;
}