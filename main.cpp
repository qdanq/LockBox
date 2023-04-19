#include <iostream>
#include <cstdio>
#include "fstream"

using namespace std;

int main() {
// TODO: сделать текстовый файл невидимым, сделать проверку на присутсвие текстового файла, если нет - то придумать пароль
    string password, prompt_password;
    string path;
    cout << "Path to directory to protect:\n";
    cin >> path;
    path += "\\pass.txt";

    cout << "\nCreate a password: ";
    cin >> password;

    ofstream fout;
    fout.open(path);
    if (!fout.is_open()) {
        cout << "File open error, check correctness of path.\n";
        main();
    }
    fout << password;
    fout.close();

    /*cout << "\nEnter password: ";
    cin >> prompt_password;
    if (prompt_password == password) {
        cout << "+";
     }*/
}