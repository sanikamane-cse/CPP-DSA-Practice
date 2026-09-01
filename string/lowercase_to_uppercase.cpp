#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "hello world";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
    }

    cout << "Uppercase String: " << s << endl;

    return 0;
}