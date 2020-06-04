//SECTIONS/COMMENTS MARKED WITH ** (DOUBLE STAR) NEEDS UPDATE/IMPROVEMENTS
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

const int MAX = 100;
const int MAXDATE = 50;

string availableTime[MAXDATE]={  "10/06/2020 - 9:00 A.M", "12/06/2020 - 9:00 A.M", "15/06/2020 - 9:00 A.M", "18/06/2020 - 9:00 A.M", "19/06/2020 - 9:00 A.M",
                    "22/06/2020 - 9:00 A.M", "23/06/2020 - 9:00 A.M", "26/06/2020 - 9:00 A.M", "01/07/2020 - 9:00 A.M", "14/07/2020 - 9:00 A.M",
                    "22/07/2020 - 9:00 A.M", "28/07/2020 - 9:00 A.M", "04/08/2020 - 9:00 A.M", "28/08/2020 - 9:00 A.M", "31/08/2020 - 9:00 A.M",
                    "09/09/2020 - 9:00 A.M", "16/09/2020 - 9:00 A.M",  "29/10/2020 - 9:00 A.M","17/11/2020 - 9:00 A.M", "18/11/2020 - 9:00 A.M",
                    "26/11/2020 - 9:00 A.M","14/12/2020 - 9:00 A.M","17/12/2020 - 9:00 A.M","21/12/2020 - 9:00 A.M","30/12/2020 - 9:00 A.M",
                    "10/06/2020 - 2:00 P.M","12/06/2020 - 2:00 P.M","15/06/2020 - 2:00 P.M","18/06/2020 - 2:00 P.M","19/06/2020 - 2:00 P.M",
                    "22/06/2020 - 2:00 P.M","23/06/2020 - 2:00 P.M","26/06/2020 - 2:00 P.M","01/07/2020 - 2:00 P.M","14/07/2020 - 2:00 P.M",
                    "22/07/2020 - 2:00 P.M","28/07/2020 - 2:00 P.M","04/08/2020 - 2:00 P.M","28/08/2020 - 2:00 P.M","31/08/2020 - 2:00 P.M",
                    "09/09/2020 - 2:00 P.M","16/09/2020 - 2:00 P.M","29/10/2020 - 2:00 P.M","17/11/2020 - 2:00 P.M","18/11/2020 - 2:00 P.M",
                    "26/11/2020 - 2:00 P.M","14/12/2020 - 2:00 P.M","17/12/2020 - 2:00 P.M","21/12/2020 - 2:00 P.M","30/12/2020 - 2:00 P.M"};

string appDate[MAXDATE];

void welcomeInterface(){

    cout <<"\n\n\n\t\t\t\t" << "---------------------------------------------------------" <<endl;
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" <<"|"<<"\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" <<"|"<<"\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" <<"|"<<"\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" <<"|"<<"\n";
    cout << "\t\t\t\t" << "|" << "\tWELCOME TO DENTAL CLINIC MANAGEMENT SYSTEM\t" <<"|"<<"\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" <<"|"<<"\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" <<"|"<<"\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" <<"|"<<"\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\tBY: TEAM CORONA\t" <<"|"<<"\n";


    cout <<"\t\t\t\t" << "---------------------------------------------------------" << "\n\n\n\n\n\n\n\n\n";
    system("pause");
    system("cls");
}

void drawMenu(){

    // cout <<"\n\n\n\t\t" << "DENTAL CLINIC MANAGEMENT SYSTEM" <<endl;
    cout <<"\n\n\n\n\t\t\t\t\t" <<"     DENTAL CLINIC MANAGEMENT SYSTEM"  <<endl;
    cout <<"\n\t\t\t\t" <<"---------------------------------------------------------" <<endl;
    cout << "\t\t\t\t" << "|" << "                                                       " <<"|\n";
    cout << "\t\t\t\t" << "|" << "  1. Add a patient                                     " <<"|\n";
    cout << "\t\t\t\t" << "|" << "  2. Update patient record                             " <<"|\n";
    cout << "\t\t\t\t" << "|" << "  3. View patient record                               " <<"|\n";
    cout << "\t\t\t\t" << "|" << "  4. View staff record                                 " <<"|\n";
    cout << "\t\t\t\t" << "|" << "  5. View appointed dates                              " <<"|\n";
    cout << "\t\t\t\t" << "|" << "  6. Exit                                              " <<"|\n";
    cout << "\t\t\t\t" << "|" << "                                                       " <<"|\n";
    cout << "\t\t\t\t" << "|" << "                                                       " <<"|\n";
    cout << "\t\t\t\t" << "---------------------------------------------------------" <<"\n\n\n\n\n\n\n";
    cout << "Choose an operation => " ;

}


