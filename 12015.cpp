#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    int tc,max=0,cnt=1;
    std::vector<string> stringVector;
    std::vector<int> index;
    cin >> tc;
    while(tc--)
    {
        stringVector.clear();
        index.clear();
        max=0;
        for(int j=0;j<10;j++)
        {
            string s;
            int temp;
            cin >> s;
            cin >> temp;
            stringVector.push_back(s);
            index.push_back(temp);
            if(max<temp)max=temp;
        }

        for(int i=0;i<10;i++)
        {
            if(i == 0)
            {
                cout << "Case #" << cnt++ << ":\n";
            }
            if(index[i] == max)
            {
                cout << stringVector[i] <<"\n";
            }
        }
    }
}
