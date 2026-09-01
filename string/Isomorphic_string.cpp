#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {

    string s = "egg";
    string t = "add";

    bool isIsomorphic = true;

    unordered_map<char, char> mp1;  // s → t
    unordered_map<char, char> mp2;  // t → s

    for (int i = 0; i < s.size(); i++) {

        char a = s[i];
        char b = t[i];

       
        if (mp1.find(a) != mp1.end()) {

            if (mp1[a] != b) {
                isIsomorphic = false;
                break;
            }

        }
        else {
            mp1[a] = b;
        }


        
        if (mp2.find(b) != mp2.end()) {

            if (mp2[b] != a) {
                isIsomorphic = false;
                break;
            }

        }
        else {
            mp2[b] = a;
        }
    }

    if (isIsomorphic)
        cout << "String is isomorphic" << endl;
    else
        cout << "String is not isomorphic" << endl;

    return 0;
}