//##################### CLASS DEFINITIONS #########################


class Person{
private:

public:
    //Public kan benda ni semua bab kalau Private polymorph x jadi
    string name;
    string gender;
    string dateofBirth;
    string phoneNo;
    int age;
    // Person(string n="", string g="",string d="", string p="", int a=0 ){
    //     name = n;
    // }

//Create new person
//Polymorph 1
    virtual bool create()=0;
        // cin.ignore();


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
    Screening(){
        temp = 0.0;
        currentIllness ="NOT YET SCREENED";
    }
    void setScreening(float temp, string currentIllness){
        this->temp = temp;
        this->currentIllness = currentIllness;
    }
    bool insert(){
        cout << "Enter the patient's temperature : " ;
        cin >> temp;
        cin.ignore();
        cout << "Enter the patient's current symptoms related to COVID-19 (if any) : ";
        getline(cin, currentIllness);

        if(checkTemp())
            return 1;
        else
            return 0;


    }
    //This condition will determine whether the patient will be accepted or not
    bool checkTemp(){
        if(temp >37.5){
            cout <<endl<< "Fever detected. Appointment will be declined. Thank you for coming and stay healthy. \n" << endl;
            return 0;
        }
        else if(this->temp>30 && this->temp<37.5){
            cout <<endl<< "No fever detected. Patient's Appointment accepted. Please wait for your turn. \n" << endl;
            return 1;
        }
    }
    void dispScreeningResults(){
        cout << "Patient's temperature : " << temp << endl
            << "Symptoms related to COVID-19 : " << currentIllness << endl << endl;
    }


};


class MedHistory{
private:
    string ongoingMed,previousVisit,famMedHist;
public:

    bool insert(){
        cout << "Ongoing medications : ";
        getline(cin,ongoingMed);
        cout << "Previous visit here (date) : ";
        getline(cin, previousVisit);
        cout << "Family medical history : ";
        getline(cin, famMedHist);

        return 1;
    }

    friend ostream &operator<<(ostream &strm, MedHistory &obj){

        strm << "Ongoing medications : " << obj.ongoingMed << endl
            << "Previous visit here : " << obj.previousVisit << endl
            << "Family medical history : " << obj.famMedHist << endl << endl;
        return strm;
    }

};

//OVERLOAD OPERATOR<<


class Treatment{
protected:
    string medicine, diagnosis, note, date;
    string dentistname;
    Screening checkScreening;
public:
    Treatment(){
        if(checkScreening.checkTemp()){
            cout << "test";
        }
        else{
            medicine = "NOT YET TREATED";
            diagnosis = "NOT YET TREATED";
            note ="NOT YET TREATED";
            date = "NOT YET TREATED";
            dentistname ="NOT YET TREATED";
        }
    }
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

    friend ostream &operator<<(ostream &strm, Treatment &obj){
        strm << "Diagnosis of the patient : " << obj.diagnosis << endl
         << "Prescribed medicine : " << obj.medicine << endl
         << "Date of treatment : " << obj.date << endl
         << "Additional instructions/note : " << obj.note << endl
         << "Treated by : " << obj.dentistname << endl << endl;

         return strm;
    }



};

//OVERLOAD OPERATOR<<



class Staff : public Person{
protected:
    string staffID;
    string role, employmentType;
    int salary;
public:

