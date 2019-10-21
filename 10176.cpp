#include <bits/stdc++.h>
using namespace std;


int main() {
    char c;
    int ans = 0;
    while((c = getchar()) != EOF){
    	if(c == '0' || c == '1'){
    		ans = (ans<<1) + (c - '0');
    		if(ans >= 131071)ans = ans % 131071;
    	}
    	else if(c == '#'){
    		if(ans == 0)
    			cout << "YES" << endl;
    		else cout << "NO" << endl;
    		ans = 0;
    	}
    }
    return 0;
}