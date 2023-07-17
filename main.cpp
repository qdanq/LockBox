#include <iostream>
#include <fstream>
#include "folder.cpp"

using namespace std;

// TODO: для начала реализуй блокировку, потом с базами данных и как взаимодействовать с уже заблокироваными папками
// и запоминать их, а потом уже разблокировка.
// TODO: ОСНОВНОЙ ПРИНЦИП РАБОТЫ. Вводим путь, проверяем существует ли он, не запаролен ли он,
//  если запаролен, то проверка на пароль. Если нет то используем блок механизм, накидываем атрибут,
//  сохраняем название папки, подключи БД.


// TODO: блок механизм: прятать папку, переименовать на "название папки".{20D04FE0-3AEA-1069-A2D8-08002B30309D}




int main() {
    Folder tempFolder{};

    string folder, password, path;

    cout << "Input folder path:" << endl;
    cin >> path;
    folder = path.substr(path.find_last_of('\\') + 1, -1); // '+ 1' for get rid of last '\' before folder name


    if (tempFolder.exists) {
        cout << "This folder secured, enter password to get access:" << endl;
        while (tempFolder.folderPassword != password) {
            cin >> password;
            if (tempFolder.folderPassword == password) {
                cout << "Access granted" << endl;
            } else {
                cout << "Access denied" << endl;
            }

        }
    }

    Folder::lockFolder(path);


    return 0;
}