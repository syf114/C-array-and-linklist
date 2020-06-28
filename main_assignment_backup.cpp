#include <string>
#include <iostream>
#include <ctime>;
#include <time.h>;
#include <Windows.h>;
#include <iomanip>;


using namespace std;
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
static int id = 1;
struct Node   //creation of linked lists nodes
{
    int TutorID, Phone, Rating;
    double Hourly_Pay_Rate;
    string TutorName, Address, Tuition_Center_Code, Tuition_Center_Name, Subject_Code, Subject_Name, Date_Joined, Date_Terminated;
    Node* nextadd;
} *head, * temp, * tail;  //tail is pointer to last element in list
//function definitions
Node* CreateNewNode(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, string address, 
    double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name);

void InsertNodeAtFront(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, string address, 
    double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name);

void InsertNodeAtEnd(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, string address, 
    double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name);

void Display(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, string address, 
    double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name);

void AddTutorToFront(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, string address, 
    double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name);

void AddTutorToEnd(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, string address, 
    double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name);

void SearchTutorID(int Searchval);
void SearchTutorRating(int Search_rating);
void UpdateList();
void DeleteTutor();
void Bubblesortbyrating();
void Bubblesortbyhourlypay();
void BubbleSortbyTutorID();




bool login(string username, string password)   // just a login in function feature
{
    username = "";
    password = "";
    bool loginsuccess = false;

    do {
        cout << "Username:";
        cin >> username;
        cout << "Password:";
        cin >> password;

        if (username == "admin" && password == "admin") {
            cout << " \t successful login \n";
            loginsuccess = true;
            break;

        }
        else
        {
            cout << "incorrect username and password, please retry\n";
        }
    } while (!loginsuccess);
    return true;
}

char Menu() //how the main menu looks likes
{
    char choice;
    cout << "\t\t\t\t == Main menu == \n";
    cout << "\t\t\t\t 1: Add Tutor \n";
    cout << "\t\t\t\t 2: Display records \n";
    cout << "\t\t\t\t 3: Search by TutorID \n";
    cout << "\t\t\t\t 4: Search by Performance \n";
    cout << "\t\t\t\t 5: Sort and display by TutorID \n";
    cout << "\t\t\t\t 6: Sort and display tutors by Hourly_Pay_Rate \n";
    cout << "\t\t\t\t 7: Sort and display tutors by overall performance \n";
    cout << "\t\t\t\t 8: Modify a Tutor record only phone and address\n";
    cout << "\t\t\t\t 9: Delete tutor record \n";
    cout << "\t\t\t\t 0: Enter 0 to exit \n";
    cout << endl << "\t\t\t\t Choose your task..: ";
    cin >> choice;
    return choice;
}

Node* CreateNewNode(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, 
    string address, double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name)
{
    Node* CreateNewNode = new Node; //dynamic structure created
    CreateNewNode->TutorID = tutID;
    CreateNewNode->TutorName = tutname;
    CreateNewNode->Rating = rating;
    CreateNewNode->Phone = phone;
    CreateNewNode->Date_Joined = day_join;
    CreateNewNode->Date_Terminated = day_terminate;
    CreateNewNode->Address = address;
    CreateNewNode->Hourly_Pay_Rate = hrly_pay_r;
    CreateNewNode->Tuition_Center_Code = tut_center_code;
    CreateNewNode->Tuition_Center_Name = tut_center_name;
    CreateNewNode->Subject_Code = sub_code;
    CreateNewNode->Subject_Name = sub_name;
    CreateNewNode->nextadd = NULL;
    return CreateNewNode;

}

void InsertNodeAtFront(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, string address, 
    double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name)
{
    Node* NewNode = CreateNewNode(tutID, tutname, rating, phone, day_join, day_terminate, address, hrly_pay_r, tut_center_code, tut_center_name, sub_code, sub_name);
    NewNode->nextadd = head;
    head = NewNode;

}

void InsertNodeAtEnd(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, string address, 
    double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name)
{
    Node* NewNode = CreateNewNode(tutID, tutname, rating, phone, day_join, day_terminate, address, hrly_pay_r, tut_center_code, tut_center_name, sub_code, sub_name);

    temp = head;
    while (temp->nextadd != NULL)
    {
        temp = temp->nextadd;
    }
    temp->nextadd = NewNode;
}

