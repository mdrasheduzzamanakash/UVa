#include<iostream>
using namespace std;
int main()
{
	int tc,cnt=1,maxi;
	cin >> tc;
	while(tc--)
	{
		int n;
		cin >> n >> maxi;
		n=n-1;
		while(n--)
		{
			int temp;
			cin >> temp;
			if(maxi < temp)
				maxi = temp;
		}
		cout << "Case " <<cnt++<<": "<<maxi<<"\n";
	}
	return 0;
}