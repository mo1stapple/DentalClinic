#include <iostream>
#include <string>

using namespace std;

class Person{
private:
    string name;
    string dateofBirth;
    string phoneNo;
    int age;

public:
    Person(string n="", string d="", string p="", int a=0 ){
        name = n;
    }

    bool create(){
        cout << "Name :" ;
        getline(cin,name);
        cout << "Gender :";
        getline(cin, gender);
    }
    void dispInfo(){
        cout << name << gender;
    }
};

int main(){
    Person p1;

    p1.create();
    p1.dispInfo();
}
