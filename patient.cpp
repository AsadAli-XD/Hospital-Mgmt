#include <bits/stdc++.h>
using namespace std; 

class Patient
{
    private:
    int id, age; string name, gender, disease, phone;
    public:
    Patient() { id = age = 0; name = gender = disease = phone = "N/A"; }
    
    Patient(int i, int a, string n, string g, string d, string p) 
    { id = i; age = a; name = n; gender = g; disease = d; phone = p; }

    Patient(Patient & a) 
    { id = a.id; age = a.age; name = a.name; gender = a.gender; disease = a.disease; phone = a.phone; }

    int set()
    {
        cout << "Patient ID: "; cin >> id; 
        cout << "Patient Age: "; cin >> age; 
        cout << "Patient Name: "; cin.ignore(); getline(cin, name); 
        cout << "Gender: "; cin >> gender; 
        cout << "Disease: "; cin.ignore(); getline(cin, disease);
        cout << "Phone No. :"; cin >> phone; store(); return 0;
    }
    const void show()
    {
        cout << "Patient ID:      " << id <<endl; 
        cout << "Patient Age:     " << age << endl; 
        cout << "Patient Name:    " << name << endl; 
        cout << "Gender:          " << gender << endl; 
        cout << "Disease:         " << disease << endl;
        cout << "Phone No. :      " << phone << endl;
    }

    int getI(int p) { if (p == 1) { return id;} else return age; }
    string gets(string x) 
    {
        if (x == "name") { return name;}
        else if (x == "gender") { return gender;}
        else if (x == "disease") { return disease;}
        else return phone; 
    }
    int store()
    {
        fstream infile; infile.open("patients.txt", ios::out| ios::ate);
        if(!infile) {cerr << "Unable to the file \"patients.txt\". "; return 0;}
        else
        { 
            if(id == 0 || age == 0 || name == "N/A" ) { cout << "Data Not Initialized Correctly. \n"; return 0;}
            infile << id << ","<< age << ","<< name << ","<< gender << ","<< disease << ","<< phone << endl; return 1; }
    }
};