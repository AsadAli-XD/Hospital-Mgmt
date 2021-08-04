#include <bits/stdc++.h>
using namespace std;

class Doctor
{
    private:
    string info[8];
    public:
    Doctor() {  for(int i = 0; i < 8; i++) { info[i] = "N/A"; } }
    Doctor(string i, string a, string n, string e, string ph, string spec, string usr, string pass) 
    {
        info[0] = i;        info[1] = n; 
        info[2] = a;        info[3] = e; 
        info[4] = ph;        info[5] = spec; 
        info[6] = usr;        info[7] = pass; 
    }
    Doctor(Doctor &a) 
    {
        for(int i = 0; i < 8; i++) {  info[i] = a.info[i];  }
    }
    int set()
    {
        int n = 0;
        cout << "ID: "; cin >> info[0]; 
        cout << "Name: "; cin >> info[1]; 
        cout << "Age: "; cin >> info[2];  
        cout << "Email: "; cin >> info[3]; 
        cout << "Phone: "; cin >> info[4]; 
        cout << "Speciality: "; cin >> info[5];
        cout << "Username: "; cin >> info[6];
        cout << "Password: "; cin >> info[7];
        cout << "\n\t Success !\n"; store();
        return 0;
    }
    string get(string n) {
        if(n == "id") {return info[0]; }
        else if(n == "name")  { return info[1]; }
        else if(n == "age")   { return info[2]; }
        else if(n == "email") { return info[3]; }
        else if(n == "phone") { return info[4]; }
        else if(n == "user")  { return info[5]; }
        else if(n == "pass")  { return info[6]; }
        else return "Invalid Parameters."; 
    }
    int store()
    {
        fstream infile;
        infile.open("doctors.txt", ios::out|ios::ate);
        if(!infile) {cout << "\t Can't open the file \"Doctors.txt\"."; cin.get(); return 0;}
        else
        {
            if(info[0] == "N/A" || info[2] == "N/A" || info[1] == "N/A") { cout << "Object Not Initialized properly.\n"; return 0;}
            else
            {
                for(int i = 0; i <8; i++)
                {
                    infile << info[i] << "*";
                }
                infile << endl;
                return 1;
            }
        }
        return 0;
    }
    int myPat()
    {
        cout << "\nIN Progress. \n"; cin.get();
        return 0;
    }
    const void show()
    {
        cout << "ID:          " << info[0] << endl;
        cout << "Name:        " << info[1] << endl;
        cout << "Age:         " << info[2] << endl;
        cout << "Email:       " << info[3] << endl;
        cout << "Phone:       " << info[4] << endl;
        cout << "Speciality:  " << info[5] << endl;
    }

    int readA()
    {
        fstream read("doctors.txt", ios::out| ios::in);
        if(!read) {cerr << "\n\t Can't open \"doctors.txt\" file. \n"; return 0;}
        else
        {
                int index = 0, l =0; string line;
            while (!read.eof())
            {
                read >> line; 
                for(int i = 0; i <8; i++)
                {
                    l = line.find("*", index);
                    info[i] = line.substr(index, l-index);
                    index = l+1;
                }
                show();
            }
            return 1;
        }
        return 0;
    }

};