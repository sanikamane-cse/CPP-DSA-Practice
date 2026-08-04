#include<iostream>
#include<unordered_map>
using namespace std;

int main() {

    int arr[6] = {1,2,1,3,2,1};

    unordered_map<int,int> mp;

    for(int i=0; i<6; i++) {
        mp[arr[i]]++;
    }

    for(auto x : mp) {
        cout << x.first << " -> " << x.second << endl;
    }

    return 0;
}