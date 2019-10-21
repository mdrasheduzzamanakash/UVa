#include <iostream>
using namespace std;
int main()
{
	int testCase,pathDifference;
	cin >> testCase;
	while(testCase--)
	{
		int numColumn,flag = 0;
		cin >> numColumn;
		for(int i = 0;i < numColumn;i++)
		{
			int y1,y2;
			cin >> y1 >> y2;

			if(i==0)
			pathDifference = y1 - y2;

		    if(pathDifference == (y1 - y2))
		    {
		    	continue;
		    }
		    else if(pathDifference != (y1 - y2))
		    {
		    	flag = 1;
		    }

		}
		if(flag == 0)
			cout << "yes\n";
		else if(flag == 1)
			cout << "no\n";
		if(testCase)
		cout << "\n";
	}
	return 0;
}