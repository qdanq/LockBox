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


    ofstream fout;
    fout.open(path);
    if (!fout.is_open()) {
        printf("File open error, check correctness of path.\n");
        main();
    }


    /*cout << "\nCreate a password: ";
    cin >> password;
    cout << "\nEnter password: ";
    cin >> prompt_password;
    if (prompt_password == password) {
        cout << "+";
     } */
}