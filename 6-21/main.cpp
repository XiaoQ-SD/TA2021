#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    fstream finout;
    finout.open("C:\\Users\\17318\\Documents\\GitHub\\TA2021\\6-21\\test1.txt");

    cout << "init pos \n";
    cout << "out pointer: " << finout.tellg() << endl;
    cout << "in  pointer: " << finout.tellp() << endl;

    string temp;
    while(getline(cin, temp) && temp[0] != '\0')
        finout << temp;

    cout << finout.tellg() << ' ' << finout.tellp() << '\n';

    finout.seekp(3, ios::beg);
    finout.seekg(2, ios::beg);
    cout << finout.tellg() << ' ' << finout.tellp() << '\n';
}