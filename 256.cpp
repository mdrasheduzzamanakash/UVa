#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;

int n;
vector<int> v;
void prep() {
    for(int i = 0;i < 10000;i++){
        v.push_back(i*i);
    }
}

int main() {
    prep();
    while(scanf("%d" , &n)==1){
        for(int i = 0;i < v.size();i++){
            if(v[i] >= (int)pow(10, n))break;
            if(pow(v[i]%(int)pow(10,n/2)+v[i]/(int)pow(10,n/2),2)==v[i]){
                cout << setw(n) << setfill('0') << v[i] << endl;
            }
        }
    }
}