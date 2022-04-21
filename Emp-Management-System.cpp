//////////////////////////////////////////
// Programing Technique Project.		//
//										//
// GROUP 14 MEMBERS:					//
// NAUFAL HADI SYUKRIMA		(A19EC0272) //	
// MD MUNTASIR BILLAH		(A19EC0251)	//	 	
//////////////////////////////////////////

/*
The program/system will be used by the staff for any kind of organization during this pandemic, 
this program will let the staff input employees personal data information, travel history, 
body temperature and their body check. From that information, there will be a checking process. 
And the data of the employee will be saved in the system to help all the medical teams that need 
the data of the employees in the organization in the future.
*/

//RUN IN FULL SCREEN CONSOLE
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

class Address		
{
	public:
		string location;
		
		Address () {}
		Address (string l="")
		{
			location = l;
		}

		void setLocation (string l)
		{
			location = l;
		}

		string getLocation ()
		{
			return location;
		}	
};


class Person			//Aggregation relationship with class Address
{
	protected:
		string name;
		string gender;
		int age;
		string phone;
		Address *address;			//Aggregation

	public:
		Person (){}
		Person (string n, string g, int a, string p, Address* A)
		{
			name = n;
			gender = g;
			age = a;
			phone = p;
			address = A;
		}

		void setName (string n)
		{
			name = n;
		}

		void setGender (string g)
		{
			gender = g;
		}

		void setAge (int a)
		{
			age = a;
		}

		void setPhone (string p)
		{
			phone = p;
		}

		string getName ()
		{
			return name;
		}

		string getGender ()
		{
			return gender;
		}

		int getAge ()
		{
			return age;
		}

		string getPhone ()
		{
			return phone;
		}
		
		void personInput ()
		{
			cout << "Name: ";
			cin >> name;
			cout << "Gender: ";
			cin >> gender;
			cout << "Age: ";
			cin >> age;
			cout << "Phone: ";
			cin >> phone;
			cout << "Location: ";
			cin >> address->location;
		}

		virtual void print ()
		{
			cout << "Name: " << name;
			cout << "Gender: " << gender;
			cout << "Age: " << age;
			cout << "Phone: " << phone;
			cout << "Location: " << address->getLocation();
		}
};		


class TravelHistory				
{
	public:
		string travelPlace;
		string travelDate;

		TravelHistory (){}
		TravelHistory (string tp, string td)
		{
			travelPlace = tp;
			travelDate = td;
		}

		void setTravelPlace (string tp)
		{
			travelPlace = tp;
		}

		void setTravelDate (string td)
		{
			travelDate = td;
		}

		string getTravelPlace ()
		{
			return travelPlace;
		}

		string getTravelDate ()
		{
			return travelDate;
		}
		
		void travelInput ()
		{
			cout << "Last travel place:	";
			cin >> travelPlace;
			cout << "Last travel date: ";
			cin >> travelDate;
		}
		
		void print ()
		{
			cout << "Last travel place:	" << getTravelPlace();
			cout << "Last travel date: " << getTravelDate();
		}
};


class Check
{
	public:
		string temperature;
		string cough;
		string breath;
		string fever;
		string diseaseHistory;
		
		Check(){}
		Check (string t, string c, string b, string f, string dh)
		{
			temperature = t;
			cough = c;
			breath = b;
			fever = f;
			diseaseHistory = dh;
		}

		void setTemperature (string t)
		{
			temperature = t;
		}

		void setCough (string c)
		{
			cough = c;
		}

		void setBreath (string b)
		{
			breath = b;
		}

		void setFever (string f)
		{
			fever = f;
		}

		void setDiseaseHistory (string dh)
		{
			diseaseHistory = dh;
		}

		string getTemperature ()
		{
			return temperature;
		}

		string getCough ()
		{
			return cough;
		}

		string getBreath ()
		{
			return breath;
		}

		string getFever ()
		{
			return fever;
		}

		string getDiseaseHistory ()
		{
			return diseaseHistory;
		}
		
		void checkInput ()
		{
			cout << "Temperature:	";
			cin >> temperature;
			cout << "Cough condition:	";
			cin >> cough;
			cout << "Breath condition:	";
			cin >> breath;
			cout << "Fever:	";
			cin >> fever;
			cout << "Diseaser History from 3 month back:	";
			cin >> diseaseHistory;
		}
		
