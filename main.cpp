#include <iostream>;
#include <string>;
#include <ctime>
#include<time.h>
#include<windows.h>
#include <cstdio>
#include <sstream>
#include <./boost/date_time/gregorian/gregorian.hpp>
#include <./boost/date_time.hpp>
#pragma warning(disable : 4996)

using namespace std;


class information
{
public:

	int length = 4;
	string Name[50];
	int id[50];
	int iid;
	string RegDate[50];
	string TerminateDate[50];
	int HourlyRate[50];
	string Phone[50];
	string Address[50];
	string TCCode[50];
	string TCName[50];
	string SubjectCode[50];
	string Rating[50];
	void delay(unsigned int mseconds)
	{
		clock_t goal = mseconds + clock();
		while (goal > clock());
	}
	void date()
	{
		time_t T = time(NULL);
		struct  tm tm = *localtime(&T);
		cout << "\n\n\n";
		cout << "\t\t\t\t\t   Date: " << tm.tm_mday << "/" << tm.tm_mon + 1 << "/" << tm.tm_year + 1900;
	}
	void mainpage()
	{
		int process = 0;
		system("cls");
		date();
		cout << ("\n");
		cout << ("\t\t\t\t    ---------------------------\n");
		cout << ("\t\t\t\t    | TUTOR MANAGEMENT SYSTEM |\n");
		cout << ("\t\t\t\t    ---------------------------\n");
		cout << ("\n\n\n");
		cout << ("\t\t\t\t");
		cout << ("Prepared By    ");
		cout << (":");
		cout << ("   Sherif Magdy , Richard James, Su Yifan");
		cout << ("\n\n");
		cout << ("\t\t\t\t");
		cout << ("Data Structure Assignment   ");
		cout << (":");
		cout << ("   Tutor Management System");
		cout << ("\n\n");
		cout << ("\t\t\t\t");
		cout << ("Guided By:    ");
		cout << (":");
		cout << ("   Ms. Chong Mien May");
		cout << ("\n\n");
		cout << ("\t\t\t\t    Login Successful!");
		cout << ("\n\n");
		cout << ("\t\t\t\tLoading");

		for (process = 0; process < 25; process++)
		{
			delay(150);
			cout << (".");
		}
	}
	void errormsg() {
		int process = 0;
		cout << ("\t\t\t\t    Invalid!");
		cout << ("\n\n");
		cout << ("\t\t\t\t Returning to main menu");
		for (process = 0; process < 25; process++)
		{
			delay(150);
			cout << (".");
		}
		menu();
	}
	void title()
	{
		cout << ("\n\n\n");
		cout << ("\t\t\t\t\t");
		cout << ("\n");
		cout << ("\t\t\t\t    ---------------------------\n");
		cout << ("\t\t\t\t    | TUTOR MANAGEMENT SYSTEM  |\n");
		cout << ("\t\t\t\t    ---------------------------\n");
		cout << ("\n\n");
		cout << ("\t\t\t\t");

	}
	void checktermination() {
		for (int i = 0; i < length; i++) {
			if (length == 0) {
				break;
			}
			if (length != 0 && length != 1) {
				const string& date = TerminateDate[i];
				stringstream ss(date);
				string d, m, y;
				getline(ss, d, '/');
				getline(ss, m, '/');
				getline(ss, y, '/');
				unsigned short dd = stoi(d);
				unsigned short mm = stoi(m);
				unsigned short yy = stoi(y);
				boost::gregorian::date dateObj{ yy,mm,dd };
				boost::gregorian::months monthObj(6);
				dateObj = dateObj + monthObj;
				boost::posix_time::ptime timeLocal =
					boost::posix_time::second_clock::local_time();
				boost::gregorian::date cdateObj = timeLocal.date();
				if (dateObj.year() == cdateObj.year()) {
					if (dateObj.month().as_number() == cdateObj.month().as_number()) {
						if (dateObj.day() == cdateObj.day()) {
							for (int x = i; x < length - 1; x++) {
								id[i] = id[i + 1];
								Name[i] = Name[i + 1];
								RegDate[i] = RegDate[i + 1];
								TerminateDate[i] = TerminateDate[i + 1];
								HourlyRate[i] = HourlyRate[i + 1];
								Phone[i] = Phone[i + 1];
								Address[i] = Address[i + 1];
								TCCode[i] = TCCode[i + 1];
								TCName[i] = TCName[i + 1];
								SubjectCode[i] = SubjectCode[i + 1];
								Rating[i] = Rating[i + 1];
								i++;
							}
							length--;
							break;
							
						}
					}
				}
				if (dateObj.year() == cdateObj.year()) {
					if (dateObj.month().as_number() <= cdateObj.month().as_number()) {
						if (dateObj.day() <= cdateObj.day()) {
							for (int x = i; x < length - 1; x++) {
								id[i] = id[i + 1];
								Name[i] = Name[i + 1];
								RegDate[i] = RegDate[i + 1];
								TerminateDate[i] = TerminateDate[i + 1];
								HourlyRate[i] = HourlyRate[i + 1];
								Phone[i] = Phone[i + 1];
								Address[i] = Address[i + 1];
								TCCode[i] = TCCode[i + 1];
								TCName[i] = TCName[i + 1];
								SubjectCode[i] = SubjectCode[i + 1];
								Rating[i] = Rating[i + 1];
								
								i++;
							}
							length--;
							break;
							
						}
					}
				}
				if (dateObj.year() < cdateObj.year()) {
					for (int x = i; x < length - 1; x++) {
						id[i] = id[i + 1];
						Name[i] = Name[i + 1];
						RegDate[i] = RegDate[i + 1];
						TerminateDate[i] = TerminateDate[i + 1];
						HourlyRate[i] = HourlyRate[i + 1];
						Phone[i] = Phone[i + 1];
						Address[i] = Address[i + 1];
						TCCode[i] = TCCode[i + 1];
						TCName[i] = TCName[i + 1];
						SubjectCode[i] = SubjectCode[i + 1];
						Rating[i] = Rating[i + 1];
						
						i++;
					}
					length--;
					break;
					
				}
				
			}
			if (length == 1) {
				const string& date = TerminateDate[i];
				stringstream ss(date);
				string d, m, y;
				getline(ss, d, '/');
				getline(ss, m, '/');
				getline(ss, y, '/');
				unsigned short dd = stoi(d);
				unsigned short mm = stoi(m);
				unsigned short yy = stoi(y);
				boost::gregorian::date dateObj{ yy,mm,dd };
				boost::gregorian::months monthObj(6);
				dateObj = dateObj + monthObj;
				boost::posix_time::ptime timeLocal =
					boost::posix_time::second_clock::local_time();
				boost::gregorian::date cdateObj = timeLocal.date();
				if (dateObj.year() == cdateObj.year()) {
					if (dateObj.month().as_number() == cdateObj.month().as_number()) {
						if (dateObj.day() == cdateObj.day()) {
							id[0] = NULL;
							Name[0] = "";
							RegDate[0] = "";
							TerminateDate[0] = "";
							HourlyRate[0] = NULL;
							Phone[0] = "";
							Address[0] = "";
							TCCode[0] = "";
							TCName[0] = "";
							SubjectCode[0] = "";
							Rating[0] = "";
							length--;
							break;

						}
					}
				}
				if (dateObj.year() == cdateObj.year()) {
					if (dateObj.month().as_number() <= cdateObj.month().as_number()) {
						if (dateObj.day() <= cdateObj.day()) {
							
								id[0] = NULL;
								Name[0] = "";
								RegDate[0] = "";
								TerminateDate[0] = "";
								HourlyRate[0] = NULL;
								Phone[0] = "";
								Address[0] = "";
								TCCode[0] = "";
								TCName[0] = "";
								SubjectCode[0] = "";
								Rating[0] = "";
								length--;
								break;
							

						}
					}
				}
				if (dateObj.year() < cdateObj.year()) {
					id[0] = NULL;
					Name[0] = "";
					RegDate[0] = "";
					TerminateDate[0] = "";
					HourlyRate[0] = NULL;
					Phone[0] = "";
					Address[0] = "";
					TCCode[0] = "";
					TCName[0] = "";
					SubjectCode[0] = "";
					Rating[0] = "";
					length--;
					break;
				}

			}

			
		}
	}
	void menu()
	{
		string a;
		int input;
		system("cls");
		title();
		cout << (" 1. Insert New Record\n\n");
		cout << ("\t\t\t\t");
		cout << (" 2. Modify Record\n\n");
		cout << ("\t\t\t\t");
		cout << (" 3. Delete Record\n\n");
		cout << ("\t\t\t\t");
		cout << (" 4. Display all records\n\n");
		cout << ("\t\t\t\t");
		cout << (" 5. search record by TutorID \n\n");
		cout << ("\t\t\t\t");
		cout << (" 6. search record by rating \n\n");
		cout << ("\t\t\t\t");
		cout << (" 7. Sort and Display records by: \n\n");
		cout << ("\t\t\t\t");
		cout << (" 8. Exit\n\n");
		cout << ("\t\t\t\t");
		cout << ("Choose options:[1/2/3/4/5/6/7/8]: ");
		cin >> input;
		if (cin.fail()) {
			string minput;
			cin.ignore();
			cin.clear();
			system("cls");
			title();
			cout << "Invalid Input! Would you like to try again? ";
			getline(cin, minput);
			cout << "\n";
			cout << ("\t\t\t\t");
			if (minput == "Y" || minput == "y")
			{
				menu();
			}
			else if (minput == "N" || minput == "n") {
				system("cls");
				cout << ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				cout << ("\t\t\t\t");
				cout << ("Brought To You By Sherif Magdy, Richard James, Su Yifan");
				cout << ("\n\n\n\n");
				exit(0);
			}

		}
		switch (input)
		{
		case 1:
		{
			system("cls");
			insert();
		}
		break;

		case 2:
		{
			system("cls");
			modify();
			
		}
		break;

		case 3:
		{
			system("cls");
			deleter();
		}
		break;

		case 4:
		{
			system("cls");
			display();
			//search();
		}
		break;

		case 5:
		{
			system("cls");
			searchid();
			
		}
		break;
		case 6:
		{
			system("cls");
			title();
			searchr();

		}
		case 7:
		{
			int ans;
			system("cls");
			title();
			cout << "1 . Sort and display by Tutors ID in ascending order \n";
			cout << "\t\t\t\t";
			cout << "2 . Sort and display by Tutors Hourly Pay Rate in ascending order \n";
			cout << "\t\t\t\t";
			cout << "3 . Sort and display by Tutors Overall Performance in ascending order \n";
			cout << "\t\t\t\t";
			cout << "4 . Return to main menu \n";
			cout << "\t\t\t\t";
			cout << "Choose option[1/2/3/4]: ";
			cin >> ans;
			if (ans == 1) {
				system("cls");
				if (length == 0) {
					title();
					
					cout << "No data found! \n";
					int process = 0;
					cout << ("\t\t\t\t Returning to menu");
					for (process = 0; process < 25; process++)
					{
						delay(150);
						cout << (".");
					}
					menu();
				}
				else {
					sortid();
				}
			}
			else if (ans == 2) {
				system("cls");
				if (length == 0) {
					title();
					
					cout << "No data found! \n";
					int process = 0;
					cout << ("\t\t\t\t Returning to menu");
					for (process = 0; process < 25; process++)
					{
						delay(150);
						cout << (".");
					}
					menu();
				}
				else {
					sortpay();
				}
			}
			else if (ans == 3) {
				system("cls");
				if (length == 0) {
					title();
					
					cout << "No data found! \n";
					int process = 0;
					cout << ("\t\t\t\t Returning to menu");
					for (process = 0; process < 25; process++)
					{
						delay(150);
						cout << (".");
					}
					menu();
				}
				else {
					sortrate();
				}
			}
			else if (ans == 4) {
				system("cls");
					menu();
			}
			else {
				errormsg();
			}

		}
		break;
		
		case 8:
		{
			system("cls");
			cout << ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			cout << ("\t\t\t\t");
			cout << ("Brought To You By Sherif Magdy, Richard James, Su Yifan");
			cout << ("\n\n\n\n");
			exit(0);
		}
		break;
		default:
		{
			string minput;
			system("cls");
			title();
			cout << "Invalid Input! Would you like to try again? ";
			cin >> minput;
			cout << "\n";
			cout << ("\t\t\t\t");
			if (minput == "Y" || minput == "y")
			{
				menu();
			}
			else if (minput == "N" || minput == "n") {
				system("cls");
				cout << ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				cout << ("\t\t\t\t");
				cout << ("Brought To You By Sherif Magdy, Richard James, Su Yifan");
				cout << ("\n\n\n\n");
				exit(0);
			}

		}
		}
	}
	void checkid() {
		for (int i = 0; i <= length; i++) {
			if (iid == 0) {
				string input;
				cout << "\n";
				cout << "\t\t\t\t";
				cout << "CAnnot assign 0 as ID!";
				cout << "\n";
				cout << "\t\t\t\t";
				cout << "Would you like to try again? (y/n)";
				cin >> input;
				if (input == "y" || input == "Y") {
					insert();
				}
				else {
					menu();
				}
				break;
			}
			else if (id[i] == iid) {
				string input;
				cout << "\n";
				cout << "\t\t\t\t";
				cout << "User Already Exist!";
				cout << "\n";
				cout << "\t\t\t\t";
				cout << "Would you like to try again? (y/n)";
				cin >> input;
				if (input == "y" || input == "Y") {
					insert();
				}
				else {
					menu();
				}
				break;
				
			}
		}
	}
	void insert() {
		string name, rating, sfield, subjectcode, tcname, tccode, address, phone, terminatedate, regdate;
		int hourlyrate;
		int d , dd;
		int m , mm; 
		int y, yy;
		char c = '/';
		

		//Input from user
		system("cls");
		title();
		cout << "Tutor Id Number: " ;
		cin >> iid;
		checkid();
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Name: " ;
		cin.ignore();
		getline(cin, name);
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Registeration Date Day: ";
		cin >> d;
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Registeration Date Month: ";
		cin >> m;
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Registeration Date Year: ";
		cin >> y;
		isValidDate(d, m, y);
		regdate = to_string(d) + c + to_string(m) + c + to_string(y);
		//cin.ignore();
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Termiantion Date Day: ";
		cin >> dd;
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Termination Date Month: ";
		cin >> mm;
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Termination Date Year: ";
		cin >> yy;
		isValidDate(dd, mm, yy);
		terminatedate = to_string(dd) + c + to_string(mm) + c + to_string(yy);
		//cin.ignore();
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Hourly Rate (RM 40 - RM 80): ";
		//cin.clear();
		cin >> hourlyrate;
		//cin.ignore();
		if (hourlyrate < 40 || hourlyrate > 80) {
			errormsg();
		}
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Phone Number: ";
		cin.ignore();
		getline(cin, phone);
		//cin.ignore();
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Address: ";
		getline(cin, address);
		//cin.ignore();
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Tuition Centre Code: ";
		getline(cin, tccode);
		//cin.ignore();
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Tuition Centre Name: ";
		getline(cin, tcname);
		//cin.ignore();
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter Subject Code: ";
		getline(cin, subjectcode);
		//cin.ignore();
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "Enter rating : ";
		getline(cin, rating);
		if (rating == "1" || rating == "2" || rating == "3"|| rating == "4" || rating == "5") {
			Rating[length] = rating;
		}
		else {
			errormsg();
		}
		//cin.ignore();
		cout << "\n";
		cout << "\t\t\t\t";



		//store input in arrays
		Name[length] = name;
		id[length] = iid;
		RegDate[length] = regdate;
		TerminateDate[length] = terminatedate;
		HourlyRate[length] = hourlyrate;
		Phone[length] = phone ;
		Address[length] = address;
		TCCode[length] = tccode;
		TCName[length] = tcname;
		SubjectCode[length] = subjectcode;
		length++;
		checktermination();

		cout << "Record Succesfully Added!";
		cout << ("\t\t\t\t");
		cout << ("\n");
		int process = 0;
		cout << ("\t\t\t\t Returning to menu");
		for (process = 0; process < 25; process++)
		{
			delay(150);
			cout << (".");
		}
		menu();
	}
	void display() {
		system("cls");
		title();
		if (length == 0) {
			cout << "No data found! \n";
			int process = 0;
			cout << ("\t\t\t\t Returning to menu");
			for (process = 0; process < 25; process++)
			{
				delay(150);
				cout << (".");
			}
			menu();


		}
		else {
			for (int i = 0; i < length; i++) {
				cout << "Tutor ID: " << id[i] << ("\n");
				cout << ("\t\t\t");
				cout << "Name: " << Name[i] << ("\n");
				cout << ("\t\t\t");
				cout << "Registeration Date: " << RegDate[i] << ("\n");
				cout << ("\t\t\t");
				cout << "Termination Date: " << TerminateDate[i] << ("\n");
				cout << ("\t\t\t");
				cout << "Hourly Rate: " << HourlyRate[i] << ("\n");
				cout << ("\t\t\t");
				cout << "Phone Number: " << Phone[i] << ("\n");
				cout << ("\t\t\t");
				cout << "Address: " << Address[i] << ("\n");
				cout << ("\t\t\t");
				cout << "Tuition Centre Code: " << TCCode[i] << ("\n");
				cout << ("\t\t\t");
				cout << "Tuition Centre Name: " << TCName[i] << ("\n");
				cout << ("\t\t\t");
				cout << "Subject Code: " << SubjectCode[i] << ("\n");
				cout << ("\t\t\t");
				cout << "Rating: " << Rating[i] << ("\n");
				cout << ("\n");
				cout << ("\n");
				cout << ("\t\t\t");
			}
			string input;
			cout << "Do you want to return to Menu?(Y/N)";
			cin >> input;
			if (input == "Y" || input == "y")
			{
				menu();
			}
			else {
				display();

			}
		}

	}
	void modify() {
		string val;
		system("cls");
		title();
		int mid;
		string minput;
		string nphone;
		string naddress;
		cout << "Enter tutor ID: ";
		cin >> mid;
		cout << "\t\t\t\t";
		cout << "------------------------";

			for (int i = 0; i < length; i++) {
				if (id[i] == mid) {
					cout << "\n";
					cout << ("\t\t\t\t");
					cout << "Enter new phone number: ";
					cin >> nphone;
					cout << "\n";
					cout << ("\t\t\t\t");
					cout << "Enter New address: ";
					cin >> naddress;
					cout << "\n";
					cout << ("\t\t\t\t");
					Phone[i] = nphone;
					Address[i] = naddress;
					cout << "Update Successful!";
					cout << " \n \n";
					cout << ("\t\t\t\t");
					break;
				}
				if( i == length-1) {
					cout << "No User found!";
					break;
					
				}
			}

			cout << "Do you want to modify another record?(Y/N) ";
			cin >> minput;
			cout << "\n";
			cout << ("\t\t\t\t");
			if (minput == "Y" || minput == "y")
			{
				modify();
			}
			else if (minput == "N" || minput == "n") {
				menu();
			}
			else {
				cout << "Inavlid Input";
				menu();
			}
		


	}
	void searchid() {
		string val;
		string sinput;
		int sid;
		system("cls");
		title();
		cout << "Enter Tutor ID: ";
		cin >> sid;
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "--------------------------";
		if (sid == 0) {
			cout << "\n";
			cout << "\t\t\t\t";
			cout << "No User exists with inserted ID!";
			cout << "\n";
			cout << "\t\t\t\t";
			cout << "Would you like to try again?(Y/N)";
			cin >> val;
			if (val == "Y" || val == "y") {
				searchid();
			}
			else if (val == "N" || val == "n") {
				menu();
			}
			else {
				cout << "Invalid input";
				menu();
			}
		}
		else {
			for (int i = 0; i < length; i++) {
				if (id[i] == sid) {
					cout << "\n";
					cout << "\t\t\t\t";
					cout << "Name: " << Name[i] << ("\n");
					cout << "\t\t\t\t";
					cout << "Registeration Date: " << RegDate[i] << ("\n");
					cout << "\t\t\t\t";
					cout << "Termination Date: " << TerminateDate[i] << ("\n");
					cout << "\t\t\t\t";
					cout << "Hourly Rate: " << HourlyRate[i] << ("\n");
					cout << "\t\t\t\t";
					cout << "Phone Number: " << Phone[i] << ("\n");
					cout << "\t\t\t\t";
					cout << "Address: " << Address[i] << ("\n");
					cout << "\t\t\t\t";
					cout << "Tuition Centre Code: " << TCCode[i] << ("\n");
					cout << "\t\t\t\t";
					cout << "Tuition Centre Name: " << TCName[i] << ("\n");
					cout << "\t\t\t\t";
					cout << "Subject Code: " << SubjectCode[i] << ("\n");
					cout << "\t\t\t\t";
					cout << "Rating: " << Rating[i] << ("\n");
					cout << ("\n");
					cout << ("\n");
					cout << "\t\t\t\t";
					break;
					
				}
				if (i == length - 1 && id[i] != sid) {
					cout << ("\n");
					cout << "\t\t\t\t";
					cout << "No user found with inputed id";
					cout << ("\n");
					cout << "\t\t\t\t";
					break;
				}

			}
			cout << "Would you like to search for another tutor?(Y/N)";
			cin >> sinput;
			if (sinput == "Y" || sinput == "y") {
				searchid();
			}
			else if (sinput == "N" || sinput == "n") {
				menu();
			}
			else {
				cout << "Invalid Input!";
				menu();
			}
		}
		

	}
	void searchr() {
		
		string val;
		string sinput;
		string rnum;
		int tryy = 0;
		int i = 0;
		system("cls");
		title();
		cout << "Enter Rating Number: ";
		cin >> rnum;
		cout << "\n";
		cout << "\t\t\t\t";
		cout << "--------------------------";
		if (rnum == "1" || rnum == "2" || rnum == "3" || rnum == "4" || rnum == "5") {
			for ( i = 0; i < length; i++) {
				if (Rating[i] == rnum) {
					cout << "\n";
					cout << "\t\t\t\t";
					cout << "Tutor ID: " << id[i] << ("\n");
					cout << ("\t\t\t\t");
					cout << "Name: " << Name[i] << ("\n");
					cout << ("\t\t\t\t");
					cout << "Registeration Date: " << RegDate[i] << ("\n");
					cout << ("\t\t\t\t");
					cout << "Termination Date: " << TerminateDate[i] << ("\n");
					cout << ("\t\t\t\t");
					cout << "Hourly Rate: " << HourlyRate[i] << ("\n");
					cout << ("\t\t\t\t");
					cout << "Phone Number: " << Phone[i] << ("\n");
					cout << ("\t\t\t\t");
					cout << "Address: " << Address[i] << ("\n");
					cout << ("\t\t\t\t");
					cout << "Tuition Centre Code: " << TCCode[i] << ("\n");
					cout << ("\t\t\t\t");
					cout << "Tuition Centre Name: " << TCName[i] << ("\n");
					cout << ("\t\t\t\t");
					cout << "Subject Code: " << SubjectCode[i] << ("\n");
					cout << ("\t\t\t\t");
					cout << "\n\n";
					tryy++;
				}

			}
			if (tryy == 0) {
				cout << "\n \n";
				cout << "\t\t\t\t";
				cout << "No record found with inputed rate!";
				cout << ("\n");
				cout << ("\n");
				cout << "\t\t\t\t";
				cout << "Would you like to try again?(Y/N)";
				cin >> sinput;
				if (sinput == "Y" || sinput == "y") {
					searchr();
				}
				else if (sinput == "N" || sinput == "n") {
					menu();
				}
				else {
					cout << "Invalid Input!";
					menu();
				}

			}
			
			cout << "\n \n";
			cout << "\t\t\t\t";
			cout << "Would you like to search for another tutor?(Y/N)";
			cin >> sinput;
			if (sinput == "Y" || sinput == "y") {
				searchr();
			}
			else if (sinput == "N" || sinput == "n") {
				menu();
			}
			else {
				cout << "Invalid Input!";
				menu();
			}


			


		}
		else {
			cout << "\n \n";
			cout << "\t\t\t\t";
			cout << "Invalid Input";
			cout << ("\n");
			cout << ("\n");
			cout << "\t\t\t\t";
			cout << "Would you like to search for another tutor?(Y/N)";
			cin >> sinput;
			if (sinput == "Y" || sinput == "y") {
				searchr();
			}
			else if (sinput == "N" || sinput == "n") {
				menu();
			}
			else {
				cout << "Invalid Input!";
				menu();
			}


		}






	}
	void deleter() {
		system("cls");
		title();
		string sinput;
		int sid; 
		cout << "Enter Id: ";
		cin >> sid;
		if (length == 0) {
			cout << "\n \n";
			cout << "\t\t\t\t";
			cout << "No record exists";
			cout << ("\n");
			cout << ("\n");
			cout << "\t\t\t\t";
			cout << "Would you like to try again?(Y/N)";
			cin >> sinput;
			if (sinput == "Y" || sinput == "y") {
				deleter();
			}
			else if (sinput == "N" || sinput == "n") {
				menu();
			}
			else {
				cout << "Invalid Input!";
				menu();
			}		
		}
		else if (length == 1) {
			id[0] = NULL;
			Name[0] = "";
			RegDate[0] = "";
			TerminateDate[0] = "";
			HourlyRate[0] = NULL;
			Phone[0] = "";
			Address[0] = "";
			TCCode[0] = "";
			TCName[0] = "";
			SubjectCode[0] = "";
			Rating[0] = "";
			length--;
			cout << "\n";
			cout << "\t\t\t\t";
			cout << "Would you like to delete another tutor?(Y/N)";
			cin >> sinput;
			if (sinput == "Y" || sinput == "y") {
				deleter();
			}
			else if (sinput == "N" || sinput == "n") {
				menu();
			}
			else {
				cout << "Invalid Input!";
				menu();
			}


		}
		else {
			for (int i = 0; i < length; i++) {
				if (id[i] == sid) {
					for (int x = i; x < length - 1; x++) {
						id[i] = id[i + 1];
						Name[i] = Name[i + 1];
						RegDate[i] = RegDate[i + 1];
						TerminateDate[i] = TerminateDate[i + 1];
						HourlyRate[i] = HourlyRate[i + 1];
						Phone[i] = Phone[i + 1];
						Address[i] = Address[i + 1];
						TCCode[i] = TCCode[i + 1];
						TCName[i] = TCName[i + 1];
						SubjectCode[i] = SubjectCode[i + 1];
						Rating[i] = Rating[i + 1];
						i++;
					}
					length--;
					break;
				}			
			}		
			cout << "\n";
			cout << "\t\t\t\t";
			cout << "Would you like to delete another tutor?(Y/N)";
			cin >> sinput;
			if (sinput == "Y" || sinput == "y") {
				deleter();
			}
			else if (sinput == "N" || sinput == "n") {
				menu();
			}
			else {
				cout << "Invalid Input!";
				menu();
			}
		}
	}
	bool isLeap(int year)
	{
		return (((year % 4 == 0) &&
			(year % 100 != 0)) ||
			(year % 400 == 0));
	}
	bool isValidDate(int d, int m, int y)
	{
		const int MAX_VALID_YR = 9999;
		const int MIN_VALID_YR = 1800;
		if (y > MAX_VALID_YR ||
			y < MIN_VALID_YR)
			errormsg();
		if (m < 1 || m > 12)
			errormsg();
		if (d < 1 || d > 31)
			errormsg();
		if (m == 2)
		{
			if (isLeap(y))
				return (d <= 29);
			else
				return (d <= 28);
		}

		if (m == 4 || m == 6 ||
			m == 9 || m == 11)
			return (d <= 30);

		return TRUE;
	}	
	void sortpay() {
		title();
		int i, j;
		int temp1, temp3;
		string temp2, temp4, temp5, temp6, temp7, temp8, temp9, temp10, temp11;
		for (i = 0; i < length; i++) {
			for (j = i + 1; j < length; j++)
			{
				if (HourlyRate[i] > HourlyRate[j])
				{
					temp1 = HourlyRate[i];
					HourlyRate[i] = HourlyRate[j];
					HourlyRate[j] = temp1;
					temp2 = Name[i];
					Name[i] = Name[j];
					Name[j] = temp2;
					temp3 = id[i];
					id[i] = id[j];
					id[j] = temp3;
					temp4 = RegDate[i];
					RegDate[i] = RegDate[j];
					RegDate[j] = temp4;
					temp5 = TerminateDate[i];
					TerminateDate[j] = TerminateDate[j];
					TerminateDate[j] = temp5;
					temp6 = Phone[i];
					Phone[j] = Phone[j];
					Phone[j] = temp6;
					temp7 = Address[i];
					Address[j] = Address[j];
					Address[j] = temp7;
					temp8 = TCCode[i];
					TCCode[i] = TCCode[j];
					TCCode[j] = temp8;
					temp9 = TCName[i];
					TCName[i] = TCName[j];
					TCName[j] = temp9;
					temp10 = SubjectCode[i];
					SubjectCode[i] = SubjectCode[j];
					SubjectCode[j] = temp10;
					temp11 = Rating[i];
					Rating[i] = Rating[j];
					Rating[j] = temp11;


				}
			}
		}
			for (i = 0; i < length; i++) {
				cout << "Hourly Rate: " << HourlyRate[i] << ("\n");
				cout << ("\t\t\t\t");
				cout << "ID: " <<id[i];
				cout << "\n";
				cout << "\t\t\t\t";
				cout << "Name: " << Name[i];
				cout << "\n";
				cout << "\t\t\t\t";
				cout << "Registeration Date: " << RegDate[i] << ("\n");
				cout << ("\t\t\t\t");
				cout << "Termination Date: " << TerminateDate[i] << ("\n");
				cout << ("\t\t\t\t");
				cout << "Phone Number: " << Phone[i] << ("\n");
				cout << ("\t\t\t\t");
				cout << "Address: " << Address[i] << ("\n");
				cout << ("\t\t\t\t");
				cout << "Tuition Centre Code: " << TCCode[i] << ("\n");
				cout << ("\t\t\t\t");
				cout << "Tuition Centre Name: " << TCName[i] << ("\n");
				cout << ("\t\t\t\t");
				cout << "Subject Code: " << SubjectCode[i] << ("\n");
				cout << ("\t\t\t\t");
				cout << "Rating: " << Rating[i] << ("\n");
				cout << ("\n");
				cout << ("\n");
				cout << ("\t\t\t\t");
			}
			string input;
			cout << "Do you want to return to Menu?(Y/N)";
			cin >> input;
			if (input == "Y" || input == "y")
			{
				menu();
			}
			else {
				sortpay();

			}
		
	}
	void sortrate() {
		title();
		int i, j;
		int temp1, temp3;
		string temp2, temp4, temp5, temp6, temp7, temp8, temp9, temp10, temp11;
		for (i = 0; i < length; i++) {
			for (j = i + 1; j < length; j++)
			{
				if (Rating[i] > Rating[j])
				{
					temp11 = Rating[i];
					Rating[i] = Rating[j];
					Rating[j] = temp11;
					temp1 = HourlyRate[i];
					HourlyRate[i] = HourlyRate[j];
					HourlyRate[j] = temp1;
					temp2 = Name[i];
					Name[i] = Name[j];
					Name[j] = temp2;
					temp3 = id[i];
					id[i] = id[j];
					id[j] = temp3;
					temp4 = RegDate[i];
					RegDate[i] = RegDate[j];
					RegDate[j] = temp4;
					temp5 = TerminateDate[i];
					TerminateDate[j] = TerminateDate[j];
					TerminateDate[j] = temp5;
					temp6 = Phone[i];
					Phone[j] = Phone[j];
					Phone[j] = temp6;
					temp7 = Address[i];
					Address[j] = Address[j];
					Address[j] = temp7;
					temp8 = TCCode[i];
					TCCode[i] = TCCode[j];
					TCCode[j] = temp8;
					temp9 = TCName[i];
					TCName[i] = TCName[j];
					TCName[j] = temp9;
					temp10 = SubjectCode[i];
					SubjectCode[i] = SubjectCode[j];
					SubjectCode[j] = temp10;



				}
			}
		}
		for (i = 0; i < length; i++) {
			cout << "Rating: " << Rating[i] << ("\n");
			cout << "\t\t\t\t";
			cout << "Hourly Rate: " << HourlyRate[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "ID: " << id[i];
			cout << "\n";
			cout << "\t\t\t\t";
			cout << "Name: " << Name[i];
			cout << "\n";
			cout << "\t\t\t\t";
			cout << "Registeration Date: " << RegDate[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Termination Date: " << TerminateDate[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Phone Number: " << Phone[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Address: " << Address[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Tuition Centre Code: " << TCCode[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Tuition Centre Name: " << TCName[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Subject Code: " << SubjectCode[i] << ("\n");
			cout << ("\n");
			cout << ("\n");
			cout << ("\t\t\t\t");
		}
		string input;
		cout << "Do you want to return to Menu?(Y/N)";
		cin >> input;
		if (input == "Y" || input == "y")
		{
			menu();
		}
		else {
			sortpay();

		}

	}
	void sortid() {
		title();
		int i, j;
		int temp1, temp3;
		string temp2, temp4, temp5, temp6, temp7, temp8, temp9, temp10, temp11;
		for (i = 0; i < length; i++) {
			for (j = i + 1; j < length; j++)
			{
				if (id[i] > id[j])
				{
					temp3 = id[i];
					id[i] = id[j];
					id[j] = temp3;
					temp1 = HourlyRate[i];
					HourlyRate[i] = HourlyRate[j];
					HourlyRate[j] = temp1;
					temp2 = Name[i];
					Name[i] = Name[j];
					Name[j] = temp2;
					temp4 = RegDate[i];
					RegDate[i] = RegDate[j];
					RegDate[j] = temp4;
					temp5 = TerminateDate[i];
					TerminateDate[j] = TerminateDate[j];
					TerminateDate[j] = temp5;
					temp6 = Phone[i];
					Phone[j] = Phone[j];
					Phone[j] = temp6;
					temp7 = Address[i];
					Address[j] = Address[j];
					Address[j] = temp7;
					temp8 = TCCode[i];
					TCCode[i] = TCCode[j];
					TCCode[j] = temp8;
					temp9 = TCName[i];
					TCName[i] = TCName[j];
					TCName[j] = temp9;
					temp10 = SubjectCode[i];
					SubjectCode[i] = SubjectCode[j];
					SubjectCode[j] = temp10;
					temp11 = Rating[i];
					Rating[i] = Rating[j];
					Rating[j] = temp11;



				}
			}
		}
		for (i = 0; i < length; i++) {
			cout << "ID: " << id[i];
			cout << "\n";
			cout << "\t\t\t\t";
			cout << "Hourly Rate: " << HourlyRate[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Name: " << Name[i];
			cout << "\n";
			cout << "\t\t\t\t";
			cout << "Registeration Date: " << RegDate[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Termination Date: " << TerminateDate[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Phone Number: " << Phone[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Address: " << Address[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Tuition Centre Code: " << TCCode[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Tuition Centre Name: " << TCName[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Subject Code: " << SubjectCode[i] << ("\n");
			cout << ("\t\t\t\t");
			cout << "Rating: " << Rating[i] << ("\n");
			cout << ("\n");
			cout << ("\n");
			cout << ("\t\t\t\t");
		}
		string input;
		cout << "Do you want to return to Menu?(Y/N)";
		cin >> input;
		if (input == "Y" || input == "y")
		{
			menu();
		}
		else {
			sortpay();

		}

	}
	void errorloginmsg() {
		int process = 0;
		cout << ("\n");
		cout << ("\t\t\t\t Invalid Username/Password!");
		cout << ("\n\n");
		cout << ("\t\t\t\t Please try again!");
		for (process = 0; process < 25; process++)
		{
			delay(150);
			cout << (".");
		}
		login();
	}
	void login() {
		string username;
		string password;
		system("cls");
		title();
		cout << "Enter username: ";
		cin >> username;
		cout << ("\n\n");
		cout << ("\t\t\t\t");
		cout << "Enter password: ";
		cin >> password;
		if (username == "admin" && password == "admin") {
			mainpage();
			menu();
		}
		else {
			system("cls");
			title();
			errorloginmsg();
		}
		
	}

};
information c;

int main() {
	c.id[0] = 1;
	c.Name[0] = "Sherif Magdy";
	c.RegDate[0] = "01/12/2017";
	c.TerminateDate[0] = "01/06/2020";
	c.HourlyRate[0] = 80;
	c.Phone[0] = "+6011545452";
	c.Address[0] = "Parkhill";
	c.TCCode[0] = "TCBukit";
	c.TCName[0] = "Bukit Jalil";
	c.SubjectCode[0] = "Python";
	c.Rating[0] = "5";
	c.id[1] = 2;
	c.Name[1] = "Richard James";
	c.RegDate[1] = "01/01/2018";
	c.TerminateDate[1] = "01/08/2020";
	c.HourlyRate[1] = 75;
	c.Phone[1] = "+6011987562";
	c.Address[1] = "Z-Residence";
	c.TCCode[1] = "TCPetaling";
	c.TCName[1] = "Sri Petaling";
	c.SubjectCode[1] = "C++";
	c.Rating[1] = "4";
	c.id[2] = 3;
	c.Name[2] = "Su yifan";
	c.RegDate[2] = "01/12/2016";
	c.TerminateDate[2] = "01/04/2020";
	c.HourlyRate[2] = 60;
	c.Phone[2] = "+6018777452";
	c.Address[2] = "Selangor";
	c.TCCode[2] = "TCSelangor";
	c.TCName[2] = "East Lake Residence";
	c.SubjectCode[2] = "Java";
	c.Rating[2] = "3";
	c.id[3] = 4;
	c.Name[3] = "Mohamed Salah";
	c.RegDate[3] = "01/10/2017";
	c.TerminateDate[3] = "01/12/2020";
	c.HourlyRate[3] = 60;
	c.Phone[3] = "+60111111111";
	c.Address[3] = "Demanssara";
	c.TCCode[3] = "TCDemansara";
	c.TCName[3] = "One south";
	c.SubjectCode[3] = "C#";
	c.Rating[3] = "1";
	c.login();
}
		/*
		if (sid < length) {
			cout << "\n";
			cout << "\t\t\t\t";
			cout << "Name: " << Name[sid] << ("\n");
			cout << "\t\t\t\t";
			cout << "Registeration Date: " << RegDate[sid] << ("\n");
			cout << "\t\t\t\t";
			cout << "Termination Date: " << TerminateDate[sid] << ("\n");
			cout << "\t\t\t\t";
			cout << "Hourly Rate: " << HourlyRate[sid] << ("\n");
			cout << "\t\t\t\t";
			cout << "Phone Number: " << Phone[sid] << ("\n");
			cout << "\t\t\t\t";
			cout << "Address: " << Address[sid] << ("\n");
			cout << "\t\t\t\t";
			cout << "Tuition Centre Code: " << TCCode[sid] << ("\n");
			cout << "\t\t\t\t";
			cout << "Tuition Centre Name: " << TCName[sid] << ("\n");
			cout << "\t\t\t\t";
			cout << "Subject Code: " << SubjectCode[sid] << ("\n");
			cout << "\t\t\t\t";
			cout << "Rating: " << Rating[sid] << ("\n");
			cout << ("\n");
			cout << ("\n");
			cout << "\t\t\t\t";
			cout << "Would you like to search for another tutor?(Y/N)";
			cin >> sinput;
			if (sinput == "Y" || sinput == "y") {
				searchid();
			}
			else if (sinput == "N" || sinput == "n") {
				menu();
			}
			else {
				cout << "Invalid Input!";
				menu();
			}
		}
		else {
			cout << "\n";
			cout << "\t\t\t\t";
			cout << "No User exists with inserted ID!";
			cout << "\n";
			cout << "\t\t\t\t";
			cout << "Would you like to try again?(Y/N)";
			cin >> val;
			if (val == "Y" || val == "y") {
				searchid();
			}
			else if (val == "N" || val == "n") {
				menu();
			}
			else {
				cout << "Invalid input";
				menu();
			}


		}
		*/











	