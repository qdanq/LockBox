#include <iostream>

using namespace std;

int main() {
    string password, prompt_password;
    cout << "Create a password" << endl;
    cin >> password;
    cout << "Enter password" << endl;
    cin >> prompt_password;
    if (prompt_password == password) {
        cout << "+";
    }
}