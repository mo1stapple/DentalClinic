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
    void insert(){
        cout << "Enter the patient's temperature : " ;
        cin >> temp;
        cin.ignore();
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
    void dispScreeningResults(){
        cout << "Patient's temperature : " << temp << endl
            << "Symptoms related to COVID-19 : " << currentIllness << endl << endl;
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

class Treatment{
private:
    string medicine, diagnosis, note, date;
    string dentistname;
    // Dentist *dentist;
    // Nurse *nurse;
public:
    bool insert(){
        cout << "Enter the diagnosis of the patient : ";
        getline(cin, diagnosis);
        cout << "Enter the prescribed medicine : ";
        getline(cin, medicine);
        cout << "Enter the date of treatment : ";
        getline(cin, date);
        cout << "Enter any additional instructions/note : ";
        getline(cin, note);
        cout << "Treated by : ";
        getline(cin, dentistname);

        return 1;
    }

    void dispTreatment(){
        cout << "Diagnosis of the patient : " << diagnosis << endl
         << "Prescribed medicine : " << medicine << endl
         << "Date of treatment : " << date << endl
         << "Additional instructions/note : " << note << endl
         << "Treated by : " << dentistname << endl << endl;
    }


};

class Patient : public Person{
private:
    MedHistory medHist;
    Screening screeningResults;
    // Appointment appTime;
    Treatment *treatmentResults;
    string time;
public:
    Patient(){
        treatmentResults = new Treatment;
    }
    bool createPatient(){
        Person::create();
        medHist.insert(); //Adds medical history from MedHistory class

        return 1;
    }

    //Adds screening results from the Screening class
    void addscreeningResults(){
        screeningResults.insert();
        // screeningResults->setScreening()
    }

    //Adds treatment results after getting treatment from doctor
    void addtreatmentResults(){
        treatmentResults->insert();
    }

    void dispInfo(){
        Person::dispInfo();

        cout << "::: MEDICAL HISTORY OF " << getName() <<" :::"<<endl << endl;
        medHist.dispMedHistory();

        cout << "::: SCREENING RESULTS OF " << getName() <<  " :::"<< endl << endl;
        screeningResults.dispScreeningResults();
        screeningResults.checkTemp();

        cout << "::: TREATMENT RESULTS OF " << getName() <<  " :::"<< endl << endl;
        treatmentResults->dispTreatment();
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
        cout << "Enter staff role (Nurse or Doctor): ";
        getline(cin, role);
        cout << "Enter staff employment type";
        getline(cin, employmentType);
        cout << "Enter staff salary per month" ;
        cin >> salary;

        return 1;
    }
};

class Dentist : public Staff{
public:
    Dentist();
};

class Nurse : public Staff{
public:
    Nurse();
};



class Appointment{
public:
    string appDate[MAX],basicSymptoms,scheduledTime;
private:
    // bool checkDate(string t){
    //     for(int i = 0;i<MAX<i++){
    //         if(temp == )
    //     }
    // }

    // bool proposedDate(){
    //     string temp;
    //     cout << "Enter the proposed date for appointment. Use the format DD/MM/YYYY: ";
    //     cin >> temp;
    //     checkDate(temp);
    //     //Check if the date is empty.

    //     return 1;
    // }





};

//DEBUG MENU TEST (DESIGN A PROPER ONE LATER)
void debugMenu(){
    cout<< "=====MENU=====" << endl
        << "1. Add a person" << endl
        << "2. Add staff" << endl
         << "3. Add a patient <--- CHOOSE ME PLS" << endl
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
        system("cls");

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

                cout <<endl<<"<<< Enter the information of the patient >>>" << endl << endl;
                debug3[n].createPatient();
                cout <<endl << "<< Enter the screening results of the patient >>" << endl << endl;
                debug3[n].addscreeningResults();
                cout  <<endl<< "<< Enter the treatment results of the patient >> " << endl << endl;
                debug3[n].addtreatmentResults();
                n+=1;

                system("pause");
                system("cls");

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
                system("pause");
                system("cls");
                
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
