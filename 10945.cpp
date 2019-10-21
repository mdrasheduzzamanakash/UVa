#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	string s;
	std::vector<char> sRight;
	std::vector<char> rs;
	while(1)
	{
		bool flag = true;
		sRight.clear();
		rs.clear();
		cin >> ws;
		getline(cin ,s);
		if(s == "DONE")return(0);
		for(long long int i = 0;i < s.length();i++)
		{
			if(s[i] >='a' &&s[i] <='z')
			{
				sRight.push_back(s[i]);
				rs.push_back(s[i]);
			}
			else if(s[i] >='A' &&s[i] <='Z')
			{
				s[i] = s[i] - 65 + 'a';
				sRight.push_back(s[i]);
				rs.push_back(s[i]);
			}
		}
		reverse(rs.begin(),rs.end());
		for(int i=0;i < rs.size();i++)
		{
			if(rs[i] != sRight[i])
			{
				flag = false;break;
			}
		}
		if(flag)cout << "You won't be eaten!\n";
		else cout << "Uh oh..\n";
	}

}