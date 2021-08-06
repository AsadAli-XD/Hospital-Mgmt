#include <bits/stdc++.h>
using namespace std; 

class Patient
{
    private:
    string info[8];
    public:
    Patient() { for(int i = 0; i < 8; i++) { info[i] = "N/A";}}
    
    Patient(string i, string n, string a, string g, string d, string p, string usr, string pas) 
    { info[0] = i;info[1] = n; info[2]= a; info[3] = g; info[4] = d; info[5] = p; info[6] = usr; info[7] = pas; }

    Patient(Patient & a) 
    {   for(int i = 0; i < 8; i++)  { info[i] = a.info[i];} }
    int set()
    {
        cout << "Patient ID: "; cin >> info[0]; 
        cout << "Patient Name: "; cin >> info[1];
        cout << "Patient Age: "; cin >> info[2]; 
        cout << "Enter Gender: "; cin >> info[3];
        cout << "Disease: "; cin >> info[4];
        cout << "Phone No. :"; cin >> info[5];
        cout << "Username: "; cin >> info[6];
        cout << "Password: "; cin >> info[7];
        store(); return 0;
    }
    const void show()
    {
        cout << "Patient ID:      " << info[0] <<endl; 
        cout << "Patient Age:     " << info[1] << endl; 
        cout << "Patient Name:    " << info[2] << endl; 
        cout << "Gender:          " << info[3] << endl; 
        cout << "Disease:         " << info[4] << endl;
        cout << "Phone No. :      " << info[5] << endl;
    }

    string get(string x) 
    {
        if(x == "id") { return info[0];}
        else if(x == "name") { return info[1];}
        else if(x == "age") { return info[2];}
        else if(x == "gender") { return info[3];}
        else if(x == "disease") { return info[4];}
        else if(x == "phone") { return info[5];}
        else if(x == "user") { return info[6];}
        else if(x == "pass") { return info[7];}
        else return "Invalid Parameter."; 
    }
    int store()
    {
        fstream infile; infile.open("patients.txt", ios::out| ios::ate);
        if(!infile) {cerr << "Unable to open the file \"patients.txt\". "; return 0;}
        else
        { 
            if(info[0] == "N/A" || info[2] == "N/A" || info[1]== "N/A" ) { cout << "Data Not Initialized Correctly. \n"; cin.get(); set(); return 0;}
            else
            {
                for(int i = 0; i < 8; i++)
                {
                    infile << info[i] << "*";
                }
                infile << endl;
                return 1;
            } 
        }
    }
};