#include <iostream>
#include<vector>
using namespace std;
int main()
{

	int numOfDevice,numOfOperation,capacity,sum = 0,cnt = 1,Maximal;
	std::vector<int> consumption;
	std::vector<bool> state;
	while(cin >> numOfDevice >> numOfOperation >> capacity)
	{
		sum = 0;
		Maximal = 0;
		consumption.clear();
		state.clear();
		if(numOfDevice == 0 && numOfOperation == 0 && capacity == 0)
			return(0);
		while(numOfDevice--)
		{
			int temp;
			cin >> temp;
			consumption.push_back(temp);
			state.push_back(false);
		}
		for(int i = 0;i < numOfOperation;i++)
		{
			int temp;
			cin >> temp;
			if(!state[temp-1])
			{
				sum += consumption[temp-1];
				state[temp-1] = true;
			}
			else
			{
				sum -= consumption[temp-1];
				state[temp-1] = false;
			}

			if(Maximal < sum)
				Maximal = sum;
		}
		if(sum > capacity)
		{
			cout << "Sequence " << cnt++ << endl;
			cout << "Fuse was blown." << endl;
		}
		else
		{
			cout << "Sequence " << cnt++ << endl;
			cout << "Fuse was not blown."<< endl;
			cout <<"Maximal power consumption was "<< Maximal <<" amperes." << endl;
		}
		cout << endl;
	}
}