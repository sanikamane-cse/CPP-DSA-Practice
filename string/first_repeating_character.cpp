#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "abcdca";

    int freq[256] = {0};

    for (char ch : s) {
        freq[ch]++;
    }

   
    for (char ch : s) {
        if (freq[ch] > 1) {
            cout << "First repeating character = " << ch << endl;
            return 0;
        }
    }

    cout << "No repeating character";

    return 0;
}