void Display(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, string address, 
    double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name)
{
    if (head == NULL)
    {
        cout << "This list is empty \n";
    }
    temp = head;
    cout << "Tutor table as below: \n" << string(190, '=') << "\n";
    cout << "|" << setw(7) << " TutorID | " << setw(15) << " TutorName | " << setw(5) << " Rating |" << setw(15) << " Phone |" << setw(5) << " Date_Joined |" << setw(5) << " Date_Terminated |" << setw(15) << " Address |" << setw(5) << "Hourly_Pay_Rate | " << setw(5) << "Tuition_center_code |" << setw(5) << " Tuition_Center_name |" << setw(5) << "Subject_code |" << setw(15) << "Subject_name |\n" << string(190, '=') << "\n";
    while (temp != NULL)
    {
        cout << "| " << setw(7) << temp->TutorID << "| " << setw(14) << temp->TutorName << "| " << setw(8) << temp->Rating << "| " << setw(13) << temp->Phone << "| " << setw(12) << temp->Date_Joined << "| " << setw(15) << temp->Date_Terminated << "| " << setw(13) << temp->Address << "| " << setw(16) << temp->Hourly_Pay_Rate << "| " << setw(20) << temp->Tuition_Center_Code << "| " << setw(20) << temp->Tuition_Center_Name << "| " << setw(12) << temp->Subject_Code << "| " << setw(15) << temp->Subject_Name << "| \n ";
        cout << string(190, '-') << endl;
        temp = temp->nextadd;
    }

    cout << endl;
}

void AddTutorToFront(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, string address, 
    double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name)
{
    //this function will be called in the main so that user can add a tutor...
    int No_of_tuts, day, month, year;
    string choice;
    bool addtofront = false;
    temp = head;
    cout << endl << "How many tutors do you want to add?";
    cin >> No_of_tuts;
    while (cin.fail()) //validation
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Wrong input! Please try again:";
        cin >> No_of_tuts;
    }
    while (temp != NULL)
    {
        cout << temp->TutorID << ",";
        temp = temp->nextadd;
    }
    cout << " ID's are already taken \n";
    for (int i = 1; i <= No_of_tuts; i++) {

        if (head == NULL)
        {
            cout << "List empty \n";
        }
       
        cout << endl << " Enter TutorID:";
        cin >> tutID;
        while (cin.fail()) //validation
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "Wrong input! Please try again:";
            cin >> tutID;
        }


        cin.get();
        cout << endl << " Enter TutorName: \n";
        getline(cin, tutname);

        
        do
        {
            cin.clear();
            cout << "Tutors ratings are between 1-5: ";
            cin >> rating;
        } while (cin.bad() || rating < 1 || rating > 5);

        cout << endl << "Enter the Tutors Phone Number: \n";
        cin >> phone;
        while (cin.fail()) //validation
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "Wrong input! Please try again:";
            cin >> phone;
        }

        cout << endl << " Enter the Date the Tutor joined ( Format: MM/DD/YYYY)\n";
        do
        {
            cin.clear();
            cout << "Day: ";
            cin >> day;
        } while (cin.bad() || day < 1 || day > 31);

        do
        {
            cin.clear();
            cout << "Month: ";
            cin >> month;
        } while (cin.bad() || month < 1 || month > 12);
        cout << endl << " Year: ";
        cin >> year;
        while (cin.fail()) //validation
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "Wrong input! Please try again:";
            cin >> year;
        }
        day_join = to_string(day) + "/" + to_string(month) + "/" + to_string(year);


        cout << endl << " Enter the Date the Tutor left ( Format: MM/DD/YYYY): \n";
        do
        {
            cin.clear();
            cout << "Day: ";
            cin >> day;
        } while (cin.bad() || day < 1 || day > 31);

        do
        {
            cin.clear();
            cout << "Month: ";
            cin >> month;
        } while (cin.bad() || month < 1 || month > 12);
        cout << endl << " Year: ";
        cin >> year;
        while (cin.fail()) //validation
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "Wrong input! Please try again:";
            cin >> year;
        }
        day_terminate = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

        cin.get();
        cout << endl << " Enter The Tutors Address (EG: Bukit jalil):\n ";
        getline(cin, address);

        
        do
        {
            cin.clear();
            cout << "Tutors hourly pay is between 40 to 80: ";
            cin >> hrly_pay_r;
        } while (cin.bad() || hrly_pay_r < 40 || hrly_pay_r > 80);

        cout << endl << "Enter The Tuition Center Code the tutor will be teaching at ( EG: C01, C02 ....)\n:";
        cin >> tut_center_code;
        cin.get();
        cout << endl << "Enter the Tuition Center's Name ( EG: Business center...):\n";
        getline(cin, tut_center_name);
        cout << endl << " Enter the subject Code of the Tutor ( EG: S01, S02.....): \n";
        cin >> sub_code;
        cin.get();
        cout << endl << "Enter the Subject the tutor will teach (EG: Computer science): \n";
        getline(cin, sub_name);
        InsertNodeAtFront(tutID, tutname, rating, phone, day_join, day_terminate, address, hrly_pay_r, tut_center_code, tut_center_name, sub_code, sub_name);



    }
}

