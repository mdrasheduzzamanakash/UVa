/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int  h,l,min = 90000000,k;
	std::vector<int> v;
	while(cin >> h >> l)
	{
		min = 90000000;
		k=0;
		v.clear();
		if(h == 0 && l == 0 )return(0);
		while(l--)
		{
			int k;cin>>k;
			if(min > k)min = k;
			v.push_back(k);
		}
		min = h - min;
		for (int i = 0; i < v.size(); i++)
		{
			if(v[i] == v[i+1])k++;
		}
		sort(v.begin(),v.end());

		for(int i = 0;i < v.size();i++) 
		{
			if(v[i] == v[i+1])min++;
		}
		cout << min - k << endl;

	}
}*/
/*#include <iostream>
using namespace std;
int main()
{
	int h,l,tot,last;
	while(cin >> h >> l)
	{
		if(h == 0 || l == 0)return(0);
		tot = 0;
		last = h;
		for(int i=0;i < l;i++)
		{
			int k;
			cin >> k;
			if(last > k)
			{
				tot += (last - k);
			}
			last = k;
		}
		cout << tot << endl;
	}
}*/

