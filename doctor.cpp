#include <bits/stdc++.h>
using namespace std;

class Doctor
{
    private:
    int id,age; string name,special,email, phone;
    public:
    Doctor() {id = age = 0; name = special = email = phone = "N/A"; }
    Doctor(int i, int a, string n, string s, string e, string p) 
    {        id = i; age = a; name = n; special = s; email =e; phone = p;}
    Doctor(Doctor &a) 
    {id = a.id; age = a.age; name = a.name; special = a.special; email = a.email; phone = a.phone; }
    int set()
    {
        cout << "ID: "; cin >> id; 
        cout << "Name: "; cin.ignore(); getline(cin, name);
        cout << "Age: "; cin >> age; 
        cout << "Speciality: "; cin.ignore(); getline(cin, special);
        cout << "Email: "; cin >> email;
        cout << "Phone: "; cin.ignore();getline(cin,phone);
    }
    int getI(int a)
    {
        if(a == 1) {return id;}
        if(a == 2) {return age;}
    }
    string getS(string n) {
        if(n == "name") { return name; }
        else if(n == "special") {return  special;}
        else if(n == "email") {return email;}
        else if(n == "phone") { return phone; }
        else return "Invalid Parameters."; 
    }
    int store()
    {
        fstream infile;
        infile.open("doctors.txt", ios::out|ios::ate);
        if(!infile) {cout << "\t Can't open the file \"Doctors.txt\"."; cin.get(); return 0;}
        else
        {
            if(id == 0 || age == 0 || name == "N/A") { cout << "Object Not Initialized properly.\n"; return 0;} 
            infile << id << "," << name << "," << age << ","<< special << "," << email << "," << phone << endl;
            return 1;
        }
        return 0;
    }
    const void show()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Speciality: " << special << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
    }

};