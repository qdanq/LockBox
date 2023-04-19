#include <iostream>
#include "fstream"

using namespace std;

int main() {
// TODO: сделать текстовый файл невидимым, сделать проверку на присутсвие текстового файла, если нет - то придумать пароль
    string password, prompt_password, path;
    cout << "Path to directory to protect:\n";
    cin >> path;
    path += "\\pass.txt";

    cout << path;

    ofstream fout;
    fout.exceptions(ofstream::badbit | ofstream::failbit);
    try {
        fout.open(path);
    }
    catch (const exception &ex) {
        cout << ex.what();
        cout << "\nFile open error, check correctness of path.\n";
        main();
    }

    cout << "\nCreate a password: ";
    cin >> password;
    fout << password;
    fout.close();

    /*cout << "\nEnter password: ";
    cin >> prompt_password;
    if (prompt_password == password) {
        cout << "+";
     }*/
}