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


int frgt()
{
    cout << "If You Forgot Your Credentials, Please Contact Admin at assadalee248@gmail.com. Ph: 123 \n"; return 0;
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
    else if(choice == 2) { regdoc(); }
    else if(choice == 3) { regpat();}
    else
    {
        throw runtime_error("Invalid Choice! Program Exiting. \n");
    }
    return 0;
}

int regadmin()
{
    cout << "Program Entered Regadmin." << endl;
    Admin obj;
    obj.set(); obj.show(); return 0;
}

int regdoc()
{
    return 0;
}

int regpat()
{
    return 0;
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
    // cout << "Under Progress. \n"; login();
    Admin temp;
    cout << "Enter Username: "; string u; cin >> u;
    cout << "Enter Password: "; string p; cin >> p;
    fstream outfile("Admin.txt", ios::in|ios::app);
    string usr, ps, line = " "; int index= 0; int old =0; string sbstr;
    while(!outfile.eof())
    {
        outfile >> line;
        for(int i{0}; i < 7; i++)
        {
            usr = ps;
            index = line.find(",",index,line.size());
            sbstr = line.substr(old,index);
            old = index; sbstr = ps;
            cout << endl << usr << "   " << ps << endl;
        }
    }
    if(usr == u && ps == p) 
    {
        cout << "Success. !" << endl;
    }
    else 
    {
        cout << "Failed " << endl;
    }
    
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