		void print ()
		{
			cout << "Temperature:	" << getTemperature();
			cout << "Cough condition:	" << getCough();
			cout << "Breath condition:	" << getBreath();
			cout << "Fever:	" << getFever();
			cout << "Diseaser History from 3 month back:	" << getDiseaseHistory();
		}
};


class CloseContact : public Person 									//inheritance from class Person	
{
	private:
		string nationality;
		string relationship;
		string dateMeet;

	public:
		CloseContact (){}
		CloseContact (string n, string g, int a, string p, Address* A, string nat="", string r="", string dm="")
		{
			name = n;
			gender = g;
			age = a;
			phone = p;
			address = A;
			nationality = nat;
			relationship = r;
			dateMeet = dm;
		}

		void setNationality (string nat)
		{
			nationality = nat;
		}

		void setRelationship (string r)
		{
			relationship = r;
		}

		void setDateMeet (string dm)
		{
			dateMeet = dm;
		}

		string getNationality ()
		{
			return nationality;
		}

		string getRelationship ()
		{
			return relationship;
		}

		string getDateMeet ()
		{
			return dateMeet;
		}
		
		void closeContactInput ()
		{
			personInput ();
			cout << "Nationality:	";
			cin >> nationality;
			cout << "Relationship:	";
			cin >> nationality;
			cout << "Date and place meet:	";
			cin >> dateMeet;
		}

		void print ()
		{
			cout << "Nationality:	" << getNationality();
			cout << "Relationship:	" << getRelationship();
			cout << "Date and place meet:	" << getDateMeet();
		}
};


// Aggregation relationship to class CloseContact and TravelHistory
// Compossition relatinship to Check
class Employee : public Person										//inheritance from class Person	
{
	protected:
		string id;
		string position;
		TravelHistory *travelHistory;		//Aggregation
		Check check;						//Compossition
		CloseContact *closeContact;			//Aggregation
	
	public:
		Employee (){}
		Employee (string i, string pos, string n, string g, int a, string p, Address* A, TravelHistory *TH, Check C, CloseContact *CC)
		{
			id = i;
			position = pos;
			name = n;
			gender = g;
			age = a;
			phone = p;
			address = A;
			travelHistory = TH;
			check = C;
			closeContact = CC;
		}

		void setId (string i)
		{
			id = i;
		}

		void setPosition (string pos)
		{
			position = pos;
		}

		string getId ()
		{
			return id;
		}

		string getPosition ()
		{
			return position;
		}
		
		void employeeInput ()
		{	
			cout << "ID:	";
			cin >> id;
			cout << "Position:	";
			cin >> position;
			personInput ();
			
		}

		void print ()
		{
			cout << "ID:	" << getId();
			cout << "Position:	" << getPosition();
			Person::print();
			travelHistory->print();
			check.print();
			closeContact->print();
		}
};


class Safe :public Employee
{
	private:
		string negative;
	
	public:
		Safe (){}
		Safe (string i, string pos, string n, string g, int a, string p, Address* A, TravelHistory *TH, Check C, CloseContact *CC, string neg)
		{
			id = i;
			position = pos;
			name = n;
			gender = g;
			age = a;
			phone = p;
			address = A;
			travelHistory = TH;
			check = C;
			closeContact = CC;
			negative = neg;
		}

		string getNegative ()
		{
			return negative;
		}

		void print ()
		{
			Employee::print();
			Person::print();
			travelHistory->print();
			check.print();
			closeContact->print();
			cout << "Negative" << endl;	
		}
};


class Suspected :public Employee
{
	private:
		string warded;
	
	public:
		Suspected (){}
		Suspected (string i, string pos, string n, string g, int a, string p, Address* A, TravelHistory *TH, Check C, CloseContact *CC, string wrd)
		{
			id = i;
			position = pos;
			name = n;
			gender = g;
			age = a;
			phone = p;
			address = A;
			travelHistory = TH;
			check = C;
			closeContact = CC;
			warded = wrd;
		}

		string getWarded ()
		{
			return warded;
		}

		void print ()
		{
			Employee::print();
			Person::print();
			travelHistory->print();
			check.print();
			closeContact->print();
			cout << "Suspected" << endl;	
		}
};


class Other :public Employee
{
	private:
		string unknown;
	
	public:
		Other (){}
		Other (string i, string pos, string n, string g, int a, string p, Address* A, TravelHistory *TH, Check C, CloseContact *CC, string unk)
		{
			id = i;
			position = pos;
			name = n;
			gender = g;
			age = a;
			phone = p;
			address = A;
			travelHistory = TH;
			check = C;
			closeContact = CC;
			unknown = unk;
		}

