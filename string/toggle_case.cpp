#include <iostream>
#include <string>
using namespace std;

int main() {

    string s = "HeLLo WoRLd";

    for (int i = 0; i < s.length(); i++) {

        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }

    cout << "Toggle case: " << s << endl;

    return 0;
}