void AddTutorToEnd(int tutID, string tutname, int  rating, int phone, string day_join, string day_terminate, string address, 
    double hrly_pay_r, string tut_center_code, string tut_center_name, string sub_code, string sub_name)
{
    int No_of_tuts, day, month, year;
    string choice;
    bool addtofront = false;
    cout << endl << "How many tutors do you want to add?";
    cin >> No_of_tuts;
    while (cin.fail()) //validation
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Wrong input! Please try again:";
        cin >> No_of_tuts;
    }
    while (temp != NULL)
    {
        cout << temp->TutorID << ",";
        temp = temp->nextadd;
    }
    cout << " ID's are already taken \n";
    for (int i = 1; i <= No_of_tuts; i++) {
        if (head == NULL)
        {
            cout << "List empty \n";
        }
        
        cout << endl << " Enter TutorID:";
        cin >> tutID;
        while (cin.fail()) //validation
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "Wrong input! Please try again:";
            cin >> tutID;
        }

        cin.get();
        cout << endl << " Enter TutorName: \n";
        cin >> tutname;

        
        do
        {
            cin.clear();
            cout << "Tutors ratings are between 1-5: ";
            cin >> rating;
        } while (cin.bad() || rating < 1 || rating > 5);

        cout << endl << "Enter the Tutors Phone Number: \n";
        cin >> phone;
        while (cin.fail()) //validation
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "Wrong input! Please try again:";
            cin >> phone;
        }

        cout << endl << " Enter the Date the Tutor joined ( Format: MM/DD/YYYY)\n";        
        do
        {
            cin.clear();
            cout << "Day: ";
            cin >> day;
        } while (cin.bad() || day < 1 || day > 31);

        do
        {
            cin.clear();
            cout << "Month: ";
            cin >> month;
        } while (cin.bad() || month < 1 || month > 12);

        cout << endl << " Year: ";
        cin >> year;
        while (cin.fail()) //validation
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "Wrong input! Please try again:";
            cin >> year;
        }
        day_join = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

        cout << endl << " Enter the Date the Tutor left ( Format: MM/DD/YYYY): \n";
        
        do
        {
            cin.clear();
            cout << "Day: ";
            cin >> day;
        } while (cin.bad() || day < 1 || day > 31);

        do
        {
            cin.clear();
            cout << "Month: ";
            cin >> month;
        } while (cin.bad() || month < 1 || month > 12);

        cout << endl << " Year: ";
        cin >> year;
        while (cin.fail()) //validation
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << "Wrong input! Please try again:";
            cin >> year;
        }
        day_terminate = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

        cin.get();
        cout << endl << " Enter The Tutors Address (EG: Bukit jalil):\n ";
        getline(cin, address);

        
        do
        {
            cin.clear();
            cout << "Tutors hourly pay is between 40 to 80: ";
            cin >> hrly_pay_r;
        } while (cin.bad() || hrly_pay_r < 40 || hrly_pay_r > 80);

        cout << endl << "Enter The Tuition Center Code the tutor will be teaching at ( EG: C01, C02 ....)\n:";
        cin >> tut_center_code;
        cin.get();
        cout << endl << "Enter the Tuition Center's Name ( EG: Business center...):\n";
        getline(cin, tut_center_name);
        cout << endl << " Enter the subject Code of the Tutor ( EG: S01, S02.....): \n";
        cin >> sub_code;
        cin.get();
        cout << endl << "Enter the Subject the tutor will teach (EG: Computer science): \n";
        getline(cin, sub_name);
        InsertNodeAtEnd(tutID, tutname, rating, phone, day_join, day_terminate, address, hrly_pay_r, tut_center_code, tut_center_name, sub_code, sub_name);
    }
}

