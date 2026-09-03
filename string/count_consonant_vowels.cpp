#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void count(string s, int &vowelCount, int &consonantCount) {

    for (int i = 0; i < s.length(); i++) {

        char ch = tolower(s[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' || 
            ch == 'o' || ch == 'u') {
            vowelCount++;
        }
        else if (ch >= 'a' && ch <= 'z') {
            consonantCount++;
        }
    }
}

int main() {

    string s = "I Love Coding";

    int vowelCount = 0;
    int consonantCount = 0;

    count(s, vowelCount, consonantCount);

    cout << "Vowel: " << vowelCount << endl;
    cout << "Consonant: " << consonantCount << endl;

    return 0;
}