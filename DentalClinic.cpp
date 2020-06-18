//////////////////////////////////////////////////////////////
// PROGRAMMING TECHNIQUE 2 TEAM PROJECT                     //
// DENTAL CLINIC MANAGEMENT SYSTEM FOR CORONAVIRUS PANDEMIC //
// BY : TEAM CORONA (FAHMI, VEEJAY, LIWAUDDIN)              //
//////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


using namespace std;

const int MAX = 100;
const int MAXDATE = 50;

string availableTime[MAXDATE] = { "10/06/2020 - 9:00 A.M", "12/06/2020 - 9:00 A.M", "15/06/2020 - 9:00 A.M", "18/06/2020 - 9:00 A.M", "19/06/2020 - 9:00 A.M",
                    "22/06/2020 - 9:00 A.M", "23/06/2020 - 9:00 A.M", "26/06/2020 - 9:00 A.M", "01/07/2020 - 9:00 A.M", "14/07/2020 - 9:00 A.M",
                    "22/07/2020 - 9:00 A.M", "28/07/2020 - 9:00 A.M", "04/08/2020 - 9:00 A.M", "28/08/2020 - 9:00 A.M", "31/08/2020 - 9:00 A.M",
                    "09/09/2020 - 9:00 A.M", "16/09/2020 - 9:00 A.M",  "29/10/2020 - 9:00 A.M","17/11/2020 - 9:00 A.M", "18/11/2020 - 9:00 A.M",
                    "26/11/2020 - 9:00 A.M","14/12/2020 - 9:00 A.M","17/12/2020 - 9:00 A.M","21/12/2020 - 9:00 A.M","30/12/2020 - 9:00 A.M",
                    "10/06/2020 - 2:00 P.M","12/06/2020 - 2:00 P.M","15/06/2020 - 2:00 P.M","18/06/2020 - 2:00 P.M","19/06/2020 - 2:00 P.M",
                    "22/06/2020 - 2:00 P.M","23/06/2020 - 2:00 P.M","26/06/2020 - 2:00 P.M","01/07/2020 - 2:00 P.M","14/07/2020 - 2:00 P.M",
                    "22/07/2020 - 2:00 P.M","28/07/2020 - 2:00 P.M","04/08/2020 - 2:00 P.M","28/08/2020 - 2:00 P.M","31/08/2020 - 2:00 P.M",
                    "09/09/2020 - 2:00 P.M","16/09/2020 - 2:00 P.M","29/10/2020 - 2:00 P.M","17/11/2020 - 2:00 P.M","18/11/2020 - 2:00 P.M",
                    "26/11/2020 - 2:00 P.M","14/12/2020 - 2:00 P.M","17/12/2020 - 2:00 P.M","21/12/2020 - 2:00 P.M","30/12/2020 - 2:00 P.M" };

string appDate[MAXDATE];

void welcomeInterface() {

    cout << "\n\n\n\t\t\t\t" << "---------------------------------------------------------" << endl;
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" << "|" << "\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" << "|" << "\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" << "|" << "\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" << "|" << "\n";
    cout << "\t\t\t\t" << "|" << "\tWELCOME TO DENTAL CLINIC MANAGEMENT SYSTEM\t" << "|" << "\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" << "|" << "\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" << "|" << "\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\t\t\t" << "|" << "\n";
    cout << "\t\t\t\t" << "|" << "\t\t\t\t\tBY: TEAM CORONA\t" << "|" << "\n";


    cout << "\t\t\t\t" << "---------------------------------------------------------" << "\n\n\n\n\n\n\n\n\n";
    system("pause");
    system("cls");
}

void drawMenu() {

    cout << "\n\n\n\n\t\t\t\t\t" << "     DENTAL CLINIC MANAGEMENT SYSTEM" << endl;
    cout << "\n\t\t\t\t" << "---------------------------------------------------------" << endl;
    cout << "\t\t\t\t" << "|" << "                                                       " << "|\n";
    cout << "\t\t\t\t" << "|" << "  1. Add a patient                                     " << "|\n";
    cout << "\t\t\t\t" << "|" << "  2. Update patient record                             " << "|\n";
    cout << "\t\t\t\t" << "|" << "  3. View patient record                               " << "|\n";
    cout << "\t\t\t\t" << "|" << "  4. View staff record                                 " << "|\n";
    cout << "\t\t\t\t" << "|" << "  5. View appointed dates                              " << "|\n";
    cout << "\t\t\t\t" << "|" << "  6. Exit                                              " << "|\n";
    cout << "\t\t\t\t" << "|" << "                                                       " << "|\n";
    cout << "\t\t\t\t" << "|" << "                                                       " << "|\n";
    cout << "\t\t\t\t" << "---------------------------------------------------------" << "\n\n\n\n\n\n\n";
    cout << "Choose an operation => ";

}

