#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s = "englishalphabet";
    int count = 0;

    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            count++;
        }
    }

    cout << "Vowels: " << count;

    return 0;
}