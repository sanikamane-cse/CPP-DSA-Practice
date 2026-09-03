#include <iostream>
#include <string>
using namespace std;

int main() {

    string s = "I love programming very much";

    string word = "";
    string longest = "";

    for (int i = 0; i < s.length(); i++) {

        if (s[i] != ' ') {
            word += s[i];
        }
        else {
            if (word.length() > longest.length()) {
                longest = word;
            }

            word = "";
        }
    }

    
    if (word.length() > longest.length()) {
        longest = word;
    }

    cout << "Longest word: " << longest << endl;

    return 0;
}