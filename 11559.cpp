#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	long long int min=0;
	vector<long long int> v;
	vector<long long int> v1;
		long long int numPerticipents,budget,numHotel,numWeekend;
		long long int hotelPrice;
		cin >> numPerticipents >> budget >> numHotel >> numWeekend;
		while(numHotel--)
		{
			cin >> hotelPrice;
			for(long long int i = 0;i < numWeekend;i++)
			{
				long long int tempValue;
				cin >> tempValue;
				v.push_back(tempValue);
			}
			sort(v.rbegin(),v.rend());
			if(v[0] >= numPerticipents)
			{
				min = (numPerticipents * hotelPrice);
				v1.push_back(min);
			}
			v.clear();

		}
		sort(v1.begin(),v1.end());
		if(budget<v1[0])
			cout<<"stay home\n";
		else
			cout << v1[0]<<"\n";

		v1.clear();
	return 0;
}
