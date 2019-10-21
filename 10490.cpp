#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long a){
    if(a < 2)return false;
    if(a == 2)return true;
    long long i,j;
    j = sqrt(a);
    for(int i = 2;i <= j;i++){
        if(a%i == 0) return false;
    }
    return true;
}


int main(){
    long long n;
    while(cin >> n && n){
        bool a = is_prime(n);
        bool b = is_prime((1LL << n)-1);

        if(a && b){
            printf("Perfect: %lld!\n",(1LL << (n-1)) * ((1LL << n)-1));
        }
        else if(a && !b){
            printf("Given number is prime. But, NO perfect number is available.\n");
        }
        else{
            printf("Given number is NOT prime! NO perfect number is available.\n");
        }
    }
    return 0;
}