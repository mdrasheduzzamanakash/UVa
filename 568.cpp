#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int mul(int x,int res[],int res_size){
    int carry = 0;
    for(int i = 0;i < res_size;i++){
        int pro = res[i] * x + carry;
        res[i] = pro%10;
        carry = pro/10;
    }
    while(carry){
        res[res_size] = carry % 10;
        carry = carry / 10; 
        res_size++;
    }
    return res_size;
}

int factorial(int res[],int n){
    int res_size = 1;

    for(int i = 2;i <= n;i++){
        res_size = mul(i,res,res_size);
    }
    return res_size;
}



int main(){
    int n;
    while(cin >> n){
        int res[100000];
        res[0] = 1;

        int size = factorial(res,n);

        for(int i = 0;i < size;i++){
            if(res[i] != 0){
                cout << right << setw(5) << n << " -> " << res[i] << endl;
                break;
            }
        }
    }

    return 0;
}