#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

int main(){

    vector<string> operations = {"5", "2", "C", "D", "+"};

    stack<int>st;

    for(string op:operations){

        if(op != "C" && op != "D" && op !="+"){
            st.push(stoi(op));
        }

        else if(op=="C"){
            st.pop();
        }

        else if(op=="D"){
            st.push(st.top()*2);
        }

        else if(op=="+"){

            int first=st.top();
            st.pop();

            int second=st.top();

            st.push(first);
            st.push(first+second);

        }
    }

    int sum=0;
    while(!st.empty()){
        sum+=st.top();
        st.pop();
    }

    cout<<"Total Scores:"<<sum<<endl;
    return 0;


}