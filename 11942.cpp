#include <iostream>
#include <vector>
using namespace std;
int main()
{
	cout << "Lumberjacks:\n";
	int tc;
	std::vector<int> v;
	cin >> tc;
	while(tc--)
	{
		bool ac=false,dc=false;
		for(int i=0;i<10;i++)
		{
			int c;
			cin >> c;
			v.push_back(c);
		}
		for(int i=0;i<9;i++)
		{
			if(v[i] < v[i+1])
				ac = true;
			else
			{
				ac = false;
				break;
			}
		}
		for(int i=0;i<9;i++)
		{
			if(v[i] > v[i+1])
				dc = true;
			else
			{
				dc = false;
				break;
			}
		}
		if(ac || dc)
			cout<<"Ordered\n";
		else
			cout <<"Unordered\n";
		v.clear();

	}
	return 0;
}
