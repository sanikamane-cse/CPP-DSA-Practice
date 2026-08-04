#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec;

    vec.push_back(25);
    vec.push_back(50);
    vec.push_back(70);

    cout<<"after push back size="<<vec.size()<<endl;

    vec.back();   //give output last value =70
    cout<<vec.back()<<endl;


return 0;
}