#include <bits/stdc++.h>
#include "Admin.cpp"
#include "doctor.cpp"
#include "patient.cpp"
using namespace std;

//  Functions

int welcome();
int home();
int frgt();
int regadmin(); int regdoc(); int regpat();
int regusr(); 
int login();
int adminL();
int docL(); int patL();
int adminPanel();
int doctorPanel();
int patientPanel();





int main()      // Main Execution.
{
    // welcome();
    // Admin a;
    // a.show();
    // cout  << endl << a.gets("name") << endl;
    // a.set(); a.show();
    // adminL();
    home();
    // patL();

    return 0;
}

int home()      // Main Menu.
{
    cout << "1)Register\n2)Login\n3) Forgotton Credentials\n";
    int choice{0}; cin >> choice;
    if( choice == 1) 
    {
        try
        {
            regusr();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    else if(choice == 2)
    {
        try
        {
            login();
        }
        catch(const std::exception& e)
        {
            cerr << e.what() << '\n';
        }
    }
    else if(choice == 3) {frgt();}
    else { cout << "invalid choice. "; home();}
    return 0;
}


int frgt()      // Incase Forgot Credentials. 
{
    cout << "If You Forgot Your Credentials, Please Contact Admin at assadalee248@gmail.com. Ph: 123 \n"; return 0;
}

int welcome()   // Welcome Screen
{
    cout << "\n\n\n\t\t\tWelcome To Corona Center Management Center. \n"; 
    cin.get(); system("clear");
    return 0;
}

int regusr()    // Register User.
{
    //- Option of Selecting b/w admin, doctor & patient. Register as whoever they want.
    cout << "1) Admin \n2)Doctor \n3) Patient\n"; 
    int choice{0}; cin >> choice;
    if(choice == 1) {regadmin();}
    else if(choice == 2) { regdoc(); }
    else if(choice == 3) { regpat();}
    else
    {
        throw runtime_error("Invalid Choice! Program Exiting. \n");
    }
    return 0;
}

int regadmin()      // Register As Admin.
{
    cout << "\n\n\t\tRegister As Admin\n\n" << endl;
    Admin obj;
    obj.set(); obj.show(); return 0;
}

int regdoc()    // Register As Doctor.
{
    // fstream infile("doctors.txt", ios::out | ios::in | ios::app);
    Doctor obj;
    obj.set(); obj.show();
    return 0;
}

int regpat()    // Register As Patient.
{
    Patient obj;
    obj.set(); obj.show(); cin.get();
    system("clear");
    return 0;
}

int login()     // Login Function.
{
    system("clear");
    cout << "\n\n\t\t\tSelect Your Role: \n";
    cout << "\n1)Admin\n2)Doctor\n3)patient\n4)Exit\n";
    int choice{0}; cin >> choice;
    switch (choice)
    {
        case 1:
            adminL();
            break;
        case 2:
            docL();
            break;
        case 3:
            patL();
            break;
        case 4:
            exit(0);
            break;
        default:
            {throw runtime_error("Input Violation. Program is exiting.\n");}
            break;
    }
    return 0;
}

int adminL()        // Login For Admin.
{
    // cout << "Under Progress. \n"; login();
    cout << "Enter Username: "; string u; cin >> u;
    cout << "Enter Password: "; string p; cin >> p;
    fstream outfile("Admin.txt", ios::in|ios::app);
    string line = " "; int index= 0, len = 0; string info[7];
    while(!outfile.eof())
    {
        outfile >> line;
        for(int i = 0; i < 7; i++)
        {
            len = line.find("*", index);
            info[i] = line.substr(index, len - index);
            index = len+1;
        }
        if(info[5] == u && info[6] == p) 
        {cout << "\nLogin Successful.";  adminPanel(); return 0;} 
    }
    cout << "\nLogin Failed. \n"; system("clear"); adminL();
    return 0;
}

int docL()      // Login For Doctor.
{
    cout << "Enter Username: "; string u; cin >> u;
    cout << "Enter Password: "; string p; cin >> p;
    fstream snow("doctors.txt", ios::in);
    if(!snow) { cerr << "\n\tCan't Open File \"doctors.txt\". \n"; home();}
    else
    {
        string line, info[8]; int index = 0, length = 0;
        while(!snow.eof())
        {
            snow >> line;
            for(int i = 0; i <8; i++)
            {
                length = line.find("*", index);
                info[i] = line.substr(index, length-index);
                index = length +1;
            }
            if(info[6] == u && info[7] == p) 
            { cout << "\n\tLogin Successful. \n"; doctorPanel(); return 1;}
        }
        cout << "\n\tLogin Failed. \n"; system("clear"); docL();
        return 0;
    }
    return 0;
}

int patL()      // Login For Patient.
{
        cout << "Enter Username: "; string u; cin >> u;
    cout << "Enter Password: "; string p; cin >> p;
    fstream snow("patients.txt", ios::in);
    if(!snow) { cerr << "ERROR: Can't Open Patients File. Please Try Again Later. \n"; home();}
    else
    {
        string line, info[8]; int index = 0, length = 0;
        while(!snow.eof())
        {
            snow >> line;
            for(int i = 0; i <8; i++)
            {
                length = line.find("*", index);
                info[i] = line.substr(index, length-index);
                index = length +1;
            }
            if(info[6] == u && info[7] == p) 
            { cout << "\n\tLogin Successful. \n"; patientPanel(); return 1;}
        }
        cout << "\n\tLogin Failed. \n"; system("clear"); patL();;
        return 0;
    }

}


int adminPanel()
{
    cout << "Welcome To Admin Panel.";
    return 0;
}

int doctorPanel()
{
    cout << "Welcome To Doctor Panel. "; 
    cin.get();
    return 0;
}

int patientPanel()
{
    cout << "\n\n\t\tWelcome TO Patient Panel; \n";
    cin.ignore(); cin.get();
    return 0;
}