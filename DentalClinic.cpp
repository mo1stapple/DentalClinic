#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX = 1000;

class Person{
private:
    string name;
    string gender;
    string dateofBirth;
    string phoneNo;
    int age;

public:
    Person(string n="", string g="",string d="", string p="", int a=0 ){
        name = n;
    }

//Create new person
    bool create(){
        cin.ignore();
        cout << "Name : " ;
        getline(cin,name);
        cout << "Age : ";
        cin >> age;
        cin.ignore();
        cout << "Gender : ";
        getline(cin, gender);
        cout << "Date of Birth : ";
        getline(cin,dateofBirth);
        cout << "Phone Number : ";
        getline(cin,phoneNo);

        return 1;

    }
//Update person's info
    bool update();
    
//View person's info
    void dispInfo(){
        cout << "Name : " << name << endl;
        cout << "Age : "<<age << endl;
        cout << "Gender : "<<gender<< endl;
        cout << "Date of Birth : "<<dateofBirth<< endl;
        cout << "Phone Number : "<<phoneNo<< endl << endl;
    }
};

class Patient 


//DEBUG MENU TEST
void debugMenu(){
    cout<< "=====MENU=====" << endl
        << "1. Add a person" << endl
        << "2. Display people" << endl
        << "3. Exit" << endl;
    cout << endl << "Choose an operation => ";
}

int main(){

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  DEBUGGING SECTION @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ COMMENT STARTS HERE

    Person *debug;
    int i=0,n=1;

    debug = new Person[MAX];

    //TESTING THE RECORD SAVING FUNCTION
    do{
        debugMenu();
        cin >> i;
        cout << endl;

        switch(i){
           case 1:
                cout <<"<<< Enter the information of the person >>>" << endl << endl;
                debug[n].create();
                n+=1;

                break;
        case 2:
                //will print all of the inputted people
                cout <<"<<< Inventory of people >>>" << endl << endl;
                cout << "Total people: " << n << endl << endl;

                for(int j=0;j<n;j++){
                    cout << "Patient number " << j+1 << endl;
                    debug[j].dispInfo();

                }

                cout << endl;
                break;
        default:
                cout << "Please enter either 1,2 or 3" << endl;
                break;

        }
        cout <<endl;

    }while(i!=3);
    // ship[0].print();
    delete [] debug;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ END DEBUGGING @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ COMMENT ENDS HERE


}
