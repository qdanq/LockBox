#include <iostream>
#include "fstream"

using namespace std;

int main() {
    string password, prompt_password, path;
    cout << "Path to directory to protect: ";
    cin >> path;
    path += "\\pass.txt";

    cout << path;


    ofstream fout;
    fout.open(path);


    /*cout << "\nCreate a password: ";
    cin >> password;
    cout << "\nEnter password: ";
    cin >> prompt_password;
    if (prompt_password == password) {
        cout << "+";
     } */
}