//############################################## CLASS DECLARATIONS ##################################################




class Person {
public:
    string name;
    string gender;
    string dateofBirth;
    string phoneNo;
    int age;

    //Create new person
    bool create() {
        cout << "Name : ";
        getline(cin, name);
        
        // exception handling
        do{
        cout << "Age : ";
        while(!(cin >> age)){  //if user enters string instead of int for age
        	string ageError2 ="Please enter a valid value!";
        	throw ageError2;
		}
        try{ // if value entered by user for age is <= 0
        	if (age <= 0){
        		string ageError="Age must be greater than 0! Please re-enter age.";
        		throw ageError;
			}
		}
		catch (string msg){
			cout << "Error : " << msg << endl;
		}
		} while (age < 0 || age == 0);
        cin.ignore();
        cout << "Gender : ";
        getline(cin, gender);
        cout << "Date of Birth : ";
        getline(cin, dateofBirth);
        cout << "Phone Number : ";
        getline(cin, phoneNo);

        return 1;

    };


    //Get person name
    string getName() {
        return name;
    }

    //View person's info
    void dispInfo() {
        cout << "::: BASIC INFORMATION :::" << endl << endl;
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Gender : " << gender << endl;
        cout << "Date of Birth : " << dateofBirth << endl;
        cout << "Phone Number : " << phoneNo << endl << endl;
    }
};

class Staff : public Person {
protected:
    friend class Treatment;
    friend class Screening;
    string staffID;
    string role, employmentType;
    int salary;
public:

    virtual bool create() = 0;
    virtual void displayInfo() {

    }

    friend ostream& operator<<(ostream& strm, Staff& obj) {
        strm << "::: STAFF INFORMATION :::" << endl << endl;
        strm << "Name : " << obj.name << endl;
        strm << "Age : " << obj.age << endl;
        strm << "Gender : " << obj.gender << endl;
        strm << "Date of Birth : " << obj.dateofBirth << endl;
        strm << "Phone Number : " << obj.phoneNo << endl;
        strm << "ID : " << obj.staffID << endl;
        strm << "Employment Type : " << obj.employmentType << endl;
        strm << "Salary : RM" << obj.salary << endl;

        return strm;
    }

};

class Dentist : public Staff {

private:
    string expertise;


public:
    int k = 0;
    Dentist(string x="", int y=0, string z="", string xy="", string xz="", string yz="", string yx="", string xx="", int yy=0) {
        this->name = x;
        this->age = y;
        this->gender = z;
        this->dateofBirth = xy;
        this->phoneNo = xz;
        this->staffID = yz;
        this->expertise = yx;
        this->employmentType = xx;
        this->salary = yy;
    };
    //polymorph
    bool create() {
        cout << "Name of Dentist: ";
        getline(cin, name);
        cout << "Age of Dentist: ";
        cin >> age;
        cin.ignore();
        cout << "Gender : ";
        getline(cin, gender);
        cout << "Date of Birth : ";
        getline(cin, dateofBirth);
        cout << "Phone Number : ";
        getline(cin, phoneNo);
        cout << "Enter staff ID : ";
        getline(cin, staffID);
        role = "Dentist";
        cout << "Enter expertise : ";
        getline(cin, expertise);
        cout << "Enter staff employment type";
        getline(cin, employmentType);
        cout << "Enter staff salary per month";
        cin >> salary;

        return 1;
    }

    void displayInfo() {
        cout << "No. of patients    : " << k << endl;
    }

    void chooseDoctor() {  // update no of patients
        k += 1;
    }

   
};



class Nurse : public Staff {

private : 
	string screeningList[10];
	int j = 1;
public:
	
