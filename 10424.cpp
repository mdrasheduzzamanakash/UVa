#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
	string name1,name2;
	cin >> ws;
	while(getline(cin,name1) && getline(cin,name2))
	{
		int temp1 = 0,temp2 = 0,sumOfname1=0,sumOfname2=0;

		int sizeName1=name1.size();
		int sizeName2=name2.size();
		for(int i=0;i<sizeName1;i++)
		{
			if(name1[i]>='a'&&name1[i]<='z')
				sumOfname1+=name1[i]-'a'+1;
			else if(name1[i]>='A'&&name1[i]<='Z')
				sumOfname1+=name1[i]-'A'+1;
		}
		for(int i=0;i<sizeName2;i++)
		{
			if(name2[i]>='a'&&name2[i]<='z')
				sumOfname2+=name2[i]-'a'+1;
			else if(name2[i]>='A'&&name2[i]<='Z')
				sumOfname2+=name2[i]-'A'+1;
		}
		levelname1:
		while(sumOfname1 > 0)
		{
			temp1+=sumOfname1%10;
			sumOfname1/=10;
		}
		if(temp1 >= 10)
		{
			sumOfname1 = temp1;
			temp1 = 0;
			goto levelname1;
		}
		levelname2:
		while(sumOfname2 > 0)
		{
			temp2+=sumOfname2%10;
			sumOfname2/=10;
		}
		if(temp2 >= 10)
		{
			sumOfname2 = temp2;
			temp2 = 0;
			goto levelname2;
		}

		if(temp1 < temp2)
			swap(temp1,temp2);
		double p = (double)temp2 / (double)temp1;
		cout << fixed << setprecision(2) << p*100 << " %" << endl;
	}
}