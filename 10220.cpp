#include <bits/stdc++.h>
using namespace std;





int mul(int res[],int res_size,int x){
    int carry = 0;
    for(int i = 0;i < res_size;i++){
        int pro = res[i] * x + carry;
        res[i] = pro % 10;
        carry = pro / 10;
    }
    while(carry){
        res[res_size] = carry % 10;
        carry /= 10;
        res_size++;
    }
    return res_size;
}





int factorial(int res[],int n){
    int res_size = 1;
    for(int i = 2;i <= n;i++){
        res_size = mul(res,res_size,i);
    }
    return res_size;
}






int main(){
    int n;
    while(cin >> n){
        int res[100000];
        res[0] = 1;

        int size = factorial(res,n);


        int sum = 0;
        for(int i = size-1;i >= 0;i--){
            sum += res[i];
        }

        cout << sum << endl;
    }
}