    Nurse(string x="", int y=0, string z="", string xy="", string xz="", string yz="", string xx="", int yy=0) {
        this->name = x;
        this->age = y;
        this->gender = z;
        this->dateofBirth = xy;
        this->phoneNo = xz;
        this->staffID = yz;
       
        this->employmentType = xx;
        this->salary = yy;
	}
    //polymorph
    
    bool create() {
        cout << "Name of Nurse: ";
        getline(cin, name);
        cout << "Age of Nurse: ";
        cin >> age;
        cin.ignore();
        cout << "Gender : ";
        getline(cin, gender);
        cout << "Date of Birth : ";
        getline(cin, dateofBirth);
        cout << "Phone Number : ";
        getline(cin, phoneNo);

        cout << "Enter staff ID : ";
        getline(cin, staffID);
        role = "Nurse";
        cout << "Enter staff employment type";
        getline(cin, employmentType);
        cout << "Enter staff salary per month";
        cin >> salary;

        return 1;
    }
    
    void doScreening(string ptname){
		this->screeningList[j-1] = ptname;
		j++;
	}
	
	string showPatient(int n){
		return screeningList[n];
	}

    void displayInfo() {
        cout << "Patients screened :" << endl;
        for (int i=0; i<j; i++){
        	cout << i+1 << ". " << this->showPatient(i) << endl; 
		}
    }

};

//Nurse will do the screening before the patient is treated by dentist
class Screening {
private:
    float temp;
    string currentIllness;
public:
    Screening() {
        temp = 0.0;
        currentIllness = "NOT YET SCREENED";
    }
    void setScreening(float temp, string currentIllness){ 
        this->temp = temp;
        this->currentIllness = currentIllness;
         
    }
    bool insert(Nurse &obj, string &n) { // pass Nurse obj dgn string of patient name n
        cout << "Enter the patient's temperature : ";
        cin >> temp;
        cin.ignore();
        cout << "Enter the patient's current symptoms related to COVID-19 (if any) : ";
        getline(cin, currentIllness);
		obj.doScreening(n);  // will update Patient's name currently doing screening to list of Nurse
        if (checkTemp())
            return 1;
        else
            return 0;

	
    }
    //This condition will determine whether the patient will be accepted or not
    bool checkTemp() {
    	try{ // second exception handling
    		if ( temp <= 0){
    			string invalidTemp = "Temperature entered is invalid!";
				throw invalidTemp;
			}	
		}
		catch ( string msg3){
			cout << "Error: "<< msg3 << endl;
		}
		
        if (temp > 37.5) {
            cout << endl << "Fever detected. Appointment will be declined. Thank you for coming and stay healthy. \n" << endl;
            return 0;
        }
        else if (this->temp > 30 && this->temp < 37.5) {
            cout << endl << "No fever detected. Patient's Appointment accepted. Please wait for your turn. \n" << endl;
            return 1;
        }
        
    }
    void dispScreeningResults() {
        cout << "Patient's temperature : " << temp << endl
             << "Symptoms related to COVID-19 : " << currentIllness << endl << endl;
    }


};


class MedHistory {
private:
    string ongoingMed, previousVisit, famMedHist;
public:

    bool insert() {
        cout << "Ongoing medications : ";
        getline(cin, ongoingMed);
        cout << "Previous visit here (date) : ";
        getline(cin, previousVisit);
        cout << "Family medical history : ";
        getline(cin, famMedHist);

        return 1;
    }

    friend ostream& operator<<(ostream& strm, MedHistory& obj) {

        strm << "Ongoing medications : " << obj.ongoingMed << endl
             << "Previous visit here : " << obj.previousVisit << endl
             << "Family medical history : " << obj.famMedHist << endl << endl;
        return strm;
    }

};


class Treatment {
protected:
    int doc;
    string medicine, diagnosis, note, date;
    string dentistname;
    
    Screening checkScreening;

public:

