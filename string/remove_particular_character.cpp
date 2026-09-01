#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "hello world";

    char removeChar = 'l';

    string ans = "";

    for (int i=0;i<s.length();i++) {
        if (s[i] != removeChar) {
            ans += s[i];
        }
    }

    cout << "After removing character: " << ans << endl;

    return 0;
}