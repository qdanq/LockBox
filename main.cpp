#include <iostream>
#include "fstream"

using namespace std;


int main() {
// TODO: сделать проверку на присутсвие текстового файла, если нет - то придумать пароль
// TODO: блок механизм
// TODO: сделать тхт файл невидимым, в перспективе сохранять все данные о паролях и папках в БД.
    string password, prompt_password, path;
    cout << "Path to folder to protect:\n";
    cin >> path;
    path += "\\pass.txt"; // For searching/creating file with password


    fstream password_file;
    password_file.exceptions(fstream::badbit | fstream::failbit);
    try {
    password_file.open(path, fstream::in | fstream::out | fstream::app);
    }

    catch (const exception &ex) {
        cout << ex.what();
        cout << "\nFile open error, check correctness of path.\n";
        main();
    }


    cout << "\nCreate a password: ";
    cin >> password;
    password_file << password;
    password_file.close();

    /*cout << "\nEnter password: ";
    cin >> prompt_password;
    if (prompt_password == password) {
        cout << "+";
     }*/
}