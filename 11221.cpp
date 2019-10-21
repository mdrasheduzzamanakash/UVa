#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string convert(const std::string& sen){
  int size = sen.size();
  string line = "";
  for(int i = 0; i < size; i++ ){
    if(sen[i] >= 'a' && sen[i] <= 'z')
    line += sen[i];
  }
  return line;
}

int cheak(const std::string conSen){
  int len = conSen.size();
  int s = sqrt(len);
  if((s * s) != len){
    return (-1);
  }
  int end = conSen.size() - 1;
  int till = end / 2;
  for(int j = 0; j < end; j++)
  {
      if(conSen[j] != conSen[end - j])
      return -1;
  }
  return s;
}



int main(){
  int test;
  cin >> test;
  cin.ignore();
  for(int i = 0; i < test; i++)
  {
    string sen;
    string conSen;
    getline(cin , sen);
    conSen = convert(sen);
    int flag = cheak(conSen);
    cout <<"Case #" << i + 1 << ":" << endl;
    if(flag == -1)cout << "No magic :(\n";
    else cout << flag << endl;
  }
  return 0;
}
