#include <iostream>
using namespace std;
int main()
{
	int test_case;
	double sum;
	cin>>test_case;
	while(test_case--)
	{
		sum=0;
		int fermer;
		cin>>fermer;
		while(fermer--)
		{
			double sizeYard,numberAnimals,enFri;
			cin >> sizeYard >> numberAnimals >> enFri;
			sizeYard = sizeYard/numberAnimals;
			sizeYard = sizeYard * enFri;
			sizeYard = sizeYard * numberAnimals;
			sum += sizeYard;
		}
		cout << sum <<endl;

	}
	return 0;
}