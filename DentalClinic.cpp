//SECTIONS/COMMENTS MARKED WITH ** (DOUBLE STAR) NEEDS UPDATE/IMPROVEMENTS
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
//**Update person's info
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

//Nurse will do the screening before the patient is treated by dentist
class Screening{
private:
    float temp;
    string currentIllness;
public:
    Screening();

    void inputScreen(){
        cout << "Enter the patient's temperature : " ;
        cin >> temp;
        cout << "Enter the patient's current symptoms related to COVID-19 (if any) : ";
        getline(cin, currentIllness);
    }
    bool checkTemp(){
        if(this->temp >37.5){
            cout << "Fever detected. Appointment will be declined. Thank you for coming and stay healthy" << endl;
            return 1;
        }
        else{
            cout << "No fever detected. Patient's Appointment accepted. Please wait for your turn." << endl;
            return 0;
        }
    }


};

//**
class MedHistory{
private:
    string ongoingMed,previousVisit,famMedHist;
public:
    MedHistory(string ongoingMed="", string previousVisit="",string famMedHist=""){

    }
    bool insert(){
        cout << "Ongoing medications : ";
        getline(cin,ongoingMed);
        cout << "Previous visit here (date) : ";
        getline(cin, previousVisit);
        cout << "Family medical history : ";
        getline(cin, famMedHist);

        return 1;
    }

};

class Patient : public Person{
private:

public:
};

class Staff : public Person{
protected:
    char staffID[20];
    string role, employmentType;
    int salary;
public:
    // Staff(char s,string r ,string e, int sa)
    bool createStaff(){
        create();
        cout << "Enter staff ID : " ;
        cin >> staffID;
        cout << "Enter staff role : ";
        getline(cin, role);
        cout << "Enter staff employment type";
        getline(cin, employmentType);
        cout << "Enter staff salary per month" ;
        cin >> salary;

        return 1;
    }
};

class Dentist : public Staff{

};

class Nurse : public Staff{

};

class Treatment{
private:
    string medicine,symptoms,notes,date;

public:
    bool setTreatment(){
        cout << "Enter the patient's type of medicine : ";
        getline(cin, medicine);
        cout << "Enter the patient's symptoms : ";
        getline(cin, symptoms);
        cout << "Enter additional notes/instructions : ";
        getline(cin, notes);

        return 1;
    }

};

class Appointment{

};

//DEBUG MENU TEST (DESIGN A PROPER ONE LATER)
void debugMenu(){
    cout<< "=====MENU=====" << endl
        << "1. Add a person" << endl
        << "2. Add staff" << endl
        << "3. View person" << endl;
    cout << endl << "Choose an operation => ";
}

int main(){

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  DEBUGGING SECTION @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ COMMENT STARTS HERE


    Person *debug;
    Staff *debug2;
    int i=0,n=1;

    debug = new Person[MAX];
    debug2 = new Staff[MAX];


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
                cout <<"<<< Enter the information of the staff >>>" << endl << endl;
                debug2[n].createStaff();
                n+=1;

                break;
        case 3:
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
    delete [] debug;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ END DEBUGGING @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ COMMENT ENDS HERE


}
