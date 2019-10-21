#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int numOfReq,numOfRFT;
	string tempString;
	double minPrice,maxComplience;
	int maxMet;
	int flagP = 0;
	int flagC = 0;
	std::vector<string> name;
	std::vector<int> metReq;
	std::vector<double> price;
	std::vector<double> complience;
	while(cin >> numOfReq >> numOfRFT)
	{
		if(numOfReq == 0 && numOfRFT == 0)
		return(0);
	name.clear();
	metReq.clear();
	price.clear();
	complience.clear();
	maxComplience = minPrice = 0;
	maxMet = 0;
	int flagP = flagC = 0;
	while(numOfReq--)
	{
		cin >> ws;
		cin >> tempString;
	}
	for(int i = 0;i < numOfRFT;i++)
	{
		cin >> ws;
		cin >> tempString;
		name.push_back(tempString);
		double tempPrice;
		cin >> tempPrice;
		price.push_back(tempPrice);
		int tempMet;
		cin >> tempMet;
		metReq.push_back(tempMet);
		while(tempMet--){cin >> ws;cin >> tempString;}
		double tempcom = (tempMet/numOfReq);
		complience.push_back(tempcom);

		if(i == 0){maxMet = tempMet;minPrice = tempPrice;maxComplience = tempcom;}

		if(maxComplience < tempcom)maxComplience = tempcom;
		if(maxComplience == tempcom)flagC = 1;

		if(minPrice > tempPrice)minPrice = tempPrice;
		if(minPrice == tempPrice)flagP = 1;

	}
	if(flagC == 0)
	{
		for(int i=0;i < complience.size();i++)
		{
			if(complience[i] == maxComplience)
				break;
		}
		cout << name[i] <<  endl;
		continue;
	}
	else if(flagP == 0)
	{
		for(int i=0;i < price.size();i++)
		{
			if(price[i] == minPrice)
				break;
		}
		cout << name[i] <<  endl;
		continue;
	}
	else
	{
		for(int i=0;i < price.size();i++)
		{
			if(minPrice == price[i])
				break;
		}
		cout << name[i] << endl;
		continue;
	}
	}

	return(0);
}