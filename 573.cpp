#include <iostream>
using namespace std;
int main()
{
	double height,climbingDistance,downDistance,fatigFactor,sum;
	int numDay;
	while(cin >> height >> climbingDistance >> downDistance >> fatigFactor)
	{
		if(height == 0)return(0);
		numDay =0;
		sum = 0;
		fatigFactor = fatigFactor / 100;
		fatigFactor = fatigFactor * climbingDistance;
		while(1)
		{
			numDay++;
			if(climbingDistance > 0)
				sum += climbingDistance;
				climbingDistance -= fatigFactor;
			if(sum > height)
				break;
			sum -= downDistance;
			if(sum < 0)
				break;

		}
		if(sum > 0)
			cout << "success on day " << numDay << endl;
		else 
			cout << "failure on day " << numDay << endl;
	}
	return 0;
}
