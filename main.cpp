#include <iostream>
#include "fstream"

using namespace std;
// TODO: блок механизм: прятать папку, переименовать на 20D04FE0-3AEA-1069-A2D8-08002B30309D,
//  создать псевдопапку с програмой запроса пароля + разблокировка


string exclude_folder(string folder_dir) {
    size_t found = folder_dir.find_last_of("\\");

    return folder_dir.substr(0, ++found); // increment found for include "\"
}

int secure(string dir, string password) {
    auto n = dir.find("\\pass.txt");
    dir.erase(n, 9); // 9 is "pass.txt" length

    string dir_path_without_folder = exclude_folder(dir) + ".{20D04FE0-3AEA-1069-A2D8-08002B30309D}";
    cout << dir_path_without_folder;

    rename(dir.c_str(), dir_path_without_folder.c_str());

    return 0;
}

int main() {
// TODO: + чекни будет ли проблема с меню быстрого доступа
// TODO: рассмотри целесообразность использовать класс и его методы вместо функций.
// TODO: разберись с смейком, сделай нормальную структуру проекта, напиши редми и меняй висибилити
// TODO: реализовать возможность паролить несколько директорий в одном пути запоминая на что изменяется
//  та или иная папка(предположительно добавлять цифру перед точкой)
// TODO: сделать тхт файл невидимым, в перспективе сохранять все данные о паролях в БД.

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