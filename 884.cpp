#include <bits/stdc++.h>
using namespace std;

long long a[1000001];
void sieve(){
    for(long long i = 0;i < 1000001;i++)
        a[i] = 1;
    a[1] = 0;
    for(long long i = 2;i < 1000001;i++){
        if(a[i] == 1){
            for(long long j = 2;i*j < 1000001;j++){
                a[i*j] = a[i] + a[j];
            }
        }
    }

    //now merging 
    for(long long i = 2;i < 1000001;i++)
        a[i] += a[i-1];
}



int main(){
    sieve();

    long long n;
    while(cin >> n){
        cout << a[n] << endl;
    }
    return 0;
}