void SearchTutorID(int searchval)
{ //linear searching algorithm
    Node* current = head;
    int counter = 0;
    cout << endl << "Enter the TutorID to search for:";
    cin >> searchval;
    while (cin.fail()) //validation
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Wrong input! Please try again:";
        cin >> searchval;
    }

    while (current != NULL)
    {
        if (current->TutorID == searchval)
        {
            cout << "Search value is as below: \n" << string(190, '=') << "\n";
            cout << "|" << setw(7) << " TutorID | " << setw(15) << " TutorName | " << setw(5) << " Rating |" << setw(15) << " Phone |" << setw(5) << " Date_Joined |" << setw(5) << " Date_Terminated |" << setw(15) << " Address |" << setw(5) << "Hourly_Pay_Rate | " << setw(5) << "Tuition_center_code |" << setw(5) << " Tuition_Center_name |" << setw(5) << "Subject_code |" << setw(15) << "Subject_name |\n" << string(190, '=') << "\n";

            cout << "| " << setw(7) << current->TutorID << "| " << setw(14) << current->TutorName << "| " << setw(8) << current->Rating << "| " << setw(13) << current->Phone << "| " << setw(12) << current->Date_Joined << "| " << setw(15) << current->Date_Terminated << "| " << setw(13) << current->Address << "| " << setw(16) << current->Hourly_Pay_Rate << "| " << setw(20) << current->Tuition_Center_Code << "| " << setw(20) << current->Tuition_Center_Name << "| " << setw(12) << current->Subject_Code << "| " << setw(15) << current->Subject_Name << "| \n ";
            cout << string(190, '-') << endl;
            current = current->nextadd;
            break;
        }
        else
        {
            cout << "Record was not found on the " << counter << "th loop\n";
            current = current->nextadd;
        }
        counter++;
    }
}

//linear searching algorithm
void SearchTutorRating(int Search_rating)
{//linear search
    Node* current = head;
    int counter = 0;
    cout << endl << "Enter the Rating to search for the tutor (Rating between 1-5 only): \n";
    cin >> Search_rating;
    cout << "Search value is as below: \n" << string(190, '=') << "\n";
    cout << "|" << setw(7) << " TutorID | " << setw(15) << " TutorName | " << setw(5) << " Rating |" << setw(15) << " Phone |" << setw(5) << " Date_Joined |" << setw(5) << " Date_Terminated |" << setw(15) << " Address |" << setw(5) << "Hourly_Pay_Rate | " << setw(5) << "Tuition_center_code |" << setw(5) << " Tuition_Center_name |" << setw(5) << "Subject_code |" << setw(15) << "Subject_name |\n" << string(190, '=') << "\n";

    while (cin.fail()) //validation
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Wrong input! Please try again:";
        cin >> Search_rating;
    }

    while (current != NULL)
    {
        if (current->Rating == Search_rating)
        {

            cout << "| " << setw(7) << current->TutorID << "| " << setw(14) << current->TutorName << "| " << setw(8) << current->Rating << "| " << setw(13) << current->Phone << "| " << setw(12) << current->Date_Joined << "| " << setw(15) << current->Date_Terminated << "| " << setw(13) << current->Address << "| " << setw(16) << current->Hourly_Pay_Rate << "| " << setw(20) << current->Tuition_Center_Code << "| " << setw(20) << current->Tuition_Center_Name << "| " << setw(12) << current->Subject_Code << "| " << setw(15) << current->Subject_Name << "| \n ";
            cout << string(190, '-') << endl;
            current = current->nextadd;


        }
        else
        {
            current = current->nextadd;
        }
        counter++;
    }
    cout << "No more records found \n";
    cout << "program looped " << counter << " times \n";
}

