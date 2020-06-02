//SECTIONS/COMMENTS MARKED WITH ** (DOUBLE STAR) NEEDS UPDATE/IMPROVEMENTS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX = 1000;

//##################### CLASS DEFINITIONS #########################


class Person{
private:
    string name;
    string gender;
    string dateofBirth;
    string phoneNo;
    int age;

public:
    // Person(string n="", string g="",string d="", string p="", int a=0 ){
    //     name = n;
    // }

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

//Get person name
    string getName(){
        return name;
    }

//View person's info
    void dispInfo(){
        cout << "::: BASIC INFORMATION :::" << endl << endl;
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
    Screening(){}
    void setScreening(float temp, string currentIllness){
        this->temp = temp;
        this->currentIllness = currentIllness;
    }
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
    // MedHistory(string ongoingMed="", string previousVisit="",string famMedHist=""){

    // }
    bool insert(){
        cout << "Ongoing medications : ";
        getline(cin,ongoingMed);
        cout << "Previous visit here (date) : ";
        getline(cin, previousVisit);
        cout << "Family medical history : ";
        getline(cin, famMedHist);

        return 1;
    }

    void dispMedHistory(){

        cout << "Ongoing medications : " << ongoingMed << endl
            << "Previous visit here : " << previousVisit << endl
            << "Family medical history : " << famMedHist << endl << endl;
    }

};

class Treatment;

class Patient : public Person{
private:
    MedHistory *medHist;
    Screening *screeningResults;
    Treatment *treatmentResults;
    string time;
public:
    Patient(){
        medHist = new MedHistory;
        screeningResults = new Screening;
    }
    bool createPatient(){
        Person::create();
        medHist->insert(); //** BUG, when called here cannot input. SOLVED by adding initializing the pointer at constructor

        return 1;
    }

    //Adds screen results from the Screening class
    void addcurrentCondition(){

        // screeningResults->setScreening()
    }

    //Adds treatment results after treatment from doctor
    void addtreatmentResults(){

    }

    void dispInfo(){
        Person::dispInfo();
        cout << "::: MEDICAL HISTORY OF " << getName() <<":::"<<endl << endl;
        medHist->dispMedHistory();
        cout << endl << "-----------------------------" << endl;

    }
};

class Staff : public Person{
protected:
    string staffID;
    string role, employmentType;
    int salary;
public:
    // Staff(char s,string r ,string e, int sa)
    bool createStaff(){
        create();
        cout << "Enter staff ID : " ;
        getline(cin,staffID);
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



class Appointment{

};

//DEBUG MENU TEST (DESIGN A PROPER ONE LATER)
void debugMenu(){
    cout<< "=====MENU=====" << endl
        << "1. Add a person" << endl
        << "2. Add staff" << endl
         << "3. Add a patient" << endl
         << "4. Add a medhistory" << endl
        << "5. View person" << endl;
    cout << endl << "Choose an operation => ";
}

int main(){

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  DEBUGGING SECTION @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ COMMENT STARTS HERE


    Person *debug;
    Staff *debug2;
    Patient *debug3;
    MedHistory *debug4;
    int i=0,n=0;

    debug = new Person[MAX];
    debug2 = new Staff[MAX];
    debug3 = new Patient[MAX];
    debug4 = new MedHistory[MAX];


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
                cout <<"<<< Enter the information of the patient >>>" << endl << endl;
                debug3[n].createPatient();
                n+=1;

                break;
            case 4:
                cout <<"<<< Enter the information of the patient >>>" << endl << endl;
                debug4[n].insert();
                n+=1;

                break;
            case 5:
                //will print all of the inputted people
                cout <<"<<< Inventory of people >>>" << endl << endl;
                cout << "Total people: " << n << endl << endl;

                for(int j=0;j<n;j++){
                    cout << "### PATIENT NUMBER " << j+1<<" ###" << endl << endl;
                    debug3[j].dispInfo();

                }

                cout << endl;
                break;
            default:
                cout << "Please enter either 1,2 or 3" << endl;
                break;

        }
        cout <<endl;

    }while(i!=6);
    delete [] debug;
    delete [] debug2;
    delete [] debug3;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ END DEBUGGING @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ COMMENT ENDS HERE


}
