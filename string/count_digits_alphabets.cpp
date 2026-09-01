#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello123@#World45!";

    int digits = 0;
    int special = 0;

    for (char ch : s) {
        if (ch >= '0' && ch <= '9') {
            digits++;
        }
        else if (!((ch >= 'a' && ch <= 'z') ||
                   (ch >= 'A' && ch <= 'Z') ||
                   ch == ' ')) {
            special++;
        }
    }

    cout << "Digits = " << digits << endl;
    cout << "Special Characters = " << special << endl;

    return 0;
}