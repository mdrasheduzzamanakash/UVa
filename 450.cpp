#include <bits/stdc++.h>
using namespace std;

struct faculty{
    string dept;
    string title;
    string first_name;
    string last_name;
    string street_add;
    string home_p;
    string work_p;
    string campus_box;
};

map<string,faculty> m;

int main(){
    int n;
    cin >> n;
    cin >> ws;
    while(n--){
        string department,line,temp;
        getline(cin,department);
        cin >> ws;
        while(getline(cin,line)){
            if(line.length() == 0)break;
            //now extracting the information from line
            //information are seperated by comma(,)
            //.....................................
            //....now creating an persons information for PR
            faculty person;
            person.dept = department;
            int k = 0,f = 0,l = line.find(',');
            temp = line.substr(f,l-f);
            person.title = temp;
            while(l != string::npos){
                k++;
                f = l+1;
                l = line.find(',',f);
                temp = line.substr(f,l-f);
                if(k == 1)
                    person.first_name = temp;
                else if(k == 2)
                    person.last_name = temp;
                else if(k == 3)
                    person.street_add = temp;
                else if(k == 4)
                    person.home_p = temp;
                else if(k == 5)
                    person.work_p = temp;
                else if(k == 6)
                    person.campus_box = temp;
            }
            m[person.last_name] = person;
        }
    }


    //whoooh!!!!
    //now printing
    for(map<string,faculty>::iterator i = m.begin();i != m.end();i++){
        puts("----------------------------------------");
        cout << i->second.title << " " << i->second.first_name << " " << i->second.last_name << "\n"
            << i->second.street_add <<"\n"
            << "Department: " << i->second.dept << "\n"
            << "Home Phone: " << i->second.home_p << "\n"
            << "Work Phone: " << i->second.work_p << "\n"
            << "Campus Box: " << i->second.campus_box << "\n";
    }

    return 0;
}