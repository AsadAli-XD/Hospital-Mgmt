#include <bits/stdc++.h>
using namespace std;

class Admin
{
    private:
    string info[7]; //id,name,age,email,phone,username,pass;
    public:
    Admin()
    {
        for(int i = 0; i <7; i++) { info[i] = "N/A";}   // Loop Initializes all 6 cells as "N/A" & 7th "\0";
    }
    Admin(string i, string a, string n, string mail, string ph, string usr, string ps)
    {
        info[0] = i; info[2] = a; info[1] = n; info[3] = mail; info[4] = ph; info[5] = usr; info[6] = ps;
        //Starting with 0th cell. Storing all the info given in Parameters.
    }

    Admin(Admin &a) //Copy Constructor.
    {
        for(int i = 0; i < 7; i++) { info[i]= a.info[1]; } // Loop copies all values of object given as Parameter.
    }

    int set()   
    {
        cout << "ID:"; cin >> info[0];
        cout << "Name: "; cin.ignore(); getline(cin, info[1]);
        cout << "Age: "; cin >> info[2];
        cout << "E-Mail: "; cin >> info[3];
        cout << "Phone No. : "; cin >> info[4];
        cout << "Username: "; cin >> info[5]; 
        cout << "Password: "; cin >> info[6];
        cout << "\n\nSuccess. " << endl;
        store();
        return 0;
    }
    // Make Getter Functions & Make A Function to store data in admins.txt file. Also make a check for data.
    string get(string n) 
    {
        if (n == "id") {return info[0];} 
        else if (n == "name") {return info[1];}
        else if (n == "age") {return info[2];}
        else if (n == "email") {return info[3];}
        else if (n == "phone") {return info[4];}
        else if (n == "user") {return info[5];}
        else if (n == "pass") {return info[6];}
        else { return "Invalid Parameter. ";}
    }
    int store()
    {
        if(info[1] == "N/A") { cout << "\tObject Not Initialized. It Can't be saved.\n";}
        else
        {
            fstream infile;
            infile.open("Admin.txt", ios::out|ios::app);
            if(!infile) { cout << "Unable to Open Admins File.\n"; return 0;}
            else{
                for(int i = 0; i < 7; i++)
                {
                    infile << info[i] << "*";
                }
                infile << endl; 
                return 1;
            }
        }
        return 0;
    }
    const void show()
    {
        cout << "ID: " << info[0] << endl;
        cout << "Name: " << info[1] << endl;
        cout << "Age: " << info[2] << endl;
        cout << "Email: " << info[3] << endl;
        cout << "Phone: " << info[4] << endl;
    }

int readA()
{
    fstream read;
    read.open("Admin.txt", ios::out|ios::in);
    if(!read) {cerr << "Can't Open Admin.txt file. ";}
    else {
        string line = " "; int index = 0; int len = 0;
        while(!read.eof())
        {
            read >> line; cout << line << endl;
            for(int i = 0; i < 7; i++)
            {
                len = line.find("*", index);
                info[i] = line.substr(index, len-index);
                index = len+1;
            }
            show(); cout << endl << endl;
            read.close();
        }
    }
    return 0;
}

    int mod()
    {
        show();
        cout << "1) Modify Your Data \n";
        cout << "2) Exit \n";
        int c; cin >> c; 
        if(c == 1) { cout << "Under Progress. \n";}
        else if( c == 2) { exit(0); }
        return 0;
    }
};