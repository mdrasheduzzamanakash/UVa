#include<iostream>
#include<vector>
using namespace std;
vector<int> pure_primes;
void is_prime(int lb,int number)
{
    int i,j;
    int primes[number+1];
    for(i = 2;i <= number;i++)
    primes[i] = i;

    i=2;

    while((i*i) <= number)
    {
        if(primes[i]!=0)
        {
            for(j=2;j<number;j++)
            {
                if((primes[i]*j) > number)break;
                else
                    primes[primes[i]*j]=0;
            }
        }
        i++;
    }
    i=2;
    while(primes[i]<=number)
    {
        if(primes[i]!=0)
        {
            pure_primes.push_back(primes[i]);
        }
        i++;
    }
    for(i=0;i<pure_primes.size();i++)
        cout<<pure_primes[i]<<endl;


}

int cheaker (int value)
{
    int i=0,c=0;
    while(pure_primes[i]<=value)
    {
        if(value%pure_primes[i]==0)
            c++;
        i++;
    }
    return(c);
}

int main()
{
    int lb,number,cnt=0;
    cin>>lb>>number;
    is_prime(lb,number);
    for(int i=lb;i<=number;i++)
    {
        if(cheaker(i)==1)
            cnt++;
    }
    cout<<cnt<<endl;
    return(0);
}
