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
    bool update(){
        cout << "Which primary info would you like to update?" << endl
    		 << "1. Name" << endl
    		 << "2. Age" << endl
    		 << "3. Gender" << endl
    		 << "4. Date of Birth" << endl
    		 << "5. Phone Number" << endl;
             << "6. None" << endl;
    	cout << endl << "Choose a field =>";
		
        int y;
		cin >> y;
		
		switch(y){
			
			case 1: 
				cout << "New Name : ";
				getline(cin, name);
				break;
			case 2:
				cout << "New Age : ";
				cin >> age;
				break;
			case 3:
				cout << "New Gender : ";
				getline(cin, gender);
				break;
			case 4:
				cout << "New Date of Birth : ";
				getline(cin, dateofBirth);
				break;
			case 5:
				cout << "New Phone Number : ";
				getline(cin, phoneNo);
				break;
            case 6:
                cout << "Please proceed to secondary info";
                break;
			default:
				cout << "Please choose a number from 1 to 6.";
				break;	
		} 
    		 
    	return 1;
}

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

public:

};

class Patient : public Person{
private:

public:
};

class Staff : public Person{
	private:
		int staffID = 0;
		string role;
		double salary;
		string employmentType;
		
	public:
		
		void counter(){
			static int count = 0;
			count ++;
			
			staffID = count;
		}
		
		// Staff constructor
		Staff(string r ="", double s=0, string et=""){
			role = r;
			salary = s;
			employmentType = et;
		}
		
		//Create staff
		bool create(){
			Person::create();
			cin.ignore();
			cout << "Role :" << endl;
			getline(cin, role);
			cout << "Salary :" << endl;
			cin >> salary;
			cout << "Employment Type :" << endl;
			getline(cin, employmentType);
		
			counter(); //update staffID
			return 1;
		}

};

class Dentist : public Staff{
	
	private:
		
	public :
		bool approveAppoint(){
			
		}

};

class Nurse : public Staff{
	
	private:
		//Appointment * app;
	

	public:
		
};

class Treatment{
	
	private :
		string med;
		string symp;
		string note;
		string date;
	
	public :
		void set_Drug(){
			cin.ignore();
			cout << "Medicine : ";
			getline(cin, med);
			cout << "Symptoms : ";
			getline(cin, symp);
			cout << "Note     : ";
			getline(cin, note);
			cout << "Date     : ";
			getline(cin, date);
		}	
			
	friend ostream &operator<<(ostream &strm, Treatment obj);
};

ostream &operator<<(ostream &strm, Treatment obj){
	
		strm << "Medicine : " << obj.med << endl;
		strm << "Symptoms : " << obj.symp << endl;
		strm << "Notes    : " << obj.note << endl;
		strm << "Date     : " << obj.date << endl;
		return strm;
	}

//DEBUG MENU TEST (DESIGN A PROPER ONE LATER)
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
