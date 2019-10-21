#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s,s1;
	double price,complience;
	int metRequirements,numOfRequirements,numOfRFP;
	level:
	while(cin >> numOfRequirements >> numOfRFP)
	{
		std::vector<string> nameOfRequirements;
		std::vector<pair <double, string> > initialDataOfRFP;
		std::map<double, string> mapOfComplienceName1;
		std::map<double, string> mapOfPriceName;
		mapOfPriceName.clear();
		mapOfComplienceName1.clear();
		initialDataOfRFP.clear();
		nameOfRequirements.clear();

		map<double, string>::iterator it;
		vector<pair <double, string> > ::iterator itt;
		while(numOfRequirements--)
		{
			cin >> ws;
			getline(cin,s);
			nameOfRequirements.push_back(s);
		}

		while(numOfRFP--)
		{
			cin >> ws;
			getline(cin,s);
			cin >> price >> metRequirements;
			complience = metRequirements / numOfRequirements;
			while(metRequirements--)
			{
				cin.sync();
				getline(cin,s1);
			}
			mapOfComplienceName1.insert(pair<double,string>(complience,s));
			mapOfPriceName.insert(pair<double,string>(price,s));
		}
		map<double, string>mapOfComplienceName(mapOfComplienceName1.rbegin(),mapOfComplienceName1.rend());
		double a,b;
		it = mapOfComplienceName.begin();
		a = it->first;
		it++;
		b = it->first;
		if(a != b)
		{
			it = mapOfComplienceName.begin();
			cout << it->second << endl;
		}
		else if(a == b)
		{
			it = mapOfPriceName.begin();
			a = it->first;
			it++;
			b = it->first;
			if(a != b)
			{
				it = mapOfPriceName.begin();
				cout << it->second << endl;
			}
			else if(a == b)
			{
				for(itt = initialDataOfRFP.begin(); itt != initialDataOfRFP.end();itt++)
				{
					if(itt->first == a)
						cout << itt->second << endl;
					goto level;
				}
			}
		}
	}
	return(0);
}
