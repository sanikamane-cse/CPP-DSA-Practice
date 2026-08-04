#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec;

    vec.push_back(25);
    vec.push_back(50);
    vec.push_back(70);

    cout<<"after push back size="<<vec.size()<<endl;

    cout<<vec.at(1)<<endl;  // at show index value 50 is 1 index value 

return 0;
}