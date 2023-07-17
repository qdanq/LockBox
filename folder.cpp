//
// Created by 38099 on 17.07.2023.
//
#include "main.h"

using namespace std;

class Folder {
public:
    string folderPath;
    string folderName;
    string folderPassword;
    bool exists;

    static void lockFolder(const string& path) {
        string newPath = path + ".{20D04FE0-3AEA-1069-A2D8-08002B30309D}";

        const char * charPath = path.c_str();
        const char * charNewPath = newPath.c_str();
        rename(charPath, charNewPath);

        DWORD attributes = FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM;
        SetFileAttributesA(charNewPath, attributes);
    }
};

