#include <iostream>
using namespace std;
long long int recursion(long long int n){
	long long int n1 = n;
	reverse(n1);
	if(palindrome(n,n1))return (n+n1);
	else 
	{
		n +=n1;
		recursion(n);
	}
}

void reverse(long long int &n1){
	long long int t = 0;
	while(n1 > 0){
		t += t*10 +(n1%10);
		n1 /=10;
	}
}

bool palindrome(long long int a,long long int b){
	a = a+b;
	b = a;
	reverse(b);
	if(a == b)return true;
	else false;

}

int main(){
	long long int n,v;
	cin >> n;
	for(int i=1;i <= n;i++)
	{
		cin >> v;
		cout << recursion(v) << endl;
	}
	return(0);
}