void UpdateList()
{
    int Update_phone = 0, Update_address = 0;
    char a_or_b = 0;
    int t_id;
    Node* current = NULL;
    Node* prev = NULL;
    current = head;
    cout << endl << "Enter the Tutor ID who represents the Tutor you want to modify:";
    cin >> t_id;
    while (cin.fail()) //validation
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Wrong input! Please try again:";
        cin >> t_id;
    }
    while (current != NULL)
    {
        if (current->TutorID != t_id)
        {
            prev = current;
            current = current->nextadd;

        }
        else
        {
            cout << "\n\t\t\t\t  The Current phone number for this tutor is:" << current->Phone;
            cout << " \n\t\t\t\t The current address for this tutor is:     " << current->Address;
            cout << "\n \n";
            cout << "\t\t\t\t ========================SUB MENU======================== \n";
            cout << "\t\t\t\t a: Update the phone number: \n";
            cout << "\t\t\t\t b: Update the address: \n";
            cout << endl << "\t\t\t\t choose a or b: \n";
            cin >> a_or_b;
            switch (a_or_b)
            {
            case 'a':
                cout << endl << "Enter the new Phone Number:";
                cin >> current->Phone;
                while (cin.fail()) //validation
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << endl << "Wrong input! Please try again:";
                    cin >> current->Phone;
                }

                cout << "Phone number updated \n";
                break;

            case 'b':
                cout << endl << "Enter the new address:";
                cin >> current->Address;
                //validation

                cout << "Address updated \n";
                break;

            default:
                cout << " \n Error inserting values";
                break;
            }
            current = current->nextadd;
        }


    }
}

void DeleteTutor()
{
    Node* current = head, * prev = NULL;
    int tutid = 0;
    cout << " \t\t\t\t ========================SUB MENU========================\n";
    cout << "\t\t\t\t Enter the TutorID of the tutor to be deleted?\n";
    cin >> tutid;
    while (cin.fail()) //validation
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Wrong input! Please try again:";
        cin >> tutid;
    }

x:
    if (current == NULL)
    {
        cout << "No record found \n";

    }
    else if (current->TutorID != tutid)
    {
        prev = current;
        current = current->nextadd;
        goto x;
    }
    else
    {
        if (current == head)
        {
            if (current->nextadd == NULL)
            {
                head = NULL;
                tail = NULL;
                delete current;
            }
            else
            {
                head = current->nextadd;
                delete current;
            }
        }
        else if (current->nextadd == NULL)
        {
            tail = prev;
            prev->nextadd = current->nextadd;
            delete current;
        }
        else
        {
            prev->nextadd = current->nextadd;
            delete current;
        }
        cout << "record deleted \n";
    }
}

void Bubblesortbyrating()
{
    Node* curr = head;

    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->nextadd;
    }
    for (int i = count; i > 1; i--)
    {
        Node* temp = nullptr, * swap1;
        swap1 = head;
        for (int j = 0; j < count - 1; j++)
        {
            if (swap1->Rating > swap1->nextadd->Rating)
            {
                Node* swap2 = swap1->nextadd;
                swap1->nextadd = swap2->nextadd;
                swap2->nextadd = swap1;
                if (swap1 == head)
                {
                    head = swap2;
                    swap1 = swap2;
                }
                else
                {
                    swap1 = swap2;
                    temp->nextadd = swap2;
                }
            }
            temp = swap1;
            swap1 = swap1->nextadd;
        }
    }


}

void Bubblesortbyhourlypay()
{
    Node* curr = head;

    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->nextadd;
    }
    for (int i = count; i > 1; i--)
    {
        Node* temp = nullptr, * swap1;
        swap1 = head;
        for (int j = 0; j < count - 1; j++)
        {
            if (swap1->Hourly_Pay_Rate > swap1->nextadd->Hourly_Pay_Rate)
            {
                Node* swap2 = swap1->nextadd;
                swap1->nextadd = swap2->nextadd;
                swap2->nextadd = swap1;
                if (swap1 == head)
                {
                    head = swap2;
                    swap1 = swap2;
                }
                else
                {
                    swap1 = swap2;
                    temp->nextadd = swap2;
                }
            }
            temp = swap1;
            swap1 = swap1->nextadd;
        }
    }
    

}

void BubbleSortbyTutorID()
{
    
    Node* curr = head;

    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->nextadd;
    }
    for (int i = count; i > 1; i--)
    {
        Node* temp = nullptr, * swap1;
        swap1 = head;
        for (int j = 0; j < count - 1; j++)
        {
            if (swap1->TutorID > swap1->nextadd->TutorID)
            {
                Node* swap2 = swap1->nextadd;
                swap1->nextadd = swap2->nextadd;
                swap2->nextadd = swap1;
                if (swap1 == head)
                {
                    head = swap2;
                    swap1 = swap2;
                }
                else
                {
                    swap1 = swap2;
                    temp->nextadd = swap2;
                }
            }
            temp = swap1;
            swap1 = swap1->nextadd;
        }
    }


}

