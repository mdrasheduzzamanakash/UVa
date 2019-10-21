#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int yPositive=0,yNegative=0,zPositive=0,zNegative=0;
	int sumy = 0,sumz = 0,l;
	string s,direction;
	std::vector<string> v;
	level:
	while(cin >> l)
	{
		v.clear();
		if(l==0)return(0);
		if(l==1){cout << "+x" << endl;goto level;}
		yPositive=yNegative=zPositive=zNegative=0;
		for (int i = 1; i < l; ++i)
		{
			cin >> ws;
			cin >> s;
			v.push_back(s);
			if(s == "+y")yPositive++;
			else if(s == "-y")yNegative++;
			else if(s == "+z")zPositive++;
			else if(s == "-z")zNegative++;
		}

		for(int i=0;i < v.size();i++)
		{
			if(v[i]!="No"){direction = v[i];break;}
		}


		//for y section
		sumy = abs(yPositive - yNegative);
		sumz = abs(zPositive - zNegative);
		if(direction == "+y" || direction == "-y")
		{
			if(sumy%4 == 0)cout << "+x" << endl;
			else if(sumy%2 == 0)cout << "-x" << endl;
			else if(sumy%4 == 1 && (yPositive > yNegative))cout << "+y" <<endl;
			else if(sumy%4 == 1 && (yNegative > yPositive))cout << "-y" << endl;
			else if(sumy%4 == 3 && (yPositive < yNegative))cout << "+y" << endl;
			else if(sumy%3 == 3 && (yPositive > yNegative))cout << "-y" << endl;
		}
		else if(direction == "+z" || direction == "-z")
		{
			if(sumz%4 == 0)cout << "+x" << endl;
			else if(sumz%2 == 0)cout << "-x" << endl;
			else if(sumz%4 == 1 && (zPositive > zNegative))cout << "+z" <<endl;
			else if(sumz%4 == 1 && (zNegative > zPositive))cout << "-z" << endl;
			else if(sumz%4 == 3 && (zPositive < zNegative))cout << "+z" << endl;
			else if(sumz%3 == 3 && (zPositive > zNegative))cout << "-z" << endl;
		}
		cin >> ws;

	}
}