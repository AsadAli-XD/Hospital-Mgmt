#include <bits/stdc++.h>
using namespace std;

class Admin
{
    private:
    int id, age; string name, email, phone, username, pass;
    public:
    Admin()
    {
        id = age = 0; name = email = phone = username = pass = "N/A";
    }
    Admin(int i, int a, string n, string mail, string ph, string usr, string ps)
    {
        id = i; age = a; name = n; email = mail; phone = ph; username = usr; pass =ps;
    }
    Admin(Admin &a)
    {
        id = a.id; age = a.age; name = a.name; email = a.email; phone = a.phone; username = a.username; pass = a.pass; 
    }
    int set()
    {
        cout << "ID:"; cin >> id;
        cout << "Name: "; cin.ignore(); getline(cin, name);
        cout << "Age: "; cin >> age;
        cout << "E-Mail: "; cin >> email;
        cout << "Phone No. : "; cin >> phone;
        cout << "Username: "; cin >> username; 
        cout << "Password: "; cin >> pass;
        cout << "\n\nSuccess. " << endl;
        store();
        return 0;
    }
    // Make Getter Functions & Make A Function to store data in admins.txt file. Also make a check for data.
    int geti(int a) {if (a == 1) {return id;} else return age;}
    string gets(string n) 
    {
        if(n == "name") { return name;} else if(n == "email") { return email;}
        else if(n == "phone") { return phone;}
        else return "Invalid Parameters";
    }
    int store()
    {
        if(name == "N/A") { cout << "\tObject Not Initialized. It Can't be saved.\n";}
        else
        {
            fstream infile;
            infile.open("Admin.txt", ios::out|ios::ate);
            if(!infile) { cout << "Unable to Open Admins File.\n"; return 0;}
            else{
                infile << id << "," << name << "," << age << "," << email << "," << phone << ","<< username << "," << pass << endl;
                return 1;
            }
        }
        return 0;
    }
    const void show()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
    }
};