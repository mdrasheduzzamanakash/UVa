#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int testCase,hj=0,lj=0,n,first,temp,count=1;
	cin >> testCase;
	while(testCase--)
	{
		cin >> n >> first;
		hj=lj=0;
		for(int i=0;i < n-1;i++)
		{
			cin >> temp;
			if(temp > first)hj++;
			if(temp < first)lj++;
			first = temp;
		}
		cout << "Case " <<count++<<": "<<hj<<" "<<lj<<"\n";
	}
	return 0;
}