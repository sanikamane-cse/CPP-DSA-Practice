#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "hello";
    string s2 = "hello";

    if (s1 == s2) {
        cout << "Strings are equal" << endl;
    }
    else {
        cout << "Strings are not equal" << endl;
    }

    return 0;
}