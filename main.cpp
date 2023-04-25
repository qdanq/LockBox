#include <iostream>
#include "fstream"

using namespace std;
// TODO: блок механизм: прятать папку, переименовать на 20D04FE0-3AEA-1069-A2D8-08002B30309D,
//  создать псевдопапку с програмой запроса пароля + разблокировка


string execute_folder_name(string dir) {
    auto n = dir.find("\\pass.txt");
    dir.erase(n, 9); // 9 is "\pass.txt" length

    size_t found = dir.find_last_of("\\");

    return dir.substr(found + 1); // + 1 to remove "\" char

}

int secure(string dir, string password) {
    dir = execute_folder_name(dir);

    return 0;
}

int main() {
// TODO: + чекни будет ли проблема с меню быстрого доступа
// TODO: рассмотри целесообразность использовать класс и его методы вместо функций.
// TODO: разберись с смейком, сделай нормальную структуру проекта, напиши редми и меняй висибилити
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
        secure(path, password);
    }


}