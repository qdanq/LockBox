#include <iostream>

using namespace std;

// TODO: ОСНОВНОЙ ПРИНЦИП РАБОТЫ. Вводим путь, проверяем существует ли он, не запаролен ли он,
//  если запаролен, то проверка на пароль. Если нет то используем блок механизм, накидываем атрибут,
//  сохраняем название папки, подключи БД.


// TODO: блок механизм: прятать папку, переименовать на "название папки"{.20D04FE0-3AEA-1069-A2D8-08002B30309D}


class Folder {
public:
    string folderPath;
    string folderName;
    string folderPassword;
    bool exists;
};


int main() {
    Folder tempFolder{"D:\\dsa", "dsa", "123", true};

    string path, folder, password;

    /* cout << "Input path to folder:" << endl;
     cin >> path;
     folder = path.substr(path.find_last_of('\\') + 1, -1);  '+ 1' for get rid of last '\' before folder name*/


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


    return 0;
}




/*
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

    string password, prompt_password, path;
    cout << "Path to folder to protect:\n";
    cin >> path;


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


}*/
