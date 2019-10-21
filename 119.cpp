#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	int t=0;
	int numOfMembers;
	while(cin >> numOfMembers)
	{
	map <string,int> m;
	vector<string> v;
	for(int i=0;i < numOfMembers;i++)
	{
		string tempName;
		int value = 0;
		cin >> tempName;
		v.push_back(tempName);
		m.insert(pair<string,int>(tempName,value));

	}


	while(numOfMembers--)
	{
		string name;
		int giftMoney,numOfReceivers;
		cin >> name >> giftMoney >> numOfReceivers;
		if(numOfReceivers == 0)
			continue;
		int canGive = giftMoney / numOfReceivers;
		int saveMoney = giftMoney - (canGive*numOfReceivers);
		m[name] -= giftMoney;
		m[name] += saveMoney;
		while(numOfReceivers--)
		{
			string stringNameOfReceivers;
			cin >> stringNameOfReceivers;
			m[stringNameOfReceivers] += canGive;
		}
	}


	if(t>0)
		cout << endl;
	for(int i=0;i < v.size();i++)
	{
		cout << v[i] << " ";
		cout << m[v[i]] << "\n";
	}
	t++;
	}
	return 0;
}