int main()
{
    int id = 0, rating = 0, phone = 0, a = 0, b = 0;
    string name, joined, leave, adress, center_code, center_name, sub_code, sub_name;
    double hrly_pay = 0;
    string un, pw;
    int end_or_begining, searchID = 0, Search_rating = 0;
    char choice;
    int count = 0;
    head = NULL;
    cout << "Welcome to the tutor management system, Please log in to continue :) \n";
    login(un, pw);   //calling the login function 
    int process = 0;
    system("cls");
    cout << ("\n");
    cout << ("\t\t\t\t  ---------------------------- \n");
    cout << ("\t\t\t\t  | TUTOR MANAGEMENT SYSTEM |\n");
    cout << ("\t\t\t\t   ---------------------------- \n");
    cout << ("\n\n\n");
    cout << ("\t\t\t\t");
    cout << ("Prepared by   : Sherif magdy, Richard Morel, Su Yifan");
    cout << ("\n\n");
    cout << ("\t\t\t\t");
    cout << ("Data Structure Assignment  : Tutor Management System");
    cout << ("\n\n");
    cout << ("\t\t\t\t");
    cout << ("Guided by:     Ms. CHong Mien May");
    cout << ("\n\n");
    cout << ("\t\t\t\tLoading... \n");
    for (process = 0; process < 25; process++);
    {
        delay(150);
        cout << (".");
    }

    InsertNodeAtFront(5, "Richard Morel", 5, 1114201944, "3/26/2019", "8/14/2020", "Bukit Jalil", 50.00, "C01", "C++ center", "S01", "C++ for dummies");
    InsertNodeAtEnd(4, "anie Low", 5, 1115493849, "3/29/2015", "31/5/2010", "victoria", 50.00, "C04", "Business school", "S04", "Business studies");
    InsertNodeAtEnd(3, "Yifan su", 3, 1114201955, "05/21/2019", "3/26/2020", "Petaling Jaya", 44.00, "C01", "C++ center", "S02", "Advanced C++");
    InsertNodeAtEnd(2, "sherif madgy", 1, 1114539022, "01/14/2018", "3/26/2029", "Penang", 80.00, "C05", "Java School", "S10", "Java for dummies");
    InsertNodeAtEnd(1, "John Smith", 5, 2567891, "05/21/2017", "3/26/2029", "Langkawi", 78.00, "C04", "c++ center", "S05", "DSTR with VB.net");

    //calculating size of linked list



    do
    {  //start of main program with this loop to get main menu
        choice = Menu();  //calling the main menuu function

        switch (choice) {

        case '1':
            cout << "1: Front of list \n";
            cout << "2: End of list \n";
            cin >> end_or_begining;
            if (end_or_begining == 1) {
                AddTutorToFront(id, name, rating, phone, joined, leave, adress, hrly_pay, center_code, center_name, sub_code, sub_name);
            }
            else
            {
                AddTutorToEnd(id, name, rating, phone, joined, leave, adress, hrly_pay, center_code, center_name, sub_code, sub_name);
            }
            break;


        case '2':
            Display(id, name, rating, phone, joined, leave, adress, hrly_pay, center_code, center_name, sub_code, sub_name);
            break;
        case '3':

            SearchTutorID(searchID);
            break;
        case '4':
            SearchTutorRating(Search_rating);
            break;
        case '5':
            BubbleSortbyTutorID();
            Display(id, name, rating, phone, joined, leave, adress, hrly_pay, center_code, center_name, sub_code, sub_name);

            break;
        case '6':
            Bubblesortbyhourlypay();
            Display(id, name, rating, phone, joined, leave, adress, hrly_pay, center_code, center_name, sub_code, sub_name);

            break;
        case '7':
            Bubblesortbyrating();
            Display(id, name, rating, phone, joined, leave, adress, hrly_pay, center_code, center_name, sub_code, sub_name);

            break;
        case '8':
            UpdateList();
            break;
        case '9':
            DeleteTutor();
            break;
        case '0':
            break;
        }
    } while (choice != '0');
    while (head != NULL)
    {
        count = count + 1;
        head = head->nextadd;
        return count;
    }
    return 0;
}