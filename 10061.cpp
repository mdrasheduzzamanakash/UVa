#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793239, e = 2.7182818284590452354;
double a[100020];
int f_digit(int n,int b){
    if(n > 100000){
        return (int)((log(sqrt(2*PI*n)) + n*log(n/e))/log(b)) + 1;
    }
    return ceil(a[n]/log(b) + 1e-10);
}
int f_zero(int N, int B) {
    int zero = INT32_MAX;
    for(int i = 2; i <= B; i++) {
        if(B%i == 0) {
            int a = 0;
            while(B%i == 0)
                a++, B /= i;
            int b = 0;
            int temp = N;
            while(temp)
                b += temp/i, temp /= i;
            zero = min(zero, b/a);
        }
    }
    if(zero == INT32_MAX)
        return 0;
    return zero;
}



int main(){
    int n,b;
    for(int i = 1;i <= 100000;i++){
        a[i] = a[i-1] + log(i);
    }
    while(scanf("%d %d",&n,&b) != EOF){
        int digit = f_digit(n,b);
        int zero = f_zero(n,b);

        cout << zero << " " << digit << endl;
        // cout << digit << endl;
    }
    return 0;
}