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
    password_file.open(path);
    if (password_file) {
        cout << "folder is protected, type password to continue\n";
        cin >> prompt_password;
        password_file >> password;
        if (prompt_password == password) {
            cout << "Access granted";
        } else {
            cout << "Access denied";
        }

    } else {
        password_file.open(path, fstream::app);
        cout << "\nCreate a password: ";
        cin >> password;
        password_file << password;
        password_file.close();
    }


}