    bool create(){

        //polymorph create() method
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

private:
    string expertise;
public:
    Dentist();
    //polymorph
    bool create(){
     cout << "Name of Dentist: " ;
        getline(cin,name);
        cout << "Age of Dentist: ";
        cin >> age;
        cin.ignore();
        cout << "Gender : ";
        getline(cin, gender);
        cout << "Date of Birth : ";
        getline(cin,dateofBirth);
        cout << "Phone Number : ";
        getline(cin,phoneNo);
        cout << "Enter staff ID : " ;
        getline(cin,staffID);
        role = "Dentist";
        cout << "Enter expertise : " ;
        getline(cin,expertise);
        cout << "Enter staff employment type";
        getline(cin, employmentType);
        cout << "Enter staff salary per month" ;
        cin >> salary;

        return 1;
    }

    friend ostream &operator<<(ostream &strm, Dentist &obj){
     strm << "::: DENTIST INFORMATION :::" << endl << endl;
        strm << "Name           : "<< obj.name << endl;
        strm << "Age            : "<<obj.age << endl;
        strm << "Gender         : "<<obj.gender<< endl;
        strm << "Date of Birth  : "<<obj.dateofBirth<< endl;
        strm << "Phone Number   : "<<obj.phoneNo<< endl << endl;
        strm << "ID             : "<<obj.staffID<< endl << endl;
        strm << "Expertise      : "<<obj.expertise << endl << endl;
        strm << "Employment Type: "<<obj.employmentType << endl << endl;
        strm << "Salary         : "<<obj.salary << endl << endl;

        return strm;
    }
};



class Nurse : public Staff{
public:
    Nurse();
    //polymorph
     bool create(){
     cout << "Name of Nurse: " ;
        getline(cin,name);
        cout << "Age of Nurse: ";
        cin >> age;
        cin.ignore();
        cout << "Gender : ";
        getline(cin, gender);
        cout << "Date of Birth : ";
        getline(cin,dateofBirth);
        cout << "Phone Number : ";
        getline(cin,phoneNo);

        cout << "Enter staff ID : " ;
        getline(cin,staffID);
        role = "Nurse";
        cout << "Enter staff employment type";
        getline(cin, employmentType);
        cout << "Enter staff salary per month" ;
        cin >> salary;

        return 1;
    }

    friend ostream &operator<<(ostream &strm, Nurse &obj){
     strm << "::: NURSE INFORMATION :::" << endl << endl;
        strm << "Name           : "<< obj.name << endl;
        strm << "Age            : "<<obj.age << endl;
        strm << "Gender         : "<<obj.gender<< endl;
        strm << "Date of Birth  : "<<obj.dateofBirth<< endl;
        strm << "Phone Number   : "<<obj.phoneNo<< endl << endl;
        strm << "ID             : "<<obj.staffID<< endl << endl;
        strm << "Employment Type: "<<obj.employmentType << endl << endl;
        strm << "Salary         : "<<obj.salary << endl << endl;

        return strm;
    }

};




class Appointment{
private:
    string basicSymptoms,scheduledTime;

public:
    static int count;

    void drawSchedule(){
        for(int i=0; i<MAXDATE; i++){
            if(i == 0)
                cout <<endl<< "------------------9:00 A.M------------------" <<endl << endl;
            if(i ==25)
                cout <<endl<< "------------------2:00 P.M------------------" <<endl << endl;
            cout << availableTime[i] << " -> " << i << endl;
        }
    }

    bool checkDate(string chosenTime,int chosenNum){
        //Traverses through all of the elements in the array and check for same date
        for(int i = 0;i<MAXDATE;i++){
            if(chosenTime!="###### FULL ######" && i==count){
                appDate[count] = chosenTime;
                availableTime[chosenNum] = "###### FULL ######";
                ++count;
                return 1;
            }
            else if(i!=count){

                continue;
            }
            else
                return 0;
        }
    }


    bool proposedDate(){
        int temp;
        string tempdate;

        drawSchedule();

        do{
            cout <<endl<< "Enter the proposed date for appointment. Choose one of these dates by putting the number 0 to 49 : " ;
            cin >> temp;
            cout << endl;
            tempdate = availableTime[temp];
            if(checkDate(tempdate,temp)){
                cin.ignore();
                cout <<"The date is accepted. Please enter the basic symptoms about the patient : ";
                getline(cin, basicSymptoms);
                break;
            }
            else{
                cout << "The date is full!. Please choose another date." << endl;
                continue;
            }
        }while(temp<0 || temp>49);

        return 1;
    }

};

//Initialize static int in Appointment class
int Appointment::count = 0;

class Patient : public Person{
private:
    MedHistory medHist;
    Screening screeningResults;
    Appointment appTime;
    Treatment *treatmentResults;
    string time;
public:
    Patient(){
        treatmentResults = new Treatment;
    }
    //polymorph
    bool create(){
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

        medHist.insert(); //Adds medical history from MedHistory class

        return 1;
    }
    void addAppointmentTime(){
        appTime.proposedDate();
    }

