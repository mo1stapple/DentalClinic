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
        // cin.ignore();
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
        if(this->temp >37.5){
            cout <<endl<< "Fever detected. Appointment will be declined. Thank you for coming and stay healthy" << endl;
            return 0;
        }
        else{
            cout <<endl<< "No fever detected. Patient's Appointment accepted. Please wait for your turn." << endl;
            return 1;
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


class Staff : public Person{
protected:
    string staffID;
    string role, employmentType;
    int salary;
public:

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
private:
    string basicSymptoms,scheduledTime;

public:
    static int count;
    int currentCount;
    Appointment(){

    }

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
            if(chosenTime!="###### FULL ######" && i==currentCount){
                appDate[currentCount] = chosenTime;
                availableTime[chosenNum] = "###### FULL ######";
                currentCount = ++count;
                return 1;
            }
            else if(i!=currentCount){

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
        // drawSchedule(); //DEBUG

        // if(checkDate(tempdate,temp)){
        //     cout <<"The date is accepted. Please enter the basic information about the patient .";
        // }
        // else{
        //     cout << "The date is full!. Please choose another date." << endl;
        // }
        //DEBUG DELETE LATER
        // cout << currentCount;

        // for(int i = 0;i<5;i++){
        //     cout << appDate[i] << endl;
        // }

        //Check if the date is empty.

        return 1;
    }

    void dispAppointmentTimes(){
        cout << "::: LIST OF APPOINTMENTS' TIME :::" << endl << endl;
        for(int i= 0;i<currentCount;i++)
            cout << appDate[i] << endl;
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
    bool createPatient(){
        Person::create();
        medHist.insert(); //Adds medical history from MedHistory class

        return 1;
    }
    void addAppointmentTime(){
        appTime.proposedDate();
    }

    //Adds screening results from the Screening class
    bool addscreeningResults(){
        screeningResults.insert();
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
    cout << "Choose an operation => " << endl;

}

//DEBUG MENU TEST (DESIGN A PROPER ONE LATER)
void debugMenu(){
    cout<< "=====MENU=====" << endl
        << "1. Add a person" << endl
        << "2. Add staff" << endl
         << "3. Add a patient <--- CHOOSE ME PLS" << endl
         << "4. Add a medhistory" << endl
        << "5. Add dates" << endl;
    cout << endl << "Choose an operation => ";
}

int main(){

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  DEBUGGING SECTION @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ COMMENT STARTS HERE

    Appointment *debug5;

    Person *debug;
    Staff *debug2;
    Patient *debug3;
    MedHistory *debug4;
    int i=0,n=0;

    debug = new Person[MAX];
    debug2 = new Staff[MAX];
    debug3 = new Patient[MAX];
    debug4 = new MedHistory[MAX];

    debug5 = new Appointment[MAX];

    welcomeInterface();
    // drawMenu();
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
                cout <<endl<<"<<< Enter the proposed date of the patient >>>" << endl << endl;
                debug3[n].addAppointmentTime();
                cout <<endl<<"<<< Enter the information of the patient >>>" << endl << endl;
                debug3[n].createPatient();
                cout <<endl << "<< Enter the screening results of the patient >>" << endl << endl;
                if(debug3[n].addscreeningResults()){
                    cout  <<endl<< "<< Enter the treatment results of the patient >> " << endl << endl;
                    debug3[n].addtreatmentResults();
                }

                else{
                    cout << "Treatment status : Rejected" << endl;
                }
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
                cout <<"<<< Enter the information of the patient >>>" << endl << endl;
                debug5[n].proposedDate();
                // debug5[n].dispAppointmentTimes();
                n+=1;
                system("pause");

                break;
            case 6:
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

    }while(i!=7);
    delete [] debug;
    delete [] debug2;
    delete [] debug3;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ END DEBUGGING @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ COMMENT ENDS HERE


}
