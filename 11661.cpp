#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int l,min=2000009;
	string s;
	std::vector<int> index;
	std::vector<char> character;
	level:
	min=2000009;
	while(cin >> l)
	{
		if(l==0)return(0);
		cin >> ws;
		cin >> s;
		index.clear();
		character.clear();
		for (int i = 0; i < s.size(); ++i)
		{
		 	if(s[i]=='Z'){cout << "0\n";goto level;}
		 	if(s[i]=='R' || s[i]=='D'){character.push_back(s[i]);index.push_back(i);}
	    } 

	    for(int i = 0;i < character.size();i++)
	    {
	    	if(character[i]!=character[i+1])
	    	{
	    		if(min > abs(index[i+1]-index[i]))
	    			min = abs(index[i+1]-index[i]);
	    	}
	    }
	    cout << min << endl;
	}

}