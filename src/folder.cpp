//
// Created by 38099 on 17.07.2023.
//
#include "main.h"
using namespace std;

class Folder {

public:
    int id;
    string path;
    string name;
    string password;

    static void lockFolder(const string &path) {
        string newPath = path + ".{20D04FE0-3AEA-1069-A2D8-08002B30309D}";

        const char *charPath = path.c_str();
        const char *charNewPath = newPath.c_str();
        rename(charPath, charNewPath);

        DWORD attributes = FILE_ATTRIBUTE_HIDDEN; // TODO: добавь потом " | FILE ATTRIBUTE_SYSTEM" а то ебёт постоянно смотреть системные файлы
        SetFileAttributesA(charNewPath, attributes);
    }

    static void unlockFolder() {

    }
};

