#include <bits/stdc++.h>
#include "Admin.cpp"
using namespace std;

//  Functions

int welcome();
int home();
int regusr(); int regadmin(); int regdoc(); int regpat();
int login();
int adminL();
int docL(); int patL();






int main()
{
    welcome();
    // Admin a;
    // a.show();
    // cout  << endl << a.gets("name") << endl;
    // a.set(); a.show();
    home();

    return 0;
}

int home()
{
    cout << "1)Register\n2)Login\n3) Forgotton Credentials\n";
    int choice{0}; cin >> choice;
    if( choice == 1) {}
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
    return 0;
}

int welcome()
{
    cout << "\n\n\n\t\t\tWelcome To Corona Center Management Center. \n"; 
    cin.get(); system("clear");
    return 0;
}

int regusr()
{
    //- Option of Selecting b/w admin, doctor & patient. Register as whoever they want.
    cout << "1) Admin \n2)Doctor \n3) Patient\n"; 
    int choice{0}; cin >> choice;
    if(choice == 1) {regadmin();}
    else if(choice == 2) {regdoc();}
    else if(choice == 3) {regpat();}
    else
    {
        throw runtime_error("Invalid Choice! Program Exiting. \n");
    }
}

int regadmin()
{
    Admin obj;
    obj.set();
}

int login()
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

int adminL()
{
    cout << "Under Progress. \n"; login();
    return 0;
}

int docL()
{
    cout << "Under Progress. \n"; login();
    return 0;
}

int patL()
{
    cout << "Under Progress. \n"; login();
    return 0;
}


