#include <iostream>
using namespace std;
int main()
{
	long long int n,temp;
	while(cin >> n && n != 0)
	{
	while(n >= 10)
	{
		temp = 0;
		while(n > 0)
		{
			temp += (n%10);
			n /= 10;
		}
		n = temp;
	}
	cout << n <<endl;
   }
   return 0;
}