		string getUnknown ()
		{
			return unknown;
		}

		void print ()
		{
			Employee::print();
			Person::print();
			travelHistory->print();
			check.print();
			closeContact->print();
			cout << "Other" << endl;	
		}
};


int main ()
{ 

Employee *e;
char fname[20];

cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                      WELCOME TO                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                          EMPLOYEE MEDICAL MANAGEMENT SYSTEM                           |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                             -Program by MD MUNTASIR BILLAH and NAUFAL HADI SYUKRIMA   |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
system("pause");
system("cls");


int i;

//giving option to the user for their choice
b:
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  EMPLOYEE MANAGEMENT SYSTEM \n\n";	
cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
cout<<"\t\t\t\t\t\t|                                           	                  |\n";
cout<<"\t\t\t\t\t\t|             1  >> Add New Employee Record                       |\n";
cout<<"\t\t\t\t\t\t|             2  >> Full History of the Employee                  |\n";
cout<<"\t\t\t\t\t\t|             3  >> Exit the Program                              |\n";
cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
a:cout<<"\t\t\t\t\t\tEnter your choice: ";cin>>i;
if(i>3||i<1){cout<<"\n\n\t\t\t\t\t\tInvalid Choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto a;} //if inputed choice is other than given choice



system("cls");

//Adding the record of the new employee..................option 3
if(i==1)
{  
  ofstream pat_file;
  char fname[20];
  cout<<"\n\n\n\nEnter the employee file name : ";
  cin.ignore();
  gets(fname);
  pat_file.open(fname);
  		if(!fname)
		{
		cout<<"\nError while opening the file\n"; goto b;
		}
		else
		{	
			        struct Empoloyee
                        {
                            char id[10];
                            char position[50];
							char name[50];
							char gender[20];
                            char age[10];
                            char phone[20];
                            char address[100];
                            char travelHistory[100];
                            char check[100];
                            char closecontact[100];
                            char covidStatus[50];
                        };

            Empoloyee e;
            cout<<"\n********************************************************************\n";pat_file<<"\n********************************************************************\n\n";
            cout<<"\nID : ";pat_file<<"ID : ";gets(e.id);pat_file<<e.id<<"\n";
            cout<<"\nPosition : ";pat_file<<"Position : ";gets(e.position);pat_file<<e.position<<"\n";
			cout<<"\nName : ";pat_file<<"Name : ";gets(e.name);pat_file<<e.name<<"\n";
            cout<<"\nGender : ";pat_file<<"Gender : ";gets(e.gender);pat_file<<e.gender<<"\n";
            cout<<"\nAge : ";pat_file<<"Age : ";gets(e.age);pat_file<<e.age<<"\n";
            cout<<"\nPhone : ";pat_file<<"Phone : ";gets(e.phone);pat_file<<e.phone<<"\n";
            cout<<"\nAddress : ";pat_file<<"Address : ";gets(e.address);pat_file<<e.address<<"\n";
            cout<<"\nLast Travel (DATE/PLACE) : ";pat_file<<"Name : ";gets(e.travelHistory);pat_file<<e.travelHistory<<"\n";
            cout<<"\nBody Check (TEMP/BODY CONDITION) : ";pat_file<<"Body Check : ";gets(e.check);pat_file<<e.check<<"\n";
            cout<<"\nLast Close Contact(DATE/PLACE/RELATIONSHIP) : ";pat_file<<"Last Close Contact : ";gets(e.closecontact);pat_file<<e.closecontact<<"\n";
            cout<<"\nCOVID-19 Status (NEGATIVE/SUSPECTED/OTHER) : ";pat_file<<"COVID-19 Status : ";gets(e.covidStatus);pat_file<<e.covidStatus<<"\n";
            cout<<"\n********************************************************************\n";pat_file<<"\n********************************************************************\n\n";
            cout<<"\nInformation Saved Successfully\n";
        }
  system("pause");
  system("cls");
  goto b;

}

//For displaying the full medical history of patient............option 2
if(i==2)
{
    fstream pat_file;
    cout<<"\n\nEnter the employee file name to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................ Full Employee History of "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
        }
        system("pause");
        system("cls");
        goto b;
}


//Exiting the system........................option 3
if(i==3)
{
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                    THANK YOU FOR USING                                |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                            EMPLOYEE MEDICAL MANAGEMENT SYSTEM                         |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                             -Program by MD MUNTASIR BILLAH and NAUFAL HADI SYUKRIMA   |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
}


cout<<"\n";

}


