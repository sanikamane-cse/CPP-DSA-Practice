#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "banana";

    char oldChar = 'a';
    char newChar = 'x';

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == oldChar) {
            s[i] = newChar;
        }
    }

    cout << "After replacing: " << s << endl;

    return 0;
}