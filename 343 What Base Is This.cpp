#include<iostream>
#include<cstring>
using namespace std;


long long cheaker(char s[], int len, long long base)
{
    long long Dec = 0, B = 1;
    int i;
    for(i = len-1; i >= 0; i--) {
        if(s[i] >= '0' && s[i] <= '9')
            Dec += (s[i]-'0')*B;
        else
            Dec += (s[i]-'A'+10)*B;
        B *= base;
    }
    return Dec;
}





int main()
{
    char s1[50],s2[50];
    int l1,l2,b1,b2,i;
    while((cin>>s1>>s2))
    {

    l1=strlen(s1);
    l2=strlen(s2);



    int b1 = 1, b2 = 1, i;
        for(i = 0; i < l1; i++) {
            if(s1[i] >= '0' && s1[i] <= '9')
                b1 = b1 > s1[i]-'0' ? b1 : s1[i]-'0';
            else
                b1 = b1 > s1[i]-'A'+10 ? b1 : s1[i]-'A'+10;
        }
        for(i = 0; i < l2; i++) {
            if(s2[i] >= '0' && s2[i] <='9')
                b2 = b2 > s2[i]-'0' ? b2 : s2[i]-'0';
            else
                b2 = b2 > s2[i]-'A'+10 ? b2 : s2[i]-'A'+10;
        }
        b1++, b2++;


    for(;b1<=36;b1++)
    {
        for(i=b2;i<=36;i++)
        {
            if(cheaker(s1,l1,b1)==cheaker(s2,l2,i))
            {
                cout<<s1<<" (base "<<b1<<") = "<<s2<<" (base "<<i<<")"<<endl;
                goto level;
            }
        }
    }
    cout<<s1<<" is not equal to "<<s2<<" in any base 2..36"<<endl;
    level:
        i=0;
    }
return(0);

}
