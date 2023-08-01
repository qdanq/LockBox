#include "folder.cpp"

using namespace std;

// TODO: csv БД, со структурой: ид, имя, путькпапке, зашифрованый пароль. для шифра спец файл? в класе запись и сохранение,
//  в сейве сохраняем или обновляем, в записи делаем новую запись.

// TODO: блок механизм: прятать папку, переименовать на "название папки".{20D04FE0-3AEA-1069-A2D8-08002B30309D}

// TODO: исправь ошибку при пробеле в названии папки

int main() {
    Folder tempFolder{};

    string folderName, folderPassword, folderPath;

    cout << "Input folder path:" << endl;
    cin >> folderPath;
    folderName = folderPath.substr(folderPath.find_last_of('\\') + 1,
                                   -1); // '+ 1' to get rid of last '\' before folder name

    /*if (tempFolder.exists) {
        cout << "This folder secured, enter password to get access:" << endl;
        while (tempFolder.folderPassword != password) {
            cin >> password;
            if (tempFolder.folderPassword == password) {
                cout << "Access granted" << endl;
                Folder::unlockFolder();
            } else {
                cout << "Access denied" << endl;
            }

        }
    }*/

    cout << "Folder is unsecured, type password to secure the folder.";
    cin >> folderPassword;

    int id;
    ifstream folderid;
    folderid.open("..\\lock_folders.csv");
    if (!folderid.is_open()) {              // TODO: try catch
        id = 1;
    } else {

    }
    folderid.close();

    Folder secureDir{1, folderName, folderPath, folderPassword}; // TODO: dynamic id
    cout << secureDir.path;

    ofstream foldersdb;
    foldersdb.open("..\\lock_folders.csv", ofstream::app);  // TODO: Set file attribute
    foldersdb << secureDir.id << "," << secureDir.path << "," << secureDir.name << "," << secureDir.password << "\n";


    if (!foldersdb.is_open()) {
        cout << "ERROR. Something went wrong";   // TODO: try catch
        return 0;
    }

    Folder::lockFolder(secureDir.path);
    cout << "Folder successfully locked. Remember your password:\n" << secureDir.password;

    return 0;
}