    Treatment() {
        medicine = "NOT YET TREATED";
        diagnosis = "NOT YET TREATED";
        note = "NOT YET TREATED";
        date = "NOT YET TREATED";
        dentistname = "NOT YET TREATED";
    }
    bool insert(Dentist& obj1, Dentist& obj2) {
        cout << "Enter the diagnosis of the patient : ";
        getline(cin, diagnosis);
        cout << "Enter the prescribed medicine : ";
        getline(cin, medicine);
        cout << "Enter the date of treatment : ";
        getline(cin, date);
        cout << "Enter any additional instructions/note : ";
        getline(cin, note);
        cout << "Treated by : " << endl; // choose dentist and will update dentist number of patients
        cout << "1) Dr.Amir " << endl
            << "2) Dr.Anis " << endl;
        

        do{
        cin >> doc;
        if (doc == 1) {
            obj1.chooseDoctor();
            dentistname = "Dr. Amir";
            break;
        }
        else if (doc == 2) {
            obj2.chooseDoctor();
            dentistname = "Dr. Anis";
            break;
        }
        else {
            cout << "Please choose either one or two!" << endl;
            
        }
        } while ( doc < 1 || doc > 2);

        return 1;
    }

    friend ostream& operator<<(ostream& strm, Treatment& obj) {
        strm << "Diagnosis of the patient : " << obj.diagnosis << endl
             << "Prescribed medicine : " << obj.medicine << endl
             << "Date of treatment : " << obj.date << endl
             << "Additional instructions/note : " << obj.note << endl
             << "Treated by : " << obj.dentistname << endl << endl;
        

        return strm;
    }



};





class Appointment {
private:
    string basicSymptoms, scheduledTime;

public:
    static int count;

    void drawSchedule() {
        for (int i = 0; i < MAXDATE; i++) {
            if (i == 0)
                cout << endl << "------------------9:00 A.M------------------" << endl << endl;
            if (i == 25)
                cout << endl << "------------------2:00 P.M------------------" << endl << endl;
            cout << availableTime[i] << " -> " << i << endl;
        }
    }

    //Traverses through all of the elements in the array and check for same date
    bool checkDate(string chosenTime, int chosenNum) {

        for (int i = 0; i < MAXDATE; i++) {
            if (chosenTime != "###### FULL ######" && i == count) {
                appDate[count] = chosenTime;
                scheduledTime = chosenTime;
                availableTime[chosenNum] = "###### FULL ######";
                ++count;
                return 1;
            }
            else if (i != count) {

                continue;
            }
            else
                return 0;
        }
    }

    //The first prompt that will appear when trying to add patient
    void proposedDate() {
        int temp;
        string tempdate;
        bool acceptDate;

        drawSchedule();

        do {
            cout << endl << "Enter the proposed date for appointment. Choose one of these dates by putting the number 0 to 49 : ";
            cin >> temp;
            cout << endl;
            tempdate = availableTime[temp];
            if (checkDate(tempdate, temp)) {
                cin.ignore();
                cout << "The date is accepted. Please enter the basic symptoms about the patient : ";
                getline(cin, basicSymptoms);
                acceptDate = 1;
                break;
            }
            else {
                cout << "The date is full!. Please choose another date." << endl;
                acceptDate = 0;
                // continue;
            }
        } while (temp < 0 || temp>49 || acceptDate == 0);

        
    }

    string getAppointmentDate() {
        return scheduledTime;
    }

};

//Initialize static int in Appointment class
int Appointment::count = 0;

class Patient : public Person {
private:
    MedHistory medHist;
    Screening screeningResults;
    Appointment appTime;
    Treatment* treatmentResults;
    string time, k="";
    friend class Screening;
public:
    Patient() {
        treatmentResults = new Treatment;
    }
    //polymorph
    bool create() {
        Person::create();//dah

        medHist.insert(); //Adds medical history from MedHistory class

        return 1;
    }
    void addAppointmentTime() {
        appTime.proposedDate();
    }

    //Adds screening results from the Screening class
    bool addscreeningResults(Nurse &obj) {
    	k = this->name;
        if (screeningResults.insert(obj, k)) { // send Nurse obj and Patient Name
            return 1;
        }
        else {
            return 0;
        }
    }

    //Adds treatment results after getting treatment from doctor
    void addtreatmentResults(Dentist& obj1, Dentist& obj2) { // receive Dentist obj
        treatmentResults->insert(obj1, obj2);
    }

    friend ostream& operator<<(ostream& strm, Patient obj) {

        obj.Person::dispInfo();

        strm << "::: MEDICAL HISTORY OF " << obj.getName() << " :::" << endl << endl;
        strm << obj.medHist; //here VJ

        strm << "::: APPOINTMENT DATE ::: \n\n";
        strm << obj.appTime.getAppointmentDate() << endl << endl;

        strm << "::: SCREENING RESULTS OF " << obj.getName() << " :::" << endl << endl;
        obj.screeningResults.dispScreeningResults();
        obj.screeningResults.checkTemp();

        strm << "::: TREATMENT RESULTS OF " << obj.getName() << " :::" << endl << endl;
        strm << *obj.treatmentResults;
        strm << endl << "=======================================================================" << endl;

        return strm;

    }


};
//############################################## END OF CLASS DECLARATIONS ##################################################

