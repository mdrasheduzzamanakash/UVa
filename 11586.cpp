#include <iostream>
#include <string>
using namespace std;
int main()
{
	int testCase,m,f;
	cin >> testCase;
	string s;
	while(testCase--)
	{
		m=0;f=0;
		cin >> ws;
		getline(cin,s);
		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i]=='M')m++;
			else if(s[i]=='F')f++;
		}
		if(m==f)
		{
			if(m+f >= 4)cout << "LOOP\n";
			else cout << "NO LOOP\n";
		}
		else 
			cout << "NO LOOP\n";
	}
	return(0);
}