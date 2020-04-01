#include <stdio.h>
#include <math.h>



void getXY(int n, int &x, int &y) {
    int level = 0, sum = 0;
    while(sum <= n) {
        level++;
        sum += level*4;
    }
    x = -level, y = 0;
    if(n >= sum-level) {
        x += sum-n, y -= sum-n;
        return;
    } else
        sum -= level, x = 0, y = -level;
    if(n >= sum-level) {
        x += sum-n, y += sum-n;
        return;
    } else
        sum -= level, x = level, y = 0;
    if(n >= sum-level) {
        x -= sum-n, y += sum-n;
        return;
    } else
        sum -= level, x = 0, y = level;
    x -= sum-n, y -= sum-n;
    return;
}





int main() {
    int a, b;
    while(scanf("%d %d", &a, &b) == 2 && a >= 0) {
        int ax, ay, bx, by;
        getXY(a, ax, ay);
        getXY(b, bx, by);
        printf("%.2lf\n", hypot(ax-bx, ay-by));
    }
    return 0;
}