int main() {

    Patient* patient;
    patient = new Patient[MAX];


    Dentist a("Mr.Amir", 20, "M", "28/7", "012-6805527", "001", "Teeth", "Fulltime", 2300);
    Dentist b("Dr.Anis", 30, "F", "30/6", "012-9999999", "002", "Lips", "Parttime", 1000);
    Nurse c("Ms. Haida", 28, "F", "28/4", "012-5435678", "003", "Parttime", 800);
    Staff* stf[3] = { &a, &b, &c };

    int chooseMenu = 0, chooseMenu2 = 0, n = 0, choosePatient = 0;

    welcomeInterface();

    do {
        drawMenu();
        cin >> chooseMenu;
        system("cls");
        switch (chooseMenu) {
        case 1: //1. Add a patient
            patient[n].addAppointmentTime();
            cout << "\n <<< ENTER BASIC INFORMATION AND MEDICAL HISTORY OF PATIENT >>> \n\n";
            patient[n].create();
            cout << "\n @@@ Patient's information has been added to the database. @@@\n @@@ Nurses will do the screening on the appointed day. @@@ \n\n ";
            system("pause");
            system("cls");
            n += 1; //Iterates n so that it will add next patient
            break;
        case 2: //2. Update patient info
            for (int j = 0; j < n; j++) {
                cout << "### PATIENT NUMBER " << j + 1 << " ###" << endl << endl;
                cout << patient[j];
            }
            cout << "\n <<< CHOOSE WHICH PATIENT TO UPDATE BY ENTERING PATIENTS NUMBER (1,2,5,ETC) >>> \n\n";
            cin >> choosePatient;
            cout << "\n <<< ENTER THE SCREENING RESULTS OF PATIENT >>> \n\n";
            if (patient[choosePatient - 1].addscreeningResults(c)) {
                cout << "\n <<< ENTER THE TREATMENT RESULTS OF PATIENT >>> \n\n";
                patient[choosePatient - 1].addtreatmentResults(a, b); //send Dentist objects
            }
            else {
                cout << "\n ********* PATIENT WILL BE ASKED TO SELF-QUARANTINE AT HOME ********** \n\n";
            }
            system("pause");
            system("cls");

            break;
        case 3: //3. View patients record
            cout << "<<< LIST OF PATIENT >>>" << endl << endl;
            cout << "TOTAL PATIENT: " << n << endl << endl;
            for (int j = 0; j < n; j++) {
                cout << "### PATIENT NUMBER " << j + 1 << " ###" << endl << endl;
                cout << patient[j];
            }
            cout << endl;
            system("pause");
            system("cls");

            break;
        case 4: //4. View staff record
            cout << "<<< LIST OF STAFF >>>" << endl << endl;
            cout << "TOTAL STAFF: 3" << endl << endl;
            for (int j = 0; j < 3; j++) {
                cout << "### STAFF NUMBER " << j + 1 << " ###" << endl << endl;
                cout << *stf[j];
                stf[j]->displayInfo(); 
                cout << "\n============================================================\n";

            }


            cout << endl;
            system("pause");
            system("cls");

            break;
        case 5: //5. View appointed dates
            cout << "<<< LIST OF APPOINTED DATES >>> \n\n";
            for (int i = 0; i < Appointment::count; i++) {
                cout << appDate[i] << endl;
            }
            cout << endl << endl;
            system("pause");
            system("cls");
            break;
        case 6: //6. Exit
            cout << "==== YOU HAVE CHOSEN TO EXIT THE PROGRAM THANK YOU ==== \n\n\n\n\n\n\n\n\n\n";
            system("pause");
            system("cls");
            break;
        default:
            cout << "PLEASE ENTER NUMBER 1 TO 6 ONLY \n\n";
            system("pause");
            system("cls");
            break;
        }

    } while (chooseMenu != 6);
    delete[] patient;
    delete[] stf;

}
