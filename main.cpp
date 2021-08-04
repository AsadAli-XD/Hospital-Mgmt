#include <bits/stdc++.h>
#include "Admin.cpp"
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





int main()      // Main Execution.
{
    // welcome();
    // Admin a;
    // a.show();
    // cout  << endl << a.gets("name") << endl;
    // a.set(); a.show();
    adminL();
    // home();

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
    cout << "Program Entered Regadmin." << endl;
    Admin obj;
    obj.set(); obj.show(); return 0;
}

int regdoc()    // Register As Doctor.
{
    cout << "In Progress. " << endl;
    return 0;
}

int regpat()    // Register As Patient.
{
    cout << "In Progress. " << endl;
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
    cout << "Under Progress. \n"; login();
    return 0;
}

int patL()      // Login For Patient.
{
    cout << "Under Progress. \n"; login();
    return 0;
}


int adminPanel()
{
    cout << "Welcome To Admin Panel.";
    return 0;
}
