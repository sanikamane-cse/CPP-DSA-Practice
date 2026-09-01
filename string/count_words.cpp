#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "I love learning C++";

    int words = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
            words++;
        }
    }

    cout << "Number of words = " << words << endl;

    return 0;
}