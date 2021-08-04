// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string a = "1231*Asad Ali*20*assadalee248@gmail.com*03138314482*roxel*27234";
//     int index = 0; int old = 0; string sub; int length;
//     length =  a.find("*",index); sub = a.substr(old, length); cout << sub << endl; index = length+1; old = index; 
//     length =  a.find("*",index); cout << length << endl; sub = a.substr(old, length-index); cout << sub << endl; index=length+1; old = index; 
//     length =  a.find("*",index); cout << length << endl; sub = a.substr(old, length-index); cout << sub << endl; index=length+1; old = index; 
//     length =  a.find("*",index); cout << length << endl; sub = a.substr(old, length-index); cout << sub << endl; index=length+1; old = index; 


//     return 0;
// }

//          Using loop to set pieces of information into desired cells by string.substr function;

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string line = "1231*Asad Ali*20*assadalee248@gmail.com*03138314482*roxel*27234*";
//     string info[7]; int index = 0, lg;
//     for(int i = 0; i < 7; i++)
//     {
//         lg = line.find("*", index); cout << "Length: " << lg << endl;
//         info[i] = line.substr(index,lg-index); cout << "Info[" << i << "]: " << info[i] << endl;
//         index = lg+1;
//     }
//     cout << "Username: " << info[5] << endl;
//     cout << "Password: " << info[6] << endl;
//     return 0;
// }

#include <bits/stdc++.h>
#include "Admin.cpp"

using namespace std;

int main()
{
    Admin a;
    a.readA();
}