    //Adds screening results from the Screening class
    bool addscreeningResults(){
        if(screeningResults.insert()){
            return 1;
        }
        else{
            return 0;
        }
    }

    //Adds treatment results after getting treatment from doctor
    void addtreatmentResults(){
        treatmentResults->insert();
    }

    friend ostream &operator<<(ostream &strm, Patient obj){

        obj.Person::dispInfo();

        strm << "::: MEDICAL HISTORY OF " << obj.getName() <<" :::"<<endl << endl;
        strm <<obj.medHist; //here VJ

        strm << "::: SCREENING RESULTS OF " << obj.getName() <<  " :::"<< endl << endl;
        obj.screeningResults.dispScreeningResults();
        obj.screeningResults.checkTemp();

        strm << "::: TREATMENT RESULTS OF " << obj.getName() <<  " :::"<< endl << endl;
        strm << *obj.treatmentResults;
        strm << endl << "-----------------------------" << endl;

        return strm;



    }


};


int main(){

    // Staff *staff;
    Appointment *appoint;
    Patient *patient;
    appoint = new Appointment[MAX];
    patient = new Patient[MAX];
    // staff = new Staff[MAX];

    //Nak sekalikan Dentist ngan Nurse bawah satu ptr. Tapi xleh create object Person.. ptr je.
    //kene disable baru leh run :v
    // Person *stf;

    // Dentist amir;
    // amir.create();

    // Nurse farah, hana;
    // farah.create();
    // hana.create();

    // Person staff[3] = { &amir, &farah, &hana };



    int chooseMenu=0, n=0,choosePatient=0;

    welcomeInterface();
    menu:
    do{
        drawMenu();
        cin >> chooseMenu;
        system("cls");
        switch(chooseMenu){
            case 1:
                patient[n].addAppointmentTime();
                cout << "\n <<< ENTER BASIC INFORMATION AND MEDICAL HISTORY OF PATIENT >>> \n\n";
                patient[n].create();
                cout << "\n @@@ Patient's information has been added to the database. @@@\n @@@ Nurses will do the screening on the appointed day. @@@ \n\n ";
                system("pause");
                system("cls");
                n+=1;
                break;
            case 2:
                for(int j=0;j<n;j++){
                    cout << "### PATIENT NUMBER " << j+1<<" ###" << endl << endl;
                    cout<<patient[j];//here VJ 1) cun
                }
                cout <<"\n <<< CHOOSE WHICH PATIENT TO UPDATE BY ENTERING PATIENTS NUMBER (1,2,5,ETC) >>> \n\n";
                cin >> choosePatient;
                cout << "\n <<< ENTER THE SCREENING RESULTS OF PATIENT >>> \n\n";
                patient[choosePatient-1].addscreeningResults();
                cout << "\n <<< ENTER THE TREATMENT RESULTS OF PATIENT >>> \n\n";
                patient[choosePatient-1].addtreatmentResults();
                system("pause");
                system("cls");

                break;
            case 3:
                cout <<"<<< LIST OF PATIENT >>>" << endl << endl;
                cout << "TOTAL PATIENT: " << n << endl << endl;
                for(int j=0;j<n;j++){
                    cout << "### PATIENT NUMBER " << j+1<<" ###" << endl << endl;
                    cout <<patient[j];//here also 1) cun
                }
                cout << endl;
                system("pause");
                system("cls");

                break;
            case 4:
                cout <<"<<< LIST OF STAFF >>>" << endl << endl;
                cout <<"TOTAL STAFF: 3"<< endl << endl;
                for(int j=0; j<3; j++){
                    cout << "### STAFF NUMBER " << j+1 << " ###" << endl << endl;
                    // cout << staff[j]; // do overload 1) disable jap kasi boleh run fix. 2) kau ade overload ke staff punye << ??
                }
                cout << endl;
                system("pause");
                system("cls");

                break;
            case 5:
                cout <<"<<< LIST OF APPOINTED DATES >>> \n\n";
                for(int i=0;i<Appointment::count;i++){
                    cout << appDate[i] << endl;
                }
                system("pause");
                system("cls");
                break;
        }

    }while(chooseMenu!=9);

}
