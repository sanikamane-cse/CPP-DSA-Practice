#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec;

    vec.push_back(25);
    vec.push_back(50);
    vec.push_back(75);

    cout<<"after push back size="<<vec.size()<<endl;

    vec.pop_back(); //delete 45 value in output

    for(int val:vec){
        cout<<val<<endl;
    }
return 0;
}