#include <iostream>
using namespace std;
int main()
{
	int sum_mile,sum_juice,test,cnt=1;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		sum_mile = 0,sum_juice = 0;
		while(n--)
			{
				int value;
				cin >> value;
				sum_mile+=(value/30)*10 + 10;
				sum_juice+=(value/60)*15 +15;
			}
			if(sum_juice < sum_mile)
				cout << "Case " << cnt++ <<": Juice " << sum_juice << endl;
			else if(sum_mile < sum_juice)
				cout << "Case " << cnt++ <<": Mile " << sum_mile << endl;
			else
				cout << "Case " << cnt++ <<": Mile Juice " << sum_juice << endl;
	}
	return 0;
}