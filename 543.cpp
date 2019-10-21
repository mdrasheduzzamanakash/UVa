#include <bits/stdc++.h>
using namespace std;



int bs[1000000] = {0};
int prime[100000];
int ind=0;

void sieve(){
    for(int i = 3;i < 1000000; i+=2){
        if(bs[i] == 0){
            prime[ind++] = i;
            for(int j = 3; i*j <= 1000000;j += 2){
                bs[i*j] = 1;
            }
        }
    }
}


int main(){
    int n,i;
    sieve();
    while(cin >> n && n){
        int x, y, flag = 0;
		for(i = 0; i < ind; i++) {
			x = prime[i], y = n - prime[i];
			if(x > y)	break;
			if(bs[x] == 0 && bs[y] == 0) {
				printf("%d = %d + %d\n", n, x, y);
				flag = 1;
				break;
			}
		}
		if(!flag)
			puts("Goldbach's conjecture is wrong